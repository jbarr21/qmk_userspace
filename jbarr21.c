#include "jbarr21.h"
#include "layout.h"
#include "features/custom_shift_keys.h"
#include "features/oneshot.h"
#include "features/layer_lock.h"

const custom_shift_key_t custom_shift_keys[] = {
  {KC_COMM, KC_DQUO}, // Shift , is "
  {KC_DOT , KC_QUOT}, // Shift . is '
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

#ifdef BILATERAL_COMBINATIONS
bool get_enable_bilateral_combinations_per_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(MOU,KC_TAB):
        case LT(SYM,KC_SPC):
            return false;
        default:
            return true;
    }
}
#endif

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    
    #ifdef CALLUM_MODS_ENABLE
    update_oneshot(&os_shft_state, KC_LSFT, OS_SFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_cmd_state, KC_LCMD, OS_GUI, keycode, record);
    #endif

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // state = update_tri_layer_state(state, NAV, NUM, FUN);
    return state;
}
