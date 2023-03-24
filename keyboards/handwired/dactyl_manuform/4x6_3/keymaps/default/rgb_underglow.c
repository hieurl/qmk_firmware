#include "rgb_underglow.h"

void handle_layer_changes(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case _QWERTY:
//      rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL+4);
//      rgblight_sethsv_noeeprom(HSV_PURPLE);
      qwerty_mode_on_status(CURRENT_STATUS);
      break;
    
    case _LOWER:
      rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+2);
      rgblight_sethsv_noeeprom(HSV_BLUE);
      break;
    
    case _RAISE:
      rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+2);
      rgblight_sethsv_noeeprom(HSV_GREEN);
      break;

    case _FUNCT:
      rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+2);
      rgblight_sethsv_noeeprom(HSV_PURPLE);
      break;
    
    case _CONFIG:
      rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD+2);
      rgblight_sethsv_noeeprom(HSV_RED);
      break;
  }
}

void qwerty_mode_on_status (uint16_t status) {
    switch (status) {
        case STATUS_AVAILABLE:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL+4);
            break;
        case STATUS_BUSY:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case STATUS_WARNING:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+2);
            rgblight_sethsv_noeeprom(HSV_PURPLE);
            break;
        case STATUS_FURRY:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+2);
            rgblight_sethsv_noeeprom(HSV_PURPLE);
            break;
    }
}
bool process_rgb_keycodes(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGBETOG:
      if (record->event.pressed) {
        rgblight_toggle_noeeprom();
      }
      return false;

    case RGBEMOD:
      if (record->event.pressed) {
        rgblight_step_noeeprom();
      }
      return false;
  }

  return true;
}

