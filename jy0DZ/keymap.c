#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};

#include "custom.inc"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TG(1),          TG(2),                                          OSL(6),         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_LCTL, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LGUI, KC_D),KC_F,           KC_G,                                           KC_H,           KC_J,           MT(MOD_RGUI, KC_K),MT(MOD_RALT, KC_L),MT(MOD_RCTL, KC_SCLN),KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
                                                    MT(MOD_LSFT, KC_BSPC),LT(5, KC_DELETE),                                LT(3, KC_ENTER),LT(5, KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_LALT, KC_D),MT(MOD_LGUI, KC_F),KC_TRANSPARENT,                                 KC_TRANSPARENT, MT(MOD_LGUI, KC_J),MT(MOD_RALT, KC_K),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 LT(3, KC_ENTER),KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_LGUI, KC_D),MT(MOD_LALT, KC_F),KC_TRANSPARENT,                                 KC_TRANSPARENT, MT(MOD_RALT, KC_J),MT(MOD_RGUI, KC_K),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 LT(4, KC_ENTER),KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_MINUS,       KC_EQUAL,       KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_LCTL, KC_1),MT(MOD_LALT, KC_2),MT(MOD_LGUI, KC_3),KC_4,           KC_5,                                           KC_6,           KC_7,           MT(MOD_RGUI, KC_8),MT(MOD_RALT, KC_9),MT(MOD_RCTL, KC_0),KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_GRAVE,       KC_BSLS,        KC_TRANSPARENT,                                 KC_TAB,         KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_QUOTE,       KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_MINUS,       KC_EQUAL,       KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_LCTL, KC_1),MT(MOD_LGUI, KC_2),MT(MOD_LALT, KC_3),KC_4,           KC_5,                                           KC_6,           KC_7,           MT(MOD_RALT, KC_8),MT(MOD_RGUI, KC_9),MT(MOD_RCTL, KC_0),KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_GRAVE,       KC_BSLS,        KC_TRANSPARENT,                                 KC_TAB,         KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_QUOTE,       KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    QK_BOOT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,                                KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_JIGGLER_TOGGLE,KC_MS_BTN3,     KC_MS_BTN2,     KC_MS_BTN1,     KC_MEDIA_PLAY_PAUSE,                                KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_BRIGHTNESS_UP,KC_TRANSPARENT, 
    KC_TRANSPARENT, LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   LCTL(LSFT(KC_C)),LCTL(LSFT(KC_V)),KC_MEDIA_STOP,                                  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_BRIGHTNESS_DOWN,KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_TRANSPARENT, 
    KC_NO,          KC_F1,          RGB_SAD,        RGB_SAI,        RGB_VAD,        RGB_VAI,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F12,         KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


const uint16_t PROGMEM combo0[] = { KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_J, MT(MOD_RGUI, KC_K), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_LPRN),
    COMBO(combo1, KC_LBRC),
    COMBO(combo2, KC_LCBR),
    COMBO(combo3, KC_RPRN),
    COMBO(combo4, KC_RBRC),
    COMBO(combo5, KC_RCBR),
    COMBO(combo6, KC_LBRC),
    COMBO(combo7, KC_RBRC),
    COMBO(combo8, KC_ESCAPE),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LCTL, KC_A):
            return TAPPING_TERM + 50;
        case MT(MOD_LALT, KC_S):
            return TAPPING_TERM + 50;
        case MT(MOD_LGUI, KC_D):
            return TAPPING_TERM + 50;
        case KC_F:
            return TAPPING_TERM + 50;
        case KC_J:
            return TAPPING_TERM + 50;
        case MT(MOD_RGUI, KC_K):
            return TAPPING_TERM + 50;
        case MT(MOD_RALT, KC_L):
            return TAPPING_TERM + 50;
        case MT(MOD_RCTL, KC_SCLN):
            return TAPPING_TERM + 50;
        case MT(MOD_LALT, KC_D):
            return TAPPING_TERM + 50;
        case MT(MOD_LGUI, KC_F):
            return TAPPING_TERM + 50;
        case MT(MOD_LGUI, KC_J):
            return TAPPING_TERM + 300;
        case MT(MOD_RALT, KC_K):
            return TAPPING_TERM + 50;
        case MT(MOD_LALT, KC_F):
            return TAPPING_TERM + 300;
        case MT(MOD_RALT, KC_J):
            return TAPPING_TERM + 300;
        case MT(MOD_LCTL, KC_1):
            return TAPPING_TERM + 50;
        case MT(MOD_LALT, KC_2):
            return TAPPING_TERM + 50;
        case MT(MOD_LGUI, KC_3):
            return TAPPING_TERM + 50;
        case KC_4:
            return TAPPING_TERM + 50;
        case KC_7:
            return TAPPING_TERM + 50;
        case MT(MOD_RGUI, KC_8):
            return TAPPING_TERM + 50;
        case MT(MOD_RALT, KC_9):
            return TAPPING_TERM + 50;
        case MT(MOD_RCTL, KC_0):
            return TAPPING_TERM + 50;
        case MT(MOD_LGUI, KC_2):
            return TAPPING_TERM + 50;
        case MT(MOD_LALT, KC_3):
            return TAPPING_TERM + 50;
        case MT(MOD_RALT, KC_8):
            return TAPPING_TERM + 50;
        case MT(MOD_RGUI, KC_9):
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}


extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {104,255,143}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {104,255,143}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {104,255,143}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {104,255,143}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {104,255,143}, {104,255,143}, {104,255,143} },

    [1] = { {173,218,204}, {173,218,204}, {173,218,204}, {173,218,204}, {173,218,204}, {173,218,204}, {173,218,204}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {173,218,204}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {173,218,204}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {173,218,204}, {173,218,204}, {173,218,204}, {173,218,204}, {173,218,204}, {173,218,204}, {173,218,204}, {173,218,204}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {173,218,204}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {173,218,204}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {173,218,204}, {173,218,204}, {173,218,204} },

    [2] = { {194,206,226}, {194,206,226}, {194,206,226}, {194,206,226}, {194,206,226}, {194,206,226}, {194,206,226}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {194,206,226}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {194,206,226}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {194,206,226}, {194,206,226}, {194,206,226}, {194,206,226}, {194,206,226}, {194,206,226}, {194,206,226}, {194,206,226}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {194,206,226}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {194,206,226}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {194,206,226}, {194,206,226}, {194,206,226} },

    [3] = { {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {104,255,143}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {104,255,143}, {104,255,143}, {104,255,143}, {0,0,255}, {0,0,255}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {104,255,143}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {104,255,143}, {0,0,255}, {0,0,255}, {104,255,143}, {104,255,143}, {0,0,255}, {104,255,143}, {104,255,143}, {104,255,143} },

    [4] = { {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {104,255,143}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {104,255,143}, {104,255,143}, {104,255,143}, {0,0,255}, {0,0,255}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {104,255,143}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {104,255,143}, {0,0,255}, {0,0,255}, {104,255,143}, {104,255,143}, {0,0,255}, {104,255,143}, {104,255,143}, {104,255,143} },

    [5] = { {0,218,204}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {193,92,255}, {193,92,255}, {193,92,255}, {12,132,255}, {12,132,255}, {104,255,143}, {130,148,230}, {130,148,230}, {130,148,230}, {130,148,230}, {68,39,186}, {104,255,143}, {194,206,226}, {194,206,226}, {0,0,255}, {0,0,255}, {0,255,255}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {193,92,255}, {193,92,255}, {193,92,255}, {193,92,255}, {104,255,143}, {104,255,143}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {40,255,255}, {104,255,143}, {130,148,230}, {130,148,230}, {130,148,230}, {130,148,230}, {40,255,255}, {104,255,143}, {104,255,143}, {104,255,143} },

    [6] = { {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {104,255,143}, {0,0,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {104,255,143}, {0,0,255}, {104,255,143}, {104,255,143}, {104,255,143} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
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
      case 5:
        set_layer_color(5);
        break;
      case 6:
        set_layer_color(6);
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




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode)) || IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
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

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
