#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
#  include "rgb_underglow.h"
#endif
#ifdef TAP_DANCE_ENABLE
#  include "tap_dances.h"
#endif

#define _BASE 0

uint16_t CURRENT_STATUS;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
      KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                          KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC, 
   //├────────┼───────┼───────┼───────┼───────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
      ESCLSFT,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                          KC_H,   KC_J,   KC_K,   KC_L,  KC_SCOLON,KC_BSLS,
   //├────────┼───────┼───────┼───────┼───────┼───────┼───────┐      ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤ 
      KC_LCTL,  KC_Z,    KC_X,  KC_C,   KC_V,   KC_B,                          KC_N,  KC_M, KC_COMM,KC_DOT, KC_SLSH,   DM_REC1, 
   //└────────┴───────┴───────┴───┬───┴───┬───┴───┬───┴───┬───┘      └───┬───┴───┬───┴───┬───┴───┬───┼───────┼───────┼───────┤
                         DM_REC1, DM_PLY1,TT_LOWR, KC_SPC,TD_LEAD,          TD_ALT, TD_ENT, TT_RAISE, DM_REC2, DM_PLY2 
    //                            └───────┴───────┴───────┘              └───────┴───────┴───────┘ 
    ),

    [_LOWER] = LAYOUT(
   //├───────┼───────┼───────┼───────┼───────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
      KC_GRV, TM_NVER,TM_NHOR,KC_QUOT, TM_HOME,TM_END,                        KC_1,   KC_2,   KC_3,   KC_MINS,KC_EQL,KC_BSPC, 
   //├───────┼───────┼───────┼───────┼───────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
      KC_TILD, KC_UP, KC_DOWN,KC_DQT,TM_UP,TM_DOWN,                         KC_4,   KC_5,    KC_6,  KC_0,   KC_PPLS,KC_PMNS,
   //├───────┼───────┼───────┼───────┼───────┼───────┼───────┐      ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
      ESCLCTL,KC_LEFT,KC_RIGHT,TM_SELECT,TM_LEFT,TM_RIGHT,                    KC_7,  KC_8,    KC_9,  KC_DOT, KC_ASTR ,DM_RSTP, 
   //└───────┴───────┴───────┴───┬───┴───┬───┴───┬───┴───┬───┘      └───┬───┴───┬───┴───┬───┴───┬───┼───────┼───────┼───────┤
                          WIN_LEFT, WIN_RIGHT, TT_LOWR,KC_SPC, KC_ESC,         KC_RALT, KC_ENT, KC_LGUI, KC_HOME, KC_END
    //                           └───────┴───────┴───────┘              └───────┴───────┴───────┘ 
    ),

    [_RAISE] = LAYOUT(
   //├────────┼───────┼───────┼───────┼───────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
       KC_TAB, VI_QUIT,VI_SAVE,KC_LCBR,KC_RCBR,KC_QUOT,                       KC_EXLM,KC_AT , KC_HASH,KC_UNDS,KC_DEL,KC_BSPC, 
   //├────────┼───────┼───────┼───────┼───────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
      ESCLSFT, KC_UP,  KC_DOWN, KC_LPRN,KC_RPRN, KC_DQT,                      KC_DLR, KC_PERC,KC_CIRC,KC_RPRN,KC_LEFT, KC_RIGHT, 
   //├────────┼───────┼───────┼───────┼───────┼───────┼───────┐      ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤ 
      KC_LCTL, KC_LEFT,KC_RIGHT,KC_LBRC,KC_RBRC,VI_PREV,                      KC_AMPR,KC_ASTR,KC_LPRN,KC_EQL, KC_QUES,DM_PLY1, 
   //└────────┴───────┴───────┴───┬───┴───┬───┴───┬───┴───┬───┘      └───┬───┴───┬───┴───┬───┴───┬───┼───────┼───────┼───────┤
                          DM_PLY1, DM_PLY2, TG_FUNCT, KC_SPC,KC_LEAD,        KC_RALT, KC_ENT, TT_RAISE, WIN_UP, WIN_DOWN
    ),

  [_FUNCT] = LAYOUT(
   //├────────┼───────┼───────┼───────┼───────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
      KC_TAB,  KC_Q,  KC_F10,  KC_F1, KC_F2,  KC_F3 ,                         KC_MUTE,KC_VOLD,KC_VOLU,MEDIA_MIC_MUTE,RGBEMOD, KC_BSPC,
   //├────────┼───────┼───────┼───────┼───────┼───────┤                      ├───────┼───────┼───────┼───────┼───────┼───────┤
      ESCLSFT, KC_A,  KC_F11, KC_F4,   KC_F5, KC_F6,                         KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,RGB_VAD, CHANGE_STATUS, 
   //├────────┼───────┼───────┼───────┼───────┼───────┼───────┐      ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤ 
      KC_LCTL, KC_Z,   KC_F12, KC_F7, KC_F8, KC_F9,                     EDIT_C,KC_WH_U,KC_WH_D,EDIT_V, EDIT_V,RESET, 
   //└────────┴───────┴───────┴───┬───┴───┬───┴───┬───┴───┬───┘      └───┬───┴───┬───┴───┬───┴───┬───┼───────┼───────┼───────┤
                        KC_UP, KC_DOWN, TG_FUNCT, KC_BTN1,KC_BTN2,      KC_RALT, KC_BTN1 , KC_BTN2, KC_LEFT, KC_RIGHT
    //                            └───────┴───────┴───────┘              └───────┴───────┴───────┘ 
  )
};

