// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum fulcrum_layers {
  _ALPHA1 = 0,
  _ALPHA2 = 1,
  _NUM = 2,
  _NAV = 3,
};

// =============================== MACROS =============================== //

enum custom_keycodes {
  REDO = SAFE_RANGE,
  FIND,
  AND,
  THE,
  AKE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case REDO:
      if (record->event.pressed) {
        // Press down CMD and Shift
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        // Tap Z
        tap_code(KC_Z);
        // Release Shift and CMD
        unregister_code(KC_LSFT);
        unregister_code(KC_LGUI);
      }
      break;
    case FIND:
      if (record->event.pressed) {
        // Press down CMD
        register_code(KC_LGUI);
        // Tap F
        tap_code(KC_F);
        // Release CMD
        unregister_code(KC_LGUI);
      }
      break;
    case AND:
      if (record->event.pressed) {
        SEND_STRING("and");
      }
      break;
    case THE:
      if (record->event.pressed) {
        SEND_STRING("the");
      }
      break;
    case AKE:
      if (record->event.pressed) {
        SEND_STRING("ake");
      }
      break;
    }
  return true;
}

// =============================== COMBOS =============================== //

enum combos {
  RS_BSPC,
  TR_LALT_BSPC,
  DC_ALPHA2,
  SV_SLSH,
  NV_TAB,
  XC_EQL,
  SC_EXLM,
  RV_LCMD_F,
  EI_ENT,
  HU_DOT,
  AK_RPRN,
  KH_MINS,
  EH_SLSH,
  RN_RN,
  RC_QU,
  IO_YOU,
  EU_OF,
  AI_AY,
  AE_THE,
  IH_OULD,
  IK_OUGH,
  AU_FROM,
  KU_JUST,
  RIO_YOURE,
  TIO_YOU_CAPS,
  RCI_QU
};

