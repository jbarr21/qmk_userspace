#include QMK_KEYBOARD_H

const key_override_t comm_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_DQUO); // Shift , is "
const key_override_t dot_key_override = {
    .trigger_mods           = MOD_MASK_SHIFT,                       //
    .trigger                = KC_DOT,                                                    //
    .replacement            = KC_QUOT,                                                   //
    .layers                 = ~0,  
    .suppressed_mods        = MOD_MASK_SHIFT,                       //
    .enabled                = NULL
};

const key_override_t** key_overrides = (const key_override_t*[]){
    &comm_key_override,
    &dot_key_override,
    NULL
};