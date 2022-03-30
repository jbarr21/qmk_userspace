SRC += jbarr21.c

CONSOLE_ENABLE = no
COMMAND_ENABLE = no

SRC += features/caps_word.c
SRC += features/layer_lock.c

SRC += features/combos.c
COMBO_ENABLE = yes

ifeq ($(KEYBOARD), moonlander)
    WEBUSB_ENABLE = yes
    ORYX_ENABLE = yes
    DYNAMIC_MACRO_ENABLE = yes
    SRC += matrix.c
    SRC += features/rgb.c
endif

ifeq ($(KEYBOARD), kprepublic/bm16s)
    TAP_DANCE_ENABLE = no
else
    TAP_DANCE_ENABLE = yes
    SRC += features/tap_dance.c
endif