// -- Left Hand -- //
const uint16_t PROGMEM rs_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM tr_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM dc_combo[] = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM sv_combo[] = {KC_S, KC_V, COMBO_END};
const uint16_t PROGMEM td_combo[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM nv_combo[] = {KC_N, KC_V, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM sc_combo[] = {KC_S, KC_C, COMBO_END};
const uint16_t PROGMEM rv_combo[] = {KC_R, KC_V, COMBO_END};
const uint16_t PROGMEM rn_combo[] = {KC_R, KC_N, COMBO_END};
const uint16_t PROGMEM rc_combo[] = {KC_R, KC_C, COMBO_END};

// -- Right Hand -- //
const uint16_t PROGMEM ei_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM hu_combo[] = {KC_H, KC_U, COMBO_END};
const uint16_t PROGMEM ak_combo[] = {KC_A, KC_K, COMBO_END};
const uint16_t PROGMEM kh_combo[] = {KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM eh_combo[] = {KC_E, KC_H, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM eu_combo[] = {KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM ai_combo[] = {KC_A, KC_I, COMBO_END};
const uint16_t PROGMEM ae_combo[] = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM ih_combo[] = {KC_I, KC_H, COMBO_END};
const uint16_t PROGMEM ik_combo[] = {KC_I, KC_K, COMBO_END};
const uint16_t PROGMEM au_combo[] = {KC_A, KC_U, COMBO_END};
const uint16_t PROGMEM ku_combo[] = {KC_K, KC_U, COMBO_END};

// -- Both Hands -- //
const uint16_t PROGMEM rio_combo[] = {KC_R, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM tio_combo[] = {KC_T, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM rci_combo[] = {KC_R, KC_C, KC_I, COMBO_END};


combo_t key_combos[] = {
  // Keys - Left Hand
  [RS_BSPC] = COMBO(rs_combo, KC_BSPC),
  [TR_LALT_BSPC] = COMBO(tr_combo, LALT(KC_BSPC)),
  [DC_ALPHA2] = COMBO(dc_combo, OSL(_ALPHA2)),
  [SV_SLSH] = COMBO(sv_combo, LCMD(KC_SLSH)),
  [NV_TAB] = COMBO(nv_combo, KC_TAB),
  [XC_EQL] = COMBO(xc_combo, KC_EQL),
  [SC_EXLM] = COMBO(sc_combo, KC_EXLM),
  [RV_LCMD_F] = COMBO(rv_combo, LCMD(KC_F)),

  // Keys - Right Hand
  [EI_ENT] = COMBO(ei_combo, KC_ENT),
  [HU_DOT] = COMBO(hu_combo, KC_DOT),
  [AK_RPRN] = COMBO(ak_combo, KC_RPRN),
  [KH_MINS] = COMBO(kh_combo, KC_MINS),
  [EH_SLSH] = COMBO(eh_combo, KC_SLSH),

  // Words - Left Hand
  [RN_RN] = COMBO_ACTION(rn_combo),
  [RC_QU] = COMBO_ACTION(rc_combo),

  // Words - Right Hand
  [IO_YOU] = COMBO_ACTION(io_combo),
  [EU_OF] = COMBO_ACTION(eu_combo),
  [AI_AY] = COMBO_ACTION(ai_combo),
  [AE_THE] = COMBO_ACTION(ae_combo),
  [IH_OULD] = COMBO_ACTION(ih_combo),
  [IK_OUGH] = COMBO_ACTION(ik_combo),
  [AU_FROM] = COMBO_ACTION(au_combo),
  [KU_JUST] = COMBO_ACTION(ku_combo),

  // Words - Both Hands
  [RIO_YOURE] = COMBO_ACTION(rio_combo),
  [TIO_YOU_CAPS] = COMBO_ACTION(tio_combo),
  [RCI_QU] = COMBO_ACTION(rci_combo),
};

// Per-Combo Terms
#ifdef COMBO_TERM_PER_COMBO
uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
  switch (combo_index) {
    case RS_BSPC:
      return 40;
    case TR_LALT_BSPC:
      return 10;
    case RN_RN:
      return 50;
    case RIO_YOURE:
      return 80;
    case TIO_YOU_CAPS:
      return 80;
  }
  return COMBO_TERM;
}
#endif


// Handle word combos
void process_combo_event(uint16_t combo_index, bool pressed) {
  switch (combo_index) {
    case RN_RN:
      if (pressed) {
        SEND_STRING("rn");
      }
      break;
    case RC_QU:
      if (pressed) {
        SEND_STRING("qu");
      }
      break;
    case IO_YOU:
      if (pressed) {
        SEND_STRING("you");
      }
      break;
    case EU_OF:
      if (pressed) {
        SEND_STRING("of");
      }
      break;
    case AI_AY:
      if (pressed) {
        SEND_STRING("ay");
      }
      break;
    case AE_THE:
      if (pressed) {
        SEND_STRING("the");
      }
      break;
    case IH_OULD:
      if (pressed) {
        SEND_STRING("ould");
      }
      break;
    case IK_OUGH:
      if (pressed) {
        SEND_STRING("ough");
      }
      break;
    case AU_FROM:
      if (pressed) {
        SEND_STRING("from");
      }
      break;
    case KU_JUST:
      if (pressed) {
        SEND_STRING("just");
      }
      break;
    case RIO_YOURE:
      if (pressed) {
        SEND_STRING("you're");
      }
      break;
    case TIO_YOU_CAPS:
      if (pressed) {
        SEND_STRING("You");
      }
      break;
    case RCI_QU:
      if (pressed) {
        SEND_STRING("qu");
      }
      break;
  }
}

// =============================== LEADER KEYS =============================== //

void leader_start_user(void) {
}

void leader_end_user(void) {
  // LDR-I => Select entire line
  if (leader_sequence_one_key(KC_I)) {
    SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)) SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_UP(X_LSFT));
  }
  // Window left half
  if (leader_sequence_one_key(KC_S)) {
    SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_LEFT) SS_UP(X_LSFT) SS_UP(X_LCTL));
  }
  // Window right half
  if (leader_sequence_one_key(KC_E)) {
    SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_RIGHT) SS_UP(X_LSFT) SS_UP(X_LCTL));
  }
  // Window top half
  if (leader_sequence_one_key(KC_V)) {
    SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_UP) SS_UP(X_LSFT) SS_UP(X_LCTL));
  }
  // Window bottom half
  if (leader_sequence_one_key(KC_U)) {
    SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_DOWN) SS_UP(X_LSFT) SS_UP(X_LCTL));
  }
  // Caps Lock
  if (leader_sequence_one_key(KC_C)) {
    SEND_STRING(SS_TAP(X_CAPS_LOCK));
  }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * --- ALPHA 1 ---
      *                  V,                            QUOTE,
      *       N,   R,    S,     T,       -       A,      E,      I,      O,  
      *            X,    C,     D,       -       H,      U,      K,        
      *     SPC/Shift,   ESC/CMD+SHIFT,  -     LEADER/CMD, ALPHA2 (1-shot), 
      *                                  -
      *                 ⌥                -              ^
      *           UNDO      ALT          -        _NUM     Tab    
      *              ESC/CMD             -            FIND/⌘
      */
    [_ALPHA1] = LAYOUT_20_key_split(
                          KC_V,                                                KC_QUOT,
        KC_N,    KC_R,    KC_S,    KC_T,                               KC_A,    KC_E,    KC_I,    KC_O,
                 KC_X,    KC_C,    KC_D,                               KC_H,    KC_U,    KC_K,
                 LSFT_T(KC_SPC), LSG_T(KC_ESC),                  CMD_T(QK_LEAD), OSL(_ALPHA2),
        KC_LOPT, KC_UNDO, CMD_T(KC_ESC), LT(_NAV, REDO),      KC_CIRC, MO(_NUM), CMD_T(FIND), KC_TAB
    ),

         /*
      * --- ALPHA 2 ---
      *                   W,                              Z,
      *       J,    F,    L,     P,       -      and,    the,     Y,    Q,  
      *             B,    M,     G,       -       ;,      ,      ake,         
      *                  _____,   _____,  -  _____,   _____,
      *                                   -
      *                 _____,            -             _____,
      *           _____,      _____,      -      _____,      _____,    
      *                 _____             -             _____
      */
      [_ALPHA2] = LAYOUT_20_key_split(
                          KC_W,                                                 KC_Z,
        KC_J,    KC_F,    KC_L,    KC_P,                               AND,     THE,    KC_Y,    KC_Q,
                 KC_B,    KC_M,    KC_G,                            KC_SCLN,  KC_COMM,   AKE,
                              KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
      ),

