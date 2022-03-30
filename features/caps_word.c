#include QMK_KEYBOARD_H
#include "caps_word.h"

static bool caps_word_active = false;

void process_caps_word(uint16_t keycode, keyrecord_t* record, uint16_t activate_key) {
    if (!caps_word_active) {
        if (keycode == activate_key) {
            caps_word_active = true;
            tap_code(KC_CAPS);
        }
        return;
    }
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        if (!record->tap.count) {
            return;
        }
        keycode &= 0xff;
    }
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
        case KC_P1 ... KC_P0:
        case KC_UNDS:
        case KC_MINS:
        case KC_BSPC:
        case KC_DEL:
            break;
        default:
            if (keycode >= KC_A && keycode <= KC_RGUI ) {
                tap_code(KC_CAPS);
                caps_word_active = false;
            }
            break;
    }
}

void caps_word_set(bool active) {
  if (active != caps_word_active) {
    if (active) {
      clear_mods();
      clear_oneshot_mods();
      tap_code(KC_CAPS);
    }
    caps_word_active = active;
  }
}