void keyboard_post_init_user(void) {
    CURRENT_STATUS = STATUS_AVAILABLE;
}

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

layer_state_t layer_state_set_user(layer_state_t state) {

  #ifdef RGBLIGHT_ENABLE
    handle_layer_changes(state);
  #endif

  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
//    case ON_QWERTY:
//      if (record->event.pressed) {
//        layer_off(_FUNCT);
//        layer_off(_LOWER);
//        layer_off(_RAISE);
//        layer_on(_QWERTY);
//      }
//      return false;
//    
//    case ON_LOWER:
//      if (record->event.pressed) {
//        layer_off(_FUNCT);
//        layer_off(_RAISE);
//        layer_off(_QWERTY);
//        layer_on(_LOWER);
//      }
//      return false;
//    
//    case ON_RAISE:
//      if (record->event.pressed) {
//        layer_off(_FUNCT);
//        layer_off(_LOWER);
//        layer_off(_QWERTY);
//        layer_on(_RAISE);
//      }
//      return false;
//
//    case ON_FUNCT:
//      if (record->event.pressed) {
//        layer_off(_RAISE);
//        layer_off(_LOWER);
//        layer_off(_QWERTY);
//        layer_on(_FUNCT);
//      }
//      return false;
    case WIN_LEFT:
      if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LGUI));
      }
      break;
    case WIN_RIGHT:
      if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI));
      }
      break;
    case WIN_UP:
      if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_UP) SS_UP(X_LGUI));
      }
      break;
    case WIN_DOWN:
      if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_DOWN) SS_UP(X_LGUI));
      }
      break;
      
    case VI_SAVE:
      if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_ESC)":w"SS_TAP(X_ENT));
      }
      break;
    case VI_QUIT:
      if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_ESC)":q"SS_TAP(X_ENT));
      }
      break;
    case VI_PREV:
      if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_ESC)":b#"SS_TAP(X_ENT));
      }
      break;
    case TM_NVER:
      if (record->event.pressed) {
          SEND_STRING("`|");
      }
      break;
    case TM_NHOR:
      if (record->event.pressed) {
          SEND_STRING("`-");
      }
      break;
    case TM_SELECT:
      if (record->event.pressed) {
          SEND_STRING("`[k");
      }
      break;
    case TM_LEFT:
      if (record->event.pressed) {
          SEND_STRING("`"SS_TAP(X_LEFT));
      }
      break;
    case TM_RIGHT:
      if (record->event.pressed) {
          SEND_STRING("`"SS_TAP(X_RIGHT));
      }
      break;
    case TM_UP:
      if (record->event.pressed) {
          SEND_STRING("`"SS_TAP(X_UP));
      }
      break;
    case TM_DOWN:
      if (record->event.pressed) {
          SEND_STRING("`"SS_TAP(X_DOWN));
      }
      break;
    case TM_HOME:
      if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_ESC)"^i");
      }
      break;
    case TM_END:
      if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_ESC)"$a");
      }
      break;

    case EDIT_C:
      if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_C) SS_UP(X_LCTRL));
      }
      break;
    case EDIT_V:
      if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_V) SS_UP(X_LCTRL));
      }
      break;
    case EDIT_Z:
      if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_Z) SS_UP(X_LCTRL));
      }
      break;

    case MEDIA_MIC_MUTE:
      if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LSFT) SS_DOWN(X_RALT) SS_TAP(X_M) SS_UP(X_LCTRL) SS_UP(X_LSFT) SS_UP(X_RALT));
      }
    case CHANGE_STATUS:
      if (record->event.pressed) {
          if (CURRENT_STATUS == STATUS_AVAILABLE) {
              CURRENT_STATUS = STATUS_BUSY;
          } else {
              CURRENT_STATUS = STATUS_AVAILABLE;
          }
      }
  }

  #ifdef RGBLIGHT_ENABLE
    if (!process_rgb_keycodes(keycode, record)) {
        return false;
    }
  #endif

  return true;
}