/*
  * --- NUM ---
  *                 [,                      ],
  *       1,   2,   3,   4,    -       5,   6,   7,   8,  
  *            [,   -,   0,    -       9,   =,   ],
  *           _____,   _____,  -  _____,   _____,
  *                            -
  *          _____,            -             _____,
  *    _____,      _____,      -      _____,      _____,    
  *          _____             -             _____
  */
   [_NUM] = LAYOUT_20_key_split(
                       KC_LBRC,                                            KC_RBRC,
     KC_1,    KC_2,    KC_3,    KC_4,                               KC_5,     KC_6,    KC_7,    KC_8,
              KC_LBRC, KC_MINS, KC_0,                               KC_9,   KC_EQL,    KC_RBRC,
                              KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
      ),

 /*
  * --- NAV --- 
  *               _____,                        ↑,
  * ⇧,   ⌥,   ⌘,   ⌃,          -       ←,       ↓,       →,   End,  
  *  _____,   R click,   `,    -       L click, R click, Home,
  *           _____,   _____,  -  _____,   _____,
  *                            -
  *          _____,            -            mouse up,
  *    _____,      _____,      -   mouse left,      mouse right,    
  *          _____             -            mouse down,
   */
   [_NAV] = LAYOUT_20_key_split(
                       KC_TRNS,                                           KC_UP,
     KC_LSFT,  KC_LOPT,  KC_LCMD,  KC_LCTL,                     KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,
               KC_TRNS,  MS_BTN3,  KC_GRV,                      MS_BTN1,  MS_BTN3,  KC_HOME,
                              KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 MS_UP, MS_LEFT, MS_DOWN, MS_RGHT
    ),
};
