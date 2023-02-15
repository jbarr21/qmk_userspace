SRC += jbarr21.c

CAPS_WORD_ENABLE = yes
KEY_OVERRIDE_ENABLE = no
MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
EXTRAKEY_ENABLE = yes

# save space
LTO_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no
MUSIC_ENABLE = no

SRC += features/custom_shift_keys.c
SRC += features/layer_lock.c
SRC += features/oneshot.c
SRC += features/repeat_key.c

SRC += features/combos.c
COMBO_ENABLE = yes

ifeq ($(KEYBOARD), cantor)
    DYNAMIC_MACRO_ENABLE=yes
else ifeq ($(KEYBOARD), beekeeb/piantor)
    DYNAMIC_MACRO_ENABLE=yes
else ifeq ($(KEYBOARD), moonlander)
    WEBUSB_ENABLE = yes
    ORYX_ENABLE = yes
    DYNAMIC_MACRO_ENABLE = yes
    SRC += matrix.c
    SRC += features/rgb.c
else ifeq ($(KEYBOARD), fingerpunch/sweeeeep)
    SRC += features/oled.c
    RGBLIGHT_ENABLE=yes
    RGB_MATRIX_ENABLE=no
    FP_STARTUP_ANIMATION_DISABLE=yes
    FP_LAYER_LIGHTING_DISABLE=yes
    OLED_ENABLE=yes
    DYNAMIC_MACRO_ENABLE=no
endif
