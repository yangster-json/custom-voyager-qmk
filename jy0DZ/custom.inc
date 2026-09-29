#include "os_detection.h"

extern rgb_config_t rgb_matrix_config;
extern const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3];

// oryx forces this on; mod-taps with it can stick
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  return false;
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

// swap alt/gui on every mod-tap for non-linux
bool process_detected_host_os_user(os_variant_t os) {
  const bool swap = os != OS_LINUX;
  keymap_config.swap_lalt_lgui = swap;
  keymap_config.swap_ralt_rgui = swap;
  return true;
}

static bool is_home_row_mod(uint16_t keycode) {
  switch (keycode) {
    case MT(MOD_LCTL, KC_A):
    case MT(MOD_LALT, KC_S):
    case MT(MOD_LGUI, KC_D):
    case MT(MOD_RGUI, KC_K):
    case MT(MOD_RALT, KC_L):
    case MT(MOD_RCTL, KC_SCLN):
      return true;
    default:
      return false;
  }
}

static bool is_thumb_cluster_key(keyrecord_t *record) {
  const uint8_t row = record->event.key.row;
  const uint8_t col = record->event.key.col;
  return (row == 5 && (col == 0 || col == 1)) ||
         (row == 11 && (col == 5 || col == 6));
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                      uint16_t other_keycode, keyrecord_t *other_record) {
  if (is_thumb_cluster_key(tap_hold_record) ||
      (is_home_row_mod(tap_hold_keycode) &&
       (is_home_row_mod(other_keycode) || is_thumb_cluster_key(other_record)))) {
    return true;
  }
  return get_chordal_hold_default(tap_hold_record, other_record);
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
  switch (keycode) {
    case LT(1, KC_SPACE):
      return 0;
    default:
      return is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode) ? FLOW_TAP_TERM : 0;
  }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(1, KC_SPACE):
    case LT(2, KC_ENTER):
    case MT(MOD_LCTL, KC_A):
    case MT(MOD_LALT, KC_S):
    case MT(MOD_LGUI, KC_D):
    case MT(MOD_RGUI, KC_K):
    case MT(MOD_RALT, KC_L):
    case MT(MOD_RCTL, KC_SCLN):
      return true;
    default:
      return false;
  }
}

#define rgb_matrix_indicators_user oryx_rgb_matrix_indicators_user
