#pragma once

#define ACHORDION_ENABLE
#define CUSTOM_SHIFT_KEYS_ENABLE
#undef CALLUM_MODS_ENABLE

#undef TAPPING_TERM
#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY

#if defined(KEYBOARD_moonlander)
    // can remove when moonlander is upgraded
    #define TAPPING_FORCE_HOLD_PER_KEY
#else
    #define QUICK_TAP_TERM_PER_KEY
    #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#endif
#define PERMISSIVE_HOLD_PER_KEY

#define ONESHOT_TIMEOUT 5000
// #define BILATERAL_COMBINATIONS
// #define BILATERAL_COMBINATIONS_PER_KEY
#define SPLIT_USB_DETECT

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 9

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 110

#ifdef COMBO_ENABLE
    #define COMBO_VARIABLE_LEN
    #define COMBO_ONLY_FROM_LAYER 0  // DEF layer
    #undef COMBO_TERM
    #define COMBO_TERM 50
#endif

#if defined(KEYBOARD_fingerpunch_sweeeeep)
    #define FP_DISABLE_CUSTOM_KEYCODES
    #define FP_STARTUP_ANIMATION_DISABLE
    #define FP_LAYER_LIGHTING_DISABLE
    #define FP_LAYER_LIGHTING_DYNAMIC_BASE_LAYER_DISABLE
    #undef ACHORDION_ENABLE
#else
    #define LAYER_LOCK_ENABLE
#endif

#if defined(KEYBOARD_moonlander)
    #define LEGACY_CAPS_WORD_ENABLE
    #define ORYX_CONFIGURATOR
    #define FIRMWARE_VERSION u8"J4q60/KJZ9l"
    #define RGB_MATRIX_STARTUP_SPD 60
    #undef BILATERAL_COMBINATIONS
    #undef ACHORDION_ENABLE
#endif

#if defined(KEYBOARD_bm16s)
    #undef BILATERAL_COMBINATIONS
#endif

// save space
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE

#include "layout.h"