LEADER_EXTERNS();
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        //nerd tree
        SEQ_TWO_KEYS(KC_V, KC_N) {
            SEND_STRING(SS_TAP(X_ESC)":NERDTreeToggle"SS_TAP(X_ENT));
        }
        //vim replaced recently yanked
        SEQ_TWO_KEYS(KC_V, KC_R) {
            SEND_STRING("y"SS_TAP(X_ESC)":%s/"SS_DOWN(X_LCTRL) SS_TAP(X_R) SS_UP(X_LCTRL)"0/");
        }
        //vim search recently yanked global
        SEQ_TWO_KEYS(KC_V, KC_S) {
            SEND_STRING("y"SS_TAP(X_ESC)"/"SS_DOWN(X_LCTRL) SS_TAP(X_R) SS_UP(X_LCTRL)"0/");
        }
        //vim yank to system clipboard
        SEQ_TWO_KEYS(KC_V, KC_Y) {
            SEND_STRING("\"+y"SS_TAP(X_ENT));
        }

        //vim paste from system clipboard
        SEQ_TWO_KEYS(KC_V, KC_P) {
            SEND_STRING("\"+p"SS_TAP(X_ENT));
        }
        //vim terminal
        SEQ_TWO_KEYS(KC_V, KC_T) {
            SEND_STRING(SS_TAP(X_ESC)":terminal"SS_TAP(X_ENT));
            _delay_ms(100);
            SEND_STRING("i");
        }
        //vim terminal close
        SEQ_THREE_KEYS(KC_V, KC_T, KC_T) {
            SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_BSLS) SS_TAP(X_N) SS_UP(X_LCTRL));
            SEND_STRING(SS_TAP(X_ESC)":b#"SS_TAP(X_ENT));
        }


        //git
        SEQ_TWO_KEYS(KC_G, KC_S) {
            //SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
            SEND_STRING("git status .");
        }
        SEQ_TWO_KEYS(KC_G, KC_C) {
            //SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
            SEND_STRING("git commit");
        }
        SEQ_THREE_KEYS(KC_G, KC_D, KC_H) {
            //SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
            SEND_STRING("git diff HEAD .");
        }
        //window
        SEQ_TWO_KEYS(KC_W, KC_T) {
            SEND_STRING(SS_TAP(X_LGUI));
            _delay_ms(500);
            SEND_STRING("terminal"SS_TAP(X_ENT));
        }
        SEQ_TWO_KEYS(KC_W, KC_C) {
            SEND_STRING(SS_TAP(X_LGUI));
            _delay_ms(500);
            SEND_STRING("chrome"SS_TAP(X_ENT));
        }
        //workspace navigation
        SEQ_TWO_KEYS(KC_W, KC_A) {
            SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LSFT) SS_DOWN(X_LALT) "A" SS_UP(X_LALT) SS_UP(X_LCTRL) SS_UP(X_LSFT));
        }
        SEQ_TWO_KEYS(KC_W, KC_S) {
            SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LSFT) SS_DOWN(X_LALT) "S" SS_UP(X_LALT) SS_UP(X_LCTRL) SS_UP(X_LSFT));
        }

        SEQ_TWO_KEYS(KC_W, KC_Y) {
            SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LSFT)"!"SS_UP(X_LCTRL) SS_UP(X_LSFT));
        }
        SEQ_TWO_KEYS(KC_W, KC_U) {
            SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LSFT)"@"SS_UP(X_LCTRL) SS_UP(X_LSFT));
        }
        SEQ_TWO_KEYS(KC_W, KC_I) {
            SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_LSFT) "#" SS_UP(X_LCTRL) SS_UP(X_LSFT));
        }
    }
}

