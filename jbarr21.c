#include "jbarr21.h"
#include "layout.h"
#include "features/custom_shift_keys.h"
#include "features/oneshot.h"
#include "features/layer_lock.h"
#include "features/repeat_key.h"

const custom_shift_key_t custom_shift_keys[] = {
  {LT(NAV, KC_BSPC), KC_DEL},  // Shift BS is DEL
  {KC_COMM, KC_DQUO}, // Shift , is "
  {KC_DOT , KC_QUOT}, // Shift . is '
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

#ifdef BILATERAL_COMBINATIONS
bool get_enable_bilateral_combinations_per_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TH_R2:
            return false;
        default:
            return true;
    }
}
#endif

#ifdef CALLUM_MODS_ENABLE
bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case KC_LSFT:
    case OS_SFT:
    case OS_CTL:
    case OS_ALT:
    case OS_GUI:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef LAYER_LOCK_ENABLE
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
    #endif

    #ifdef CUSTOM_SHIFT_KEYS_ENABLE
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    #endif

    #ifdef CALLUM_MODS_ENABLE
    update_oneshot(&os_shft_state, KC_LSFT, OS_SFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_cmd_state, KC_LCMD, OS_GUI, keycode, record);
    #endif

    #ifdef REPEAT_KEY_ENABLE
    if (!process_repeat_key(keycode, record, REPEAT)) { return false; }
    #endif

    return true;
}

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    if (IS_HRM(keycode)) {
        if (keycode >> 8 & MOD_MASK_SHIFT) {
            return TAPPING_TERM + 50;
        }
        return TAPPING_TERM + 100;
    }
    return TAPPING_TERM;
}
#endif

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return IS_HRM(keycode) ? false : true;
}
#endif

#ifdef TAPPING_FORCE_HOLD_PER_KEY
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    return IS_HRM(keycode) ? false : true;
}
#endif