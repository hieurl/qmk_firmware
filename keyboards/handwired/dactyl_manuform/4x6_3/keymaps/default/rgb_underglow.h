  
#pragma once

#include "keymap.h"

uint16_t CURRENT_STATUS;

void handle_layer_changes (layer_state_t state);
bool process_rgb_keycodes (uint16_t keycode, keyrecord_t *record);

void qwerty_mode_on_status (uint16_t status);

enum {
    STATUS_AVAILABLE = 0,
    STATUS_BUSY = 1,
    STATUS_WARNING = 2,
    STATUS_FURRY = 3
};
