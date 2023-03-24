#include "tap_dances.h"

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for CAPS, twice for ESC
  [T_SEMCOL] = ACTION_TAP_DANCE_DOUBLE(KC_SCOLON,KC_COLN),
  [T_SHFCAP] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT,KC_CAPS),
  [T_ALT]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, t_alt_finished, t_alt_reset),
  [T_ENT]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, t_ent_finished, t_ent_reset),
  [T_CTRL]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, t_ctrl_finished, t_ctrl_reset),
  [T_LEAD]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL, t_lead_finished, t_lead_reset)
};
// T_CTRL

static tap t_ctrl_tap_state = {
  .is_press_action = true,
  .state = 0
};
static tap t_alt_tap_state = {
  .is_press_action = true,
  .state = 0
};
static tap t_ent_tap_state = {
  .is_press_action = true,
  .state = 0
};
static tap t_lead_tap_state = {
  .is_press_action = true,
  .state = 0
};

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  
  else return 8;
}

void t_alt_finished (qk_tap_dance_state_t *state, void *user_data) {
  t_alt_tap_state.state = cur_dance(state);
  switch (t_alt_tap_state.state) {
      case SINGLE_TAP: register_code(KC_LALT); break;
    case SINGLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_TAP: 
      register_code(KC_LALT);
      tap_code16(KC_ENT);
      break;
    case DOUBLE_HOLD: break;
    case TRIPLE_TAP:
      break;
  }
}

void t_alt_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (t_alt_tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_LALT); break;
    case SINGLE_HOLD: unregister_code(KC_LALT); break;
    case DOUBLE_TAP:
      unregister_code(KC_LALT);
      break;
    case DOUBLE_HOLD: break;
  }
  t_ctrl_tap_state.state = 0;
}

void t_ctrl_finished (qk_tap_dance_state_t *state, void *user_data) {
  t_ctrl_tap_state.state = cur_dance(state);
  switch (t_ctrl_tap_state.state) {
    case SINGLE_TAP: register_code(KC_LCTRL); break;
    case SINGLE_HOLD: register_code(KC_LCTRL); break;
    case DOUBLE_TAP: 
      tap_code16(KC_ESC);
      break;
    case DOUBLE_HOLD:
      register_code(KC_ESC);
      break;
    case TRIPLE_TAP:
      break;
  }
}

void t_ctrl_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (t_ctrl_tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_LCTRL); break;
    case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
    case DOUBLE_TAP:
      break;
    case DOUBLE_HOLD: 
      unregister_code(KC_ESC);
      break;
  }
  t_ctrl_tap_state.state = 0;
}
void t_ent_finished (qk_tap_dance_state_t *state, void *user_data) {
  t_ent_tap_state.state = cur_dance(state);
  switch (t_ent_tap_state.state) {
    case SINGLE_TAP: 
      tap_code16(KC_ENT);
      break;
    case SINGLE_HOLD: 
      //tap_code16(KC_ENT);
      break;
    case DOUBLE_TAP: 
      tap_code16(KC_ENT);
      tap_code16(KC_ENT);
      break;
    case DOUBLE_HOLD:
      register_code(KC_LGUI);
      tap_code16(KC_ENT);
      break;
    case TRIPLE_TAP:
      tap_code16(KC_ENT);
      tap_code16(KC_ENT);
      tap_code16(KC_ENT);
      break;
  }
}

void t_ent_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (t_ent_tap_state.state) {
      case SINGLE_TAP: break;
    case SINGLE_HOLD: break;
    case DOUBLE_TAP:
      break;
    case DOUBLE_HOLD: 
      unregister_code(KC_LGUI);
      break;
    case TRIPLE_TAP:
      break;
  }
  t_ent_tap_state.state = 0;
}

void t_lead_finished (qk_tap_dance_state_t *state, void *user_data) {
  t_lead_tap_state.state = cur_dance(state);
  switch (t_lead_tap_state.state) {
    case SINGLE_TAP: 
      qk_leader_start();
      break;
    case SINGLE_HOLD: 
      qk_leader_start();
      break;
    case DOUBLE_TAP: 
      tap_code16(KC_LSFT);
      tap_code16(KC_LSFT);
      break;
    case DOUBLE_HOLD:
      tap_code16(KC_LSFT);
      register_code(KC_LSFT);
      break;
    case TRIPLE_TAP:
      tap_code16(KC_LSFT);
      tap_code16(KC_LSFT);
      tap_code16(KC_LSFT);
      break;
  }
}

void t_lead_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (t_lead_tap_state.state) {
    case SINGLE_TAP: break;
    case SINGLE_HOLD: 
      break;
    case DOUBLE_TAP:
      break;
    case DOUBLE_HOLD: 
      unregister_code(KC_LSFT);
      break;
    case TRIPLE_TAP:
      break;
  }
  t_lead_tap_state.state = 0;
}
