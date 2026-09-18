#include "os_detection.h"

extern rgb_config_t rgb_matrix_config;
extern const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3];
bool oryx_process_record_user(uint16_t keycode, keyrecord_t *record);

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MT(MOD_LCTL, KC_A):
    case MT(MOD_LALT, KC_S):
    case MT(MOD_LGUI, KC_D):
    case MT(MOD_RGUI, KC_K):
    case MT(MOD_RALT, KC_L):
    case MT(MOD_RCTL, KC_SCLN):
    case MT(MOD_RALT, KC_QUOTE):
    case ALL_T(KC_BSPC):
    case MT(MOD_LALT, KC_BSPC):
      return false;
    default:
      return true;
  }
}

#define VOYAGER_LED_RED_GAIN_PERCENT 90
#define VOYAGER_LED_NEAR_WHITE_RED_GAIN_PERCENT 70
#define VOYAGER_LED_GREEN_GAIN_PERCENT 115
#define VOYAGER_LED_BLUE_GAIN_PERCENT 115

static uint8_t compensate_led_channel(uint8_t channel, uint8_t gain_percent) {
  const uint16_t corrected = ((uint16_t)channel * gain_percent + 50) / 100;
  return corrected > UINT8_MAX ? UINT8_MAX : corrected;
}

static RGB compensate_voyager_led_color(RGB rgb) {
  const bool near_white = rgb.r >= 0xF0 && rgb.g >= 0xF0 && rgb.b >= 0xF0;
  const uint8_t red_gain = near_white ? VOYAGER_LED_NEAR_WHITE_RED_GAIN_PERCENT
                                      : VOYAGER_LED_RED_GAIN_PERCENT;
  return (RGB){
      .r = rgb.r >= 0xF0 && !near_white ? rgb.r : compensate_led_channel(rgb.r, red_gain),
      .g = compensate_led_channel(rgb.g, VOYAGER_LED_GREEN_GAIN_PERCENT),
      .b = compensate_led_channel(rgb.b, VOYAGER_LED_BLUE_GAIN_PERCENT),
  };
}

static void set_custom_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    const HSV hsv = {
        .h = pgm_read_byte(&ledmap[layer][i][0]),
        .s = pgm_read_byte(&ledmap[layer][i][1]),
        .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
      rgb_matrix_set_color(i, 0, 0, 0);
    } else {
      RGB rgb = hsv_to_rgb(hsv);
      const float brightness = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
      rgb = (RGB){brightness * rgb.r, brightness * rgb.g, brightness * rgb.b};
      rgb = compensate_voyager_led_color(rgb);
      rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
    return false;
  }
  if (!keyboard_config.disable_layer_led) {
    switch (biton32(layer_state)) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
        set_custom_layer_color(biton32(layer_state));
        break;
      default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
    rgb_matrix_set_color_all(0, 0, 0);
  }
  return true;
}

static bool shifted_backspace_as_delete = false;
static uint16_t tab_wm_mod_keycode = KC_LEFT_GUI;

static bool is_windows_or_macos(void) {
  const os_variant_t host_os = detected_host_os();
  return host_os == OS_WINDOWS || host_os == OS_MACOS;
}

static bool process_os_aware_home_row_mod(keyrecord_t *record, uint16_t tap_keycode, uint8_t linux_mod, uint8_t windows_macos_mod) {
  if (record->tap.count > 0) {
    if (record->event.pressed) {
      register_code16(tap_keycode);
    } else {
      unregister_code16(tap_keycode);
    }
    return false;
  }

  const uint8_t hold_mod = is_windows_or_macos() ? windows_macos_mod : linux_mod;
  if (record->event.pressed) {
    add_mods(hold_mod);
  } else {
    del_mods(hold_mod);
  }
  send_keyboard_report();
  return false;
}

