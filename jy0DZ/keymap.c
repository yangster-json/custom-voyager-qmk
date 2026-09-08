#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};

#define DUAL_FUNC_0 LT(15, KC_W)
#define DUAL_FUNC_1 LT(3, KC_Y)
#define DUAL_FUNC_2 LT(11, KC_F6)
#define DUAL_FUNC_3 LT(2, KC_F14)
#define DUAL_FUNC_4 LT(11, KC_J)
#define DUAL_FUNC_5 LT(15, KC_F11)
#define DUAL_FUNC_6 LT(13, KC_C)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_voyager(
        TG(4), DUAL_FUNC_0, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, DUAL_FUNC_2, OSL(3), LT(2, KC_TAB), KC_Q, KC_W, KC_E,
        KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, ALL_T(KC_BSPC),
        MT(MOD_LCTL, KC_ESCAPE), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,
        KC_L, KC_SCLN, MT(MOD_RALT, KC_QUOTE), DUAL_FUNC_1, KC_Z, KC_X, KC_C,
        KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, DUAL_FUNC_3,
        MT(MOD_LALT, KC_BSPC), KC_LEFT_GUI, LT(2, KC_ENTER), LT(1, KC_SPACE)),
    [1] = LAYOUT_voyager(
        KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_EXLM,
        KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINUS,
        KC_UNDS, DUAL_FUNC_4, KC_TRANSPARENT, KC_1, KC_2, KC_3, KC_4, KC_5,
        KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_GRAVE, KC_BSLS, KC_LCBR, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_RCBR, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT),
    [2] = LAYOUT_voyager(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_MS_JIGGLER_TOGGLE, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP,
        KC_MS_RIGHT, KC_TRANSPARENT, QK_BOOT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,
        KC_AUDIO_VOL_UP, KC_AUDIO_MUTE, KC_TRANSPARENT, KC_MS_BTN1, KC_HOME,
        KC_PGDN, KC_PAGE_UP, KC_END, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_MEDIA_STOP,
        KC_MEDIA_PLAY_PAUSE, KC_MS_BTN2, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,
        KC_BRIGHTNESS_UP, DUAL_FUNC_5, DUAL_FUNC_6, KC_MS_BTN3, KC_TRANSPARENT,
        LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT),
    [3] = LAYOUT_voyager(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,
        KC_F10, KC_F11, KC_F12, KC_NO, KC_TRANSPARENT, RGB_SAD, RGB_SAI,
        RGB_VAD, RGB_VAI, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
    [4] = LAYOUT_voyager(
        KC_TRANSPARENT, KC_GRAVE, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_BSLS, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_LEFT_CTRL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,
        KC_SCLN, KC_QUOTE, KC_TRANSPARENT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N,
        KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RIGHT_SHIFT, KC_BSPC,
        KC_TRANSPARENT, KC_ENTER, KC_SPACE),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case DUAL_FUNC_0:
    return TAPPING_TERM - 25;
  case DUAL_FUNC_2:
    return TAPPING_TERM - 25;
  default:
    return TAPPING_TERM;
  }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  // Keep these dual-role keys release-based (Permissive Hold), rather
  // than activating their hold action when another key is pressed.
  case LT(1, KC_SPACE):
  case LT(2, KC_ENTER):
  case MT(MOD_RALT, KC_QUOTE):
  case ALL_T(KC_BSPC):
  case MT(MOD_LALT, KC_BSPC):
    return false;
  default:
    return true;
  }
}

extern rgb_config_t rgb_matrix_config;

// The Choc switch housings and keycaps alter the apparent LED balance.
// Tune these percentages after flashing if a channel still looks too
// weak/strong.
#define VOYAGER_LED_RED_GAIN_PERCENT 90
#define VOYAGER_LED_GREEN_GAIN_PERCENT 115
#define VOYAGER_LED_BLUE_GAIN_PERCENT 115

static uint8_t compensate_led_channel(uint8_t channel, uint8_t gain_percent) {
  const uint16_t corrected = ((uint16_t)channel * gain_percent + 50) / 100;
  return corrected > UINT8_MAX ? UINT8_MAX : corrected;
}

