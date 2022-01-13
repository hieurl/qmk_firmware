#pragma once

#include "keymap.h"

#define TABHYPR MT(MOD_RCTL | MOD_RSFT | MOD_RALT | MOD_RGUI, KC_TAB)
#define ESCLCTL MT(MOD_LCTL, KC_ESC)
#define ESCLSFT MT(MOD_LSFT, KC_ESC)
#define CTRLSLSH MT(MOD_RCTL, KC_SLSH)

typedef struct {
  bool is_press_action;
  int state;
} tap;

int cur_dance (qk_tap_dance_state_t *state);

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5,
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

void t_ctrl_finished (qk_tap_dance_state_t *state, void *user_data);
void t_ctrl_reset (qk_tap_dance_state_t *state, void *user_data);
void t_alt_finished (qk_tap_dance_state_t *state, void *user_data);
void t_alt_reset (qk_tap_dance_state_t *state, void *user_data);
void t_ent_finished (qk_tap_dance_state_t *state, void *user_data);
void t_ent_reset (qk_tap_dance_state_t *state, void *user_data);
void t_lead_finished (qk_tap_dance_state_t *state, void *user_data);
void t_lead_reset (qk_tap_dance_state_t *state, void *user_data);

enum {
  T_ESCTAB = 0,
  T_SHFCAP = 1,
  T_CTRL = 2,
  T_SEMCOL = 3,
  T_ALT = 4,
  T_ENT = 5,
  T_LEAD = 6
};
