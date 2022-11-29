#pragma once
#include QMK_KEYBOARD_H

#define IS_HRM(keycode) \
    keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX \
    && (((keycode & 0xff) <= KC_Z && (keycode & 0xff) >= KC_A) \
        || (keycode & 0xff) == KC_QUOT || (keycode & 0xff) == KC_TAB)
