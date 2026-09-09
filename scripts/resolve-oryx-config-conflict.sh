#!/usr/bin/env bash
set -euo pipefail

file="${1:-jy0DZ/config.h}"
mapfile -t conflicts < <(git diff --name-only --diff-filter=U)

if [[ ${#conflicts[@]} -ne 1 || ${conflicts[0]} != "$file" ]]; then
  printf 'Expected only %s to conflict; found: %s\n' "$file" "${conflicts[*]:-none}" >&2
  exit 1
fi

tmp_file=$(mktemp)
trap 'rm -f "$tmp_file"' EXIT

awk '
function fail(message) {
  print "Cannot resolve Oryx config conflict: " message > "/dev/stderr"
  failed = 1
  exit 1
}

function is_serial(line) {
  return line ~ /^#define SERIAL_NUMBER "[^"]+"$/
}

/^<<<<<<< / {
  if (state != 0) {
    fail("nested conflict marker")
  }
  state = 1
  next
}

state == 1 && /^=======$/ {
  state = 2
  next
}

state == 2 && /^>>>>>>> / {
  if (ours_custom != 1 || ours_serial != 1 || theirs_default != 1 || theirs_serial != 1) {
    fail("unexpected conflict contents")
  }
  print "#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY"
  print incoming_serial
  state = 0
  conflict_count++
  next
}

state == 1 {
  if ($0 == "#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY") {
    ours_custom++
  } else if (is_serial($0)) {
    ours_serial++
  } else {
    fail("unexpected custom-side line: " $0)
  }
  next
}

state == 2 {
  if ($0 == "#define HOLD_ON_OTHER_KEY_PRESS") {
    theirs_default++
  } else if (is_serial($0)) {
    theirs_serial++
    incoming_serial = $0
  } else {
    fail("unexpected Oryx-side line: " $0)
  }
  next
}

{
  print
}

END {
  if (failed) {
    exit 1
  }
  if (state != 0 || conflict_count != 1) {
    print "Cannot resolve Oryx config conflict: expected one complete conflict block" > "/dev/stderr"
    exit 1
  }
}
' "$file" > "$tmp_file"

mv "$tmp_file" "$file"
git add -- "$file"
