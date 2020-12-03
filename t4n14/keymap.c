#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
  BASE,
  FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox(
    // left hand
    KC_ESC,           KC_1,     KC_2,    KC_3,    KC_4,     KC_5, KC_MINS,
    KC_TAB,           KC_Q,     KC_W,    KC_E,    KC_R,     KC_T, KC_NO,
    KC_LALT,          KC_A,     KC_S,    KC_D,    KC_F,     KC_G,
    KC_LSFT,          KC_Z,     KC_X,    KC_C,    KC_V,     KC_B, KC_ENT,
    LCTL_T(KC_GRAVE), KC_QUOTE, KC_LGUI, KC_LEFT, KC_RIGHT,

    // left thumb
             KC_NO,  KC_NO,
                     KC_NO,
    KC_BSPC, KC_SPC, KC_NO,

    // right hand
    KC_EQL, KC_6, KC_7,  KC_8,    KC_9,    KC_0,    KC_CIRC,
    KC_NO,  KC_Y, KC_U,  KC_I,    KC_O,    KC_P,    KC_DLR,
            KC_H, KC_J,  KC_K,    KC_L,    KC_SCLN, KC_RALT,
    KC_DEL, KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                  KC_UP, KC_DOWN, KC_LBRC, KC_RBRC, KC_RCTL,

    // right thumb
    KC_NO,  KC_BSLASH,
    KC_NO,
    TT(FN), KC_NO,  KC_ENT
  ),
  [FN] = LAYOUT_ergodox(
    // left hand
    KC_TRNS, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_NO,
    KC_TRNS, KC_F11, KC_F12,  KC_F13,  KC_F14,  KC_F15, KC_NO,
    KC_TRNS, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
    KC_LCTL, KC_NO,  KC_TRNS, KC_TRNS, KC_TRNS,

    // left thumb
               KC_NO, KC_NO,
                      KC_NO,
    KC_TRNS, KC_TRNS, KC_NO,

    // right hand
    KC_NO,   KC_F6,  KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_HOME,
    KC_NO,   KC_F16, KC_F17,  KC_F18,  KC_F19, KC_F20, KC_END,
             KC_NO,  KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_TRNS,
    KC_TRNS, KC_NO,  KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_TRNS,
                     KC_TRNS, KC_TRNS, KC_NO,  KC_NO,  KC_TRNS,

    // right thumb
    KC_NO,    KC_NO,
    KC_NO,
    TO(BASE), KC_NO, KC_TRNS
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void keyboard_post_init_user(void) {
  rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_ALL);
  ergodox_led_all_set(LED_BRIGHTNESS_HI);
};

layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
    case BASE:
      break;
    case FN:
      ergodox_right_led_1_on();
      break;
    default:
      break;
  }

  return state;
};
