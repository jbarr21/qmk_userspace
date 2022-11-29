#pragma once

#define HRM_ENABLE
//#define CALLUM_MODS_ENABLE

#undef TAPPING_TERM
#define TAPPING_TERM 175
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define ONESHOT_TIMEOUT 5000
#define BILATERAL_COMBINATIONS
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

#if defined(KEYBOARD_moonlander)
    #define ORYX_CONFIGURATOR
    #define FIRMWARE_VERSION u8"J4q60/KJZ9l"
    #define RGB_MATRIX_STARTUP_SPD 60
    #undef BILATERAL_COMBINATIONS
#endif

#if defined(KEYBOARD_bm16s)
    #undef BILATERAL_COMBINATIONS
#endif

// save space
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE

#include "layout.h"
