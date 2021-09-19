#include QMK_KEYBOARD_H
// babygrand mac
#define BASE 0
#define CLOSE 1
#define FAR 2
#define FUNKY 3
#define CLS_SPC LT(CLOSE, KC_SPC)
#define FAR_F LT(FAR, KC_F)
#define FNK_D LT(FUNKY, KC_D)
#define SFT_DOT     RSFT_T(KC_DOT)
#define CTL_COMM    RCTL_T(KC_COMM)
#define GUI_M       RGUI_T(KC_M)
#define ALT_N       RALT_T(KC_N)
#define ALT_V       LALT_T(KC_V)
#define GUI_C       LGUI_T(KC_C)
#define CTL_X       LCTL_T(KC_X)
#define SFT_Z       LSFT_T(KC_Z)
#define COPY        LGUI(KC_C)
#define PASTE       LGUI(KC_V)
#define CUT         LGUI(KC_X)
#define UNDO        LGUI(KC_Z)
#define RUS_TGL     LALT(KC_SPC)
#define LOCK        LGUI(LCTL(KC_Q))
#define vvv         KC_TRNS


enum custom_keycodes {
    TYPEDON = SAFE_RANGE,
    PASSWORD,
    BRACKETBRACKET,
    CURLYCURLY,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TYPEDON:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("{typed on a Baby Grand}");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case PASSWORD:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("penisman"SS_TAP(X_ENT));
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case BRACKETBRACKET:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("[]" SS_TAP(X_LEFT));
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case CURLYCURLY:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("{}" SS_TAP(X_LEFT));
            } else {
                // when keycode QMKBEST is released
            }
    }
    return true;
};
enum combos { CORNERS_PWR, JQUOTE_ENT, PENIS_PASSWORD };

const uint16_t PROGMEM corners_combo[] = {KC_Q, KC_P, SFT_Z, SFT_DOT, COMBO_END};
const uint16_t PROGMEM jquote_combo[] = {KC_J, KC_QUOT, COMBO_END};
const uint16_t PROGMEM penis_combo[]   = {KC_W, KC_S, SFT_Z, CTL_X, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {[CORNERS_PWR] = COMBO(corners_combo, KC_PWR), [JQUOTE_ENT] = COMBO(jquote_combo, KC_ENT),[PENIS_PASSWORD] = COMBO(penis_combo, PASSWORD)};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_alpha_3x10(
    KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,
    KC_A,    KC_S,    FNK_D,   FAR_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,     KC_QUOTE,
        SFT_Z,   CTL_X,   GUI_C,   ALT_V,    KC_B,    ALT_N,    GUI_M,   CTL_COMM, SFT_DOT,  
                                         KC_BSPC, CLS_SPC
  ),
    

  [FAR] = LAYOUT_alpha_3x10(
    KC_ESC,    TYPEDON,  KC_BSLS, RUS_TGL, _______,  KC_PGUP,   KC_HOME,   KC_UP,     KC_END,     KC_INS,
    KC_CAPS,   KC_TAB,   KC_PIPE, vvv ,    LOCK,     KC_PGDN,   KC_LEFT,   KC_DOWN,   KC_RIGHT,   KC_DEL,
           UNDO,      CUT,      COPY,    PASTE,   KC_LBRC,  KC_RBRC,   _______,  _______, KC_QUES,   
                                           BRACKETBRACKET,  CURLYCURLY
  ),

  [CLOSE] = LAYOUT_alpha_3x10(
    KC_1,       KC_2,          KC_3,    KC_4,    KC_5,     KC_6,    KC_7,     KC_8,    KC_9,    KC_0,
    KC_EXCLAIM, KC_AT,         KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN,
          KC_MINUS,   KC_UNDERSCORE, KC_EQL,  KC_PLUS, KC_GRAVE, KC_TILDE,KC_SCOLON, KC_COLON,  KC_SLASH,
                                                 KC_BSPC, vvv

  ),
    [FUNKY] = LAYOUT_alpha_3x10(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, vvv,     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  _______,
         RESET,   _______, KC_F8,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                               KC_VOLD, KC_VOLU
  )
};

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(D5);
  setPinOutput(B0);
}



void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinLow(D5);
  } else {
    writePinHigh(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(B0);
  } else {
    writePinHigh(B0);
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FAR_F:
            return TAPPING_TERM - 50;
        case CLS_SPC:
            return TAPPING_TERM - 50;
        case SFT_Z:
            return TAPPING_TERM - 80;
        case SFT_DOT:
            return TAPPING_TERM - 75;
        default:
            return TAPPING_TERM;
    }
}
