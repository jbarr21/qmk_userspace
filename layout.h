#ifdef TAP_DANCE_ENABLE
    #include "features/tap_dance.h"
#endif

// layer indices
#define DEF 0
#define NAV 1
#define NUM 2
#define MOU 3
#define SYM 4 
#define FUN 5
#define IDE 6
#define LCK 7

// home row mods
#define CTL_A LCTL_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
#define hrGUI_T LGUI_T(KC_T)
#define GUI_N RGUI_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define CTL_O RCTL_T(KC_O)

// symbol home row mods
#define CTL_LT  TD(DANCE_3)
#define ALT_GT  TD(DANCE_4)
#define SFT_LCB TD(DANCE_5)
#define GUI_RCB TD(DANCE_6)
#define GUI_MIN RGUI_T(KC_MINS)
#define SFT_EQL RSFT_T(KC_EQL)

// one shot mods
#define OSM_HYP OSM(MOD_HYPR)
#define OSM_MEH OSM(MOD_MEH)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)

// OS X shortcuts
#define OSX_UND	G(KC_Z)
#define OSX_CUT	G(KC_X)
#define OSX_CPY	G(KC_C)
#define OSX_PST	G(KC_V)

#define EMOJ     G(C(KC_SPC))
#define ALFR     G(KC_SPC)
#define HIST_BK  G(KC_LBRC)
#define HIST_FW  G(KC_RBRC)
#define TAB_LT   S(G(KC_LBRC))
#define TAB_RT   S(G(KC_RBRC))

#define KC_MOU_EMOJ TD(DANCE_0)
#define KC_IDE_ALFR TD(DANCE_1)
#define KC_ULCK     TO(DEF)

// IJ shortcuts
#define CLS_FUN  G(KC_F12)
#define FND_USE  A(KC_F7)
#define RENAME   S(KC_F6)
#define DBG_OVR  KC_F8
#define DBG_IN   KC_F7
#define DBG_OUT  S(KC_F8)
#define DBG_RES  A(G(KC_R))
#define DBG_EVL  A(KC_F8)

// custom keycodes
#define MY_SAFE_RANGE 0xfff0
#define LLOCK         MY_SAFE_RANGE+1
#define CAPSWRD       MY_SAFE_RANGE+2

// Layout aliases
#define LAYOUT_corne_w(...)       LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_moonlander_w(...)  LAYOUT_moonlander(__VA_ARGS__)

#define _DEF \
    KC_NO,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS, \
    KC_ESC,  CTL_A,   ALT_R,   SFT_S,   hrGUI_T, KC_D,        KC_H,    GUI_N,   SFT_E,   ALT_I,   CTL_O,   KC_QUOT, \
    CAPSWRD, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,   \
         KC_MOU_EMOJ, LT(NAV,KC_BSPC), LT(NUM,KC_TAB),        RSFT_T(KC_ENT), LT(SYM,KC_SPC), KC_IDE_ALFR

#define _NAV \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, HIST_BK, TAB_LT,  TAB_RT,  HIST_FW, XXXXXXX, \
    XXXXXXX, OSM_CTL, OSM_ALT, OSM_SFT, OSM_GUI, XXXXXXX,     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
    XXXXXXX, OSX_UND, OSX_CUT, OSX_CPY, OSX_PST, XXXXXXX,     XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  LLOCK,   \
                               XXXXXXX, XXXXXXX, XXXXXXX,     KC_ENT, G(KC_GRV), XXXXXXX

#define _NUM \
    XXXXXXX, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_VOLU,     KC_LPRN, KC_7,    KC_8,    KC_9,    KC_RPRN, XXXXXXX, \
    XXXXXXX, OSM_CTL, OSM_ALT, OSM_SFT, OSM_GUI, KC_VOLD,     KC_MINS, KC_4,    KC_5,    KC_6,    KC_PLUS, XXXXXXX, \
    XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, KC_MUTE,     KC_ASTR, KC_1,    KC_2,    KC_3,    KC_SLSH, LLOCK,   \
                               XXXXXXX, RGB_TOG, XXXXXXX,     LT(FUN,KC_ENT), KC_DOT, KC_0

#define _MOU \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, HIST_BK, TAB_LT,  TAB_RT,  HIST_FW, XXXXXXX, \
    XXXXXXX, OSM_CTL, OSM_ALT, OSM_SFT, OSM_GUI, XXXXXXX,     KC_F16,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, LLOCK,   \
                               XXXXXXX, XXXXXXX, XXXXXXX,     KC_BTN1, KC_BTN2, XXXXXXX

#define _SYM \
    XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, \
    XXXXXXX, CTL_LT,  ALT_GT,  SFT_LCB, GUI_RCB, KC_GRV,      KC_PIPE, GUI_MIN, SFT_EQL, KC_UNDS, KC_PLUS, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_TILD,     KC_QUES, KC_QUOT, KC_DQUO, KC_BSLS, KC_SLSH, LLOCK,   \
                               OSM_GUI, KC_BSPC, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX

#define _FUN \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,  KC_F15,  \
    XXXXXXX, OSM_CTL, OSM_ALT, OSM_SFT, OSM_GUI, XXXXXXX,     XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_F14,  \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,  KC_F13,  \
                               XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX

#define _IDE \
    TO(LCK), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_W,    XXXXXXX, XXXXXXX, RESET,   \
    XXXXXXX, CLS_FUN, XXXXXXX, FND_USE, RENAME,  XXXXXXX,     XXXXXXX, KC_A,    KC_S,    KC_D,    XXXXXXX, XXXXXXX, \
    XXXXXXX, DBG_OVR, DBG_IN,  DBG_OUT, DBG_RES, DBG_EVL,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LLOCK,   \
                               DM_REC1, DM_RSTP, DM_PLY1,     XXXXXXX, XXXXXXX, XXXXXXX

#define _LCK \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_ULCK, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                               XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX

// 3x6_3 to moonlander conversion
#define C_ML(k) SPLIT_42_TO_ML(k)
#define SPLIT_42_TO_ML( \
    k01, k02, k03, k04, k05, k06,    k07, k08, k09, k10, k11, k12, \
    k13, k14, k15, k16, k17, k18,    k19, k20, k21, k22, k23, k24, \
    k25, k26, k27, k28, k29, k30,    k31, k32, k33, k34, k35, k36, \
                   k37, k38, k39,    k40, k41, k42 \
) \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
    k01,   k02,   k03,   k04,   k05,   k06,   KC_NO,   KC_NO, k07,   k08,   k09,   k10,   k11,   k12, \
    k13,   k14,   k15,   k16,   k17,   k18,   KC_NO,   KC_NO, k19,   k20,   k21,   k22,   k23,   k24, \
    k25,   k26,   k27,   k28,   k29,   k30,                   k31,   k32,   k33,   k34,   k35,   k36, \
    KC_NO, KC_NO, KC_NO, KC_NO, k37,          OSM_HYP, OSM_MEH,      k42,   KC_NO, KC_NO, KC_NO, KC_NO, \
                         k38,   k39,   KC_NO,                 KC_NO, k40,   k41
