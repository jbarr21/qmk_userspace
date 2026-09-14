TRUE := 1
FALSE := 0

CAPS_WORD_ENABLE = yes
DYNAMIC_MACRO_ENABLE=yes
KEY_OVERRIDE_ENABLE = no
MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
EXTRAKEY_ENABLE = yes
COMBO_ENABLE = yes
REPEAT_KEY_ENABLE = yes

# save space
LTO_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no
MUSIC_ENABLE = no

ifneq ($(filter moonlander zsa/moonlander/reva zsa/moonlander/revb,$(KEYBOARD)),)
  IS_MOONLANDER := $(TRUE)
else
  IS_MOONLANDER := $(FALSE)
endif

ifeq ($(IS_MOONLANDER),$(FALSE))
  INTROSPECTION_KEYMAP_C = jbarr21.c
endif

SRC += features/custom_shift_keys.c
SRC += features/layer_lock.c
SRC += features/oneshot.c

ifeq ($(IS_MOONLANDER),$(FALSE))
  ifneq ($(KEYBOARD),fingerpunch/sweeeeep)
    SRC += features/achordion.c
  endif
endif

ifeq ($(KEYBOARD), fingerpunch/sweeeeep)
  DYNAMIC_MACRO_ENABLE=no
endif

ifeq ($(IS_MOONLANDER),$(TRUE))
    WEBUSB_ENABLE = yes
    ORYX_ENABLE = yes
		COMBO_ENABLE = no
    SRC += matrix.c
    SRC += features/rgb.c
else ifeq ($(KEYBOARD), fingerpunch/sweeeeep)
    SRC += features/oled.c
    RGBLIGHT_ENABLE=yes
    RGB_MATRIX_ENABLE=no
    FP_STARTUP_ANIMATION_DISABLE=yes
    FP_LAYER_LIGHTING_DISABLE=yes
    OLED_ENABLE=yes
    COMBO_ENABLE = no
endif
