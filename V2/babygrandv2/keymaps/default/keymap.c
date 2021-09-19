#include QMK_KEYBOARD_H
//hello person who got a baby grand
//i have but one question
//why
#define BASE 0

enum combos { JQUOTE_ENT };

const uint16_t PROGMEM jquote_combo[] = {KC_J, KC_QUOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = { [JQUOTE_ENT] = COMBO(jquote_combo, KC_ENT)};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_alpha_3x10(
    KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,
    KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,     KC_QUOTE,
        KC_Z,   KC_X,   KC_C,   KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  
                                         KC_BSPC, KC_SPC
  ),
};

