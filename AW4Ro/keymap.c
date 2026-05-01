#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

#define DUAL_FUNC_0 LT(6, KC_5)
#define DUAL_FUNC_1 LT(4, KC_F19)
#define DUAL_FUNC_2 LT(2, KC_L)
#define DUAL_FUNC_3 LT(15, KC_4)
#define DUAL_FUNC_4 LT(1, KC_Q)
#define DUAL_FUNC_5 LT(9, KC_9)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,        
    MEH_T(KC_TAB),  KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    CW_TOGG,        KC_A,           MT(MOD_LALT, KC_S),MT(MOD_LCTL, KC_D),MT(MOD_LSFT, KC_F),MT(MOD_LGUI, KC_G),                                MT(MOD_RGUI, KC_H),MT(MOD_RSFT, KC_J),MT(MOD_RCTL, KC_K),MT(MOD_LALT, KC_L),KC_SCLN,        KC_QUOTE,       
    MO(3),          KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_LEFT_SHIFT,  
                                                    LT(1, KC_SPACE),MO(3),                                          MT(MOD_LCTL, KC_ENTER),MO(2)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,        
    KC_TRANSPARENT, KC_GRAVE,       KC_TILD,        KC_BSLS,        KC_UNDS,        KC_AMPR,                                        KC_ASTR,        KC_MINUS,       KC_SLASH,       KC_PIPE,        KC_SCLN,        KC_EQUAL,       
    KC_TRANSPARENT, KC_LABK,        MT(MOD_LALT, KC_LBRC),DUAL_FUNC_0,    DUAL_FUNC_1,    DUAL_FUNC_2,                                    DUAL_FUNC_3,    DUAL_FUNC_4,    DUAL_FUNC_5,    MT(MOD_LALT, KC_RBRC),KC_RABK,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_PERC,        KC_PLUS,        KC_AT,                                          KC_CIRC,        KC_EQUAL,       KC_HASH,        KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_SHIFT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    ST_MACRO_0,     KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_NO,          
    ST_MACRO_1,     KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          LCTL(KC_H),     LCTL(KC_J),     LCTL(KC_K),     LCTL(KC_L),     KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_SHIFT,  KC_LEFT_GUI,                                    KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          KC_NO,          
    ST_MACRO_2,     KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         KC_NO,          ST_MACRO_3,     
                                                    MO(4),          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_NO,          KC_NO,          NAVIGATOR_DEC_CPI,KC_NO,          NAVIGATOR_INC_CPI,KC_MS_BTN3,                                     KC_MS_BTN1,     KC_MS_BTN2,     KC_MS_BTN3,     KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_MS_DBL_CLICK,KC_NO,          DRAG_SCROLL,                                    DRAG_SCROLL,    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MS_ACCEL2,   
    KC_NO,          KC_NO,          NAVIGATOR_TURBO,NAVIGATOR_AIM,  KC_MS_BTN2,     KC_MS_BTN1,                                     KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MS_ACCEL1,   
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          TD(DANCE_0),    TD(DANCE_1),                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MS_ACCEL0,   
                                                    DRAG_SCROLL,    KC_TRANSPARENT,                                 KC_NO,          KC_NO
  ),
  [4] = LAYOUT_voyager(
    TO(0),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_AUDIO_VOL_UP,KC_BRIGHTNESS_UP,                                RGB_SPI,        RGB_HUI,        RGB_SAI,        RGB_VAI,        RGB_SLD,        RGB_TOG,        
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_AUDIO_VOL_DOWN,KC_BRIGHTNESS_DOWN,                                RGB_SPD,        RGB_HUD,        RGB_SAD,        RGB_VAD,        RGB_MODE_FORWARD,KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_AUDIO_MUTE,  KC_MS_JIGGLER_TOGGLE,                                KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


const uint16_t PROGMEM combo0[] = { KC_P, KC_BSLS, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_SLASH, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_COMMA, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_DQUO),
    COMBO(combo1, KC_QUES),
    COMBO(combo2, KC_EXLM),
};



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
    [1] = { {0,0,0}, {45,203,255}, {45,203,255}, {45,203,255}, {45,203,255}, {45,203,255}, {0,0,0}, {37,255,255}, {9,255,255}, {151,218,204}, {83,218,204}, {129,255,255}, {0,0,0}, {0,209,96}, {156,255,255}, {0,230,255}, {188,255,255}, {82,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {108,218,204}, {46,218,204}, {227,218,204}, {0,0,0}, {0,0,0}, {45,203,255}, {45,203,255}, {45,203,255}, {45,203,255}, {45,203,255}, {0,0,0}, {129,255,255}, {83,218,204}, {151,218,204}, {11,219,255}, {71,255,255}, {37,255,255}, {82,255,255}, {188,255,255}, {0,230,255}, {156,255,255}, {0,209,96}, {0,0,0}, {227,218,204}, {46,218,204}, {108,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {251,251,255}, {212,221,235}, {212,221,235}, {212,221,235}, {212,221,235}, {212,221,235}, {51,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {94,209,255}, {94,209,255}, {94,209,255}, {94,209,255}, {204,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {212,221,235}, {212,221,235}, {212,221,235}, {212,221,235}, {212,221,235}, {0,0,0}, {17,218,204}, {17,218,204}, {17,218,204}, {17,218,204}, {0,0,0}, {0,0,0}, {139,225,255}, {139,225,255}, {139,225,255}, {139,225,255}, {0,0,0}, {0,0,0}, {51,218,204}, {51,218,204}, {51,218,204}, {51,218,204}, {0,0,0}, {207,218,233}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {25,224,251}, {0,0,0}, {25,224,251}, {124,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {204,202,255}, {0,0,0}, {25,224,251}, {0,0,0}, {0,0,0}, {0,234,255}, {0,234,255}, {131,218,204}, {206,213,208}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,218,204}, {206,213,208}, {25,224,251}, {0,0,0}, {206,213,208}, {131,218,204}, {124,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {25,224,251}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {25,224,251}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {25,224,251}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {25,224,251}, {0,0,0}, {0,0,0} },

    [4] = { {0,225,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {189,225,255}, {204,237,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {189,225,255}, {204,237,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {189,225,255}, {44,202,251}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {204,237,255}, {189,225,255}, {167,225,255}, {155,225,255}, {136,225,255}, {121,225,255}, {204,237,255}, {189,225,255}, {167,225,255}, {155,225,255}, {136,225,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,      
    SINGLE_HOLD,         
    DOUBLE_TAP,          
    DOUBLE_HOLD,         
    DOUBLE_SINGLE_TAP,   
    MORE_TAPS            
};

static tap dance_state[2];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case DOUBLE_TAP: register_code16(LCTL(KC_MS_BTN2)); break;
        case DOUBLE_HOLD: register_code16(LSFT(KC_MS_BTN2)); break;
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case DOUBLE_TAP: unregister_code16(LCTL(KC_MS_BTN2)); break;
        case DOUBLE_HOLD: unregister_code16(LSFT(KC_MS_BTN2)); break;
    }
    dance_state[0].step = 0;
}
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case DOUBLE_TAP: register_code16(LCTL(KC_MS_BTN1)); break;
        case DOUBLE_HOLD: register_code16(LSFT(KC_MS_BTN1)); break;
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case DOUBLE_TAP: unregister_code16(LCTL(KC_MS_BTN1)); break;
        case DOUBLE_HOLD: unregister_code16(LSFT(KC_MS_BTN1)); break;
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
};

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
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_RALT(SS_TAP(X_DELETE))));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_GRAVE))));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_C))SS_DELAY(100)  SS_LCTL(SS_TAP(X_T))SS_DELAY(200)  SS_LCTL(SS_TAP(X_V))  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_S))));
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_LCBR);
        } else {
          unregister_code16(KC_LCBR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_CTRL);
        } else {
          unregister_code16(KC_LEFT_CTRL);
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
          register_code16(KC_DLR);
        } else {
          unregister_code16(KC_DLR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_GUI);
        } else {
          unregister_code16(KC_LEFT_GUI);
        }  
      }  
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_EXLM);
        } else {
          unregister_code16(KC_EXLM);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_GUI);
        } else {
          unregister_code16(KC_RIGHT_GUI);
        }  
      }  
      return false;
    case DUAL_FUNC_4:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_RPRN);
        } else {
          unregister_code16(KC_RPRN);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_SHIFT);
        } else {
          unregister_code16(KC_LEFT_SHIFT);
        }  
      }  
      return false;
    case DUAL_FUNC_5:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_RCBR);
        } else {
          unregister_code16(KC_RCBR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_CTRL);
        } else {
          unregister_code16(KC_RIGHT_CTRL);
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
}