// Apply the Voyager's optical compensation to each RGB Matrix LED color.
static RGB compensate_voyager_led_color(RGB rgb) {
  return (RGB){
      .r = rgb.r >= 0xF0 ? rgb.r
                        : compensate_led_channel(rgb.r, VOYAGER_LED_RED_GAIN_PERCENT),
      .g = compensate_led_channel(rgb.g, VOYAGER_LED_GREEN_GAIN_PERCENT),
      .b = compensate_led_channel(rgb.b, VOYAGER_LED_BLUE_GAIN_PERCENT),
  };
}

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb(hsv);
  const float brightness = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  rgb = (RGB){brightness * rgb.r, brightness * rgb.g, brightness * rgb.b};
  return compensate_voyager_led_color(rgb);
}

void keyboard_post_init_user(void) { rgb_matrix_enable(); }

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = {{112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {112, 255, 250},
           {112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {0, 0, 255},
           {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
           {112, 255, 250}, {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
           {0, 0, 255},     {0, 0, 255},     {112, 255, 250}, {0, 0, 255},
           {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
           {112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {112, 255, 250},
           {112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {112, 255, 250},
           {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
           {0, 0, 255},     {0, 120, 251},   {0, 0, 255},     {0, 0, 255},
           {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
           {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
           {0, 0, 255},     {112, 255, 250}, {112, 255, 250}, {112, 255, 250}},

    [1] = {{112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {112, 255, 250},
           {112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {0, 0, 255},
           {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
           {112, 255, 250}, {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
           {0, 0, 255},     {0, 0, 255},     {112, 255, 250}, {112, 255, 250},
           {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
           {112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {112, 255, 250},
           {112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {112, 255, 250},
           {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
           {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
           {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {112, 255, 250},
           {0, 0, 255},     {0, 0, 255},     {112, 255, 250}, {112, 255, 250},
           {112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {112, 255, 250}},

    [2] = {{112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {112, 255, 250},
           {112, 255, 250}, {133, 155, 246}, {112, 255, 250}, {193, 92, 255},
           {193, 92, 255},  {193, 92, 255},  {112, 255, 250}, {133, 59, 230},
           {112, 255, 250}, {12, 132, 255},  {12, 132, 255},  {0, 255, 255},
           {68, 39, 186},   {133, 59, 230},  {112, 255, 250}, {40, 255, 255},
           {40, 255, 255},  {0, 0, 255},     {0, 0, 255},     {133, 59, 230},
           {112, 255, 250}, {112, 255, 250}, {133, 59, 230},  {133, 59, 230},
           {133, 59, 230},  {133, 59, 230},  {112, 255, 250}, {0, 218, 204},
           {193, 92, 255},  {193, 92, 255},  {193, 92, 255},  {193, 92, 255},
           {112, 255, 250}, {112, 255, 250}, {0, 0, 255},     {0, 0, 255},
           {0, 0, 255},     {133, 155, 246}, {112, 255, 250}, {112, 255, 250},
           {112, 255, 250}, {194, 206, 226}, {194, 206, 226}, {112, 255, 250},
           {112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {112, 255, 250}},

    [3] = {{112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {112, 255, 250},
           {112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {112, 255, 250},
           {112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {112, 255, 250},
           {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
           {0, 0, 255},     {0, 0, 255},     {112, 255, 250}, {112, 255, 250},
           {40, 255, 255},  {40, 255, 255},  {40, 255, 255},  {40, 255, 255},
           {112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {112, 255, 250},
           {112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {112, 255, 250},
           {112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {112, 255, 250},
           {112, 255, 250}, {112, 255, 250}, {0, 0, 255},     {0, 0, 255},
           {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
           {112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {112, 255, 250},
           {112, 255, 250}, {112, 255, 250}, {112, 255, 250}, {112, 255, 250}},

    [4] = {{0, 255, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255},
           {0, 0, 255},   {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255},
           {0, 0, 255},   {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255},
           {0, 0, 255},   {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255},
           {0, 0, 255},   {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255},
           {0, 0, 255},   {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255},
           {0, 0, 255},   {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255},
           {0, 0, 255},   {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255},
           {0, 0, 255},   {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255},
           {0, 0, 255},   {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255},
           {0, 0, 255},   {0, 0, 255}},

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
        .h = pgm_read_byte(&ledmap[layer][i][0]),
        .s = pgm_read_byte(&ledmap[layer][i][1]),
        .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
      rgb_matrix_set_color(i, 0, 0, 0);
    } else {
      // Every layer-mapped LED passes through the same optical correction.
      RGB rgb = hsv_to_rgb_with_value(hsv);
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
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    default:
      if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
        rgb_matrix_set_color_all(0, 0, 0);
      }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}

static bool shifted_backspace_as_delete = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_BSPC:
  case ALL_T(KC_BSPC):
  case MT(MOD_LALT, KC_BSPC):
    // Only intercept taps; let QMK handle Hyper/Alt holds normally.
    if (keycode != KC_BSPC && record->tap.count == 0) {
      return true;
    }
    if (record->event.pressed) {
      if (get_mods() & MOD_MASK_SHIFT) {
        // Send an unmodified Delete, then restore the held Shift state.
        const uint8_t mods = get_mods();
        shifted_backspace_as_delete = true;
        del_mods(MOD_MASK_SHIFT);
        send_keyboard_report();
        tap_code(KC_DELETE);
        set_mods(mods);
        send_keyboard_report();
        return false;
      }
    } else if (shifted_backspace_as_delete) {
      shifted_backspace_as_delete = false;
      return false;
    }
    break;

  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work
    // inconsistently across operating systems, this makes sure that modifiers
    // are always applied to the key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode)) ||
        IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;

  case DUAL_FUNC_0:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        register_code16(KC_GRAVE);
      } else {
        unregister_code16(KC_GRAVE);
      }
    } else {
      if (record->event.pressed) {
        register_code16(KC_TILD);
      } else {
        unregister_code16(KC_TILD);
      }
    }
    return false;
  case DUAL_FUNC_1:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        register_code16(KC_LPRN);
      } else {
        unregister_code16(KC_LPRN);
      }
    } else {
      if (record->event.pressed) {
        register_code16(KC_LEFT_SHIFT);
      } else {
        unregister_code16(KC_LEFT_SHIFT);
      }
    }
    return false;
  case DUAL_FUNC_2:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        register_code16(KC_BSLS);
      } else {
        unregister_code16(KC_BSLS);
      }
    } else {
      if (record->event.pressed) {
        register_code16(KC_PIPE);
      } else {
        unregister_code16(KC_PIPE);
      }
    }
    return false;
  case DUAL_FUNC_3:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        register_code16(KC_RPRN);
      } else {
        unregister_code16(KC_RPRN);
      }
    } else {
      if (record->event.pressed) {
        register_code16(KC_RIGHT_SHIFT);
      } else {
        unregister_code16(KC_RIGHT_SHIFT);
      }
    }
    return false;
  case DUAL_FUNC_4:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        register_code16(KC_EQUAL);
      } else {
        unregister_code16(KC_EQUAL);
      }
    } else {
      if (record->event.pressed) {
        register_code16(KC_PLUS);
      } else {
        unregister_code16(KC_PLUS);
      }
    }
    return false;
  case DUAL_FUNC_5:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        register_code16(LCTL(KC_C));
      } else {
        unregister_code16(LCTL(KC_C));
      }
    } else {
      if (record->event.pressed) {
        register_code16(LCTL(LSFT(KC_C)));
      } else {
        unregister_code16(LCTL(LSFT(KC_C)));
      }
    }
    return false;
  case DUAL_FUNC_6:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        register_code16(LCTL(KC_V));
      } else {
        unregister_code16(LCTL(KC_V));
      }
    } else {
      if (record->event.pressed) {
        register_code16(LCTL(LSFT(KC_V)));
      } else {
        unregister_code16(LCTL(LSFT(KC_V)));
      }
    }
    return false;
  case RGB_SLD:
    if (record->event.pressed) {
      rgblight_mode(1);
    }
    return false;
  }
  return true;