static bool process_os_aware_number_layer(keyrecord_t *record, uint16_t tap_keycode) {
  if (record->tap.count > 0) {
    if (record->event.pressed) {
      register_code16(tap_keycode);
    } else {
      unregister_code16(tap_keycode);
    }
    return false;
  }

  const uint8_t layer = is_windows_or_macos() ? 4 : 3;
  if (record->event.pressed) {
    layer_on(layer);
  } else {
    layer_off(layer);
  }
  return false;
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(3, KC_SPACE):
    case LT(5, KC_SPACE):
    case MT(MOD_LCTL, KC_A):
    case MT(MOD_LALT, KC_S):
    case MT(MOD_LGUI, KC_D):
    case MT(MOD_RGUI, KC_K):
    case MT(MOD_RALT, KC_L):
    case MT(MOD_RCTL, KC_SCLN):
    case MT(MOD_LALT, KC_D):
    case MT(MOD_LGUI, KC_F):
    case MT(MOD_LGUI, KC_J):
    case MT(MOD_RALT, KC_K):
    case MT(MOD_LALT, KC_F):
    case MT(MOD_RALT, KC_J):
      return true;
    default:
      return false;
  }
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
  if (keycode == LT(3, KC_SPACE) || keycode == LT(5, KC_SPACE)) {
    return 75;
  }
  return is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode) ? FLOW_TAP_TERM : 0;
}

static bool process_custom_record(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(3, KC_SPACE):
      return process_os_aware_number_layer(record, KC_SPACE);
    case LT(3, KC_ENTER):
      return process_os_aware_number_layer(record, KC_ENTER);
    case MT(MOD_LALT, KC_S):
      return process_os_aware_home_row_mod(record, KC_S, MOD_BIT_LALT, MOD_BIT_LGUI);
    case MT(MOD_LGUI, KC_D):
      return process_os_aware_home_row_mod(record, KC_D, MOD_BIT_LGUI, MOD_BIT_LALT);
    case MT(MOD_RGUI, KC_K):
      return process_os_aware_home_row_mod(record, KC_K, MOD_BIT_RGUI, MOD_BIT_RALT);
    case MT(MOD_RALT, KC_L):
      return process_os_aware_home_row_mod(record, KC_L, MOD_BIT_RALT, MOD_BIT_RGUI);
    case KC_BSPC:
    case ALL_T(KC_BSPC):
    case MT(MOD_LALT, KC_BSPC):
      if (keycode != KC_BSPC && record->tap.count == 0) {
        return true;
      }
      if (record->event.pressed && (get_mods() & MOD_MASK_SHIFT)) {
        const uint8_t mods = get_mods();
        shifted_backspace_as_delete = true;
        del_mods(MOD_MASK_SHIFT);
        send_keyboard_report();
        tap_code(KC_DELETE);
        set_mods(mods);
        send_keyboard_report();
        return false;
      }
      if (!record->event.pressed && shifted_backspace_as_delete) {
        shifted_backspace_as_delete = false;
        return false;
      }
      return true;
    case QK_MODS ... QK_MODS_MAX:
      if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode)) || IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
        if (record->event.pressed) {
          add_mods(QK_MODS_GET_MODS(keycode));
          send_keyboard_report();
          wait_ms(2);
          register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
          return false;
        }
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
      return true;
    case MT(MOD_LGUI, KC_TAB):
      if (record->tap.count > 0) {
        if (record->event.pressed) register_code16(KC_TAB); else unregister_code16(KC_TAB);
      } else if (record->event.pressed) {
        tab_wm_mod_keycode = detected_host_os() == OS_WINDOWS ? KC_LEFT_ALT : KC_LEFT_GUI;
        register_code16(tab_wm_mod_keycode);
      } else {
        unregister_code16(tab_wm_mod_keycode);
      }
      return false;
    default:
      return true;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_custom_record(keycode, record)) {
    return false;
  }
  return oryx_process_record_user(keycode, record);
}

#define process_record_user oryx_process_record_user
#define rgb_matrix_indicators_user oryx_rgb_matrix_indicators_user
