#ifdef TAP_DANCE_ENABLE
    #include "features/tap_dance.h"
#endif

// layer indices
#define DEF 0
#define SYM 1 
#define NAV 2
#define NUM 3
#define FUN 4
#define IDE 5
#define MOU 6

// home row mods
#ifdef HRM_ENABLE
#define HR_A LCTL_T(KC_A)
#define HR_R LALT_T(KC_R)
#define HR_S LSFT_T(KC_S)
#define HR_T LGUI_T(KC_T)
#define HR_N RGUI_T(KC_N)
#define HR_E RSFT_T(KC_E)
#define HR_I LALT_T(KC_I)
#define HR_O RCTL_T(KC_O)
#else
#define HR_A KC_A
#define HR_R KC_R
#define HR_S KC_S
#define HR_T KC_T
#define HR_N KC_N
#define HR_E KC_E
#define HR_I KC_I
#define HR_O KC_O
#endif

// one shot mods
#define OSM_HYP OSM(MOD_HYPR)
#define OSM_MEH OSM(MOD_MEH)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)

// layer toggles
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)

// OS X shortcuts
#define UNDO	G(KC_Z)
#define CUT     G(KC_X)
#define COPY	G(KC_C)
#define PASTE	G(KC_V)

#define EMOJ     G(C(KC_SPC))
#define ALFR     G(KC_SPC)
#define HIST_BK  G(KC_LBRC)
#define HIST_FW  G(KC_RBRC)
#define TAB_LT   S(G(KC_LBRC))
#define TAB_RT   S(G(KC_RBRC))
#define APP_WIN  G(KC_GRV)

#define KC_MOU_EMOJ TD(DANCE_0)
#define KC_IDE_ALFR TD(DANCE_1)

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
#define OS_GUI        MY_SAFE_RANGE+3
#define OS_SFT        MY_SAFE_RANGE+4
#define OS_ALT        MY_SAFE_RANGE+5
#define OS_CTL        MY_SAFE_RANGE+6

// Layout aliases
#define LAYOUT_corne_w(...)       LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_moonlander_w(...)  LAYOUT_moonlander(__VA_ARGS__)

#define _DEF \
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS, \
    KC_ESC,  HR_A,    HR_R,    HR_S,    HR_T,    KC_D,        KC_H,    HR_N,    HR_E,    HR_I,    HR_O,    KC_QUOT, \
    TO(MOU), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSL(IDE), \
                      LT(MOU,KC_BSPC), LA_NAV, OS_SFT,        KC_SPC,  LA_SYM, LT(IDE,KC_ENT)

#define _SYM \
    XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, \
    XXXXXXX, KC_PLUS, KC_UNDS, KC_EQL,  KC_MINS, KC_GRV,      KC_PIPE, OS_GUI,  OS_SFT,  OS_ALT,  OS_CTL,  XXXXXXX, \
    XXXXXXX, KC_LT,   KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD,     KC_QUES, KC_RPRN, KC_RCBR, KC_RBRC, KC_GT,   LLOCK,   \
                               KC_BSPC, _______, KC_BSPC,     XXXXXXX,  _______, XXXXXXX

#define _NAV \
    XXXXXXX, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_VOLU,     XXXXXXX, HIST_BK, TAB_LT,  TAB_RT,  HIST_FW, XXXXXXX, \
    XXXXXXX, OS_CTL,  OS_ALT,  OS_SFT,  OS_GUI,  KC_VOLD,     APP_WIN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
    XXXXXXX, UNDO,    CUT,     COPY,    PASTE,   KC_MUTE,     XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  LLOCK,   \
                               XXXXXXX, _______, XXXXXXX,     KC_ENT, _______, XXXXXXX

#define _NUM \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX, \
    OSL(FUN), OS_CTL,  OS_ALT,  OS_SFT,  OS_GUI, XXXXXXX,     XXXXXXX, KC_4,    KC_5,    KC_6,    KC_0,    KC_DOT, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OSL(FUN), XXXXXXX,    XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, LLOCK,   \
                               XXXXXXX, XXXXXXX, XXXXXXX,     LT(FUN, KC_ENT),  KC_DOT, KC_0

#define _FUN \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_F15,  XXXXXXX,  \
    XXXXXXX, OS_CTL,  OS_ALT,  OS_SFT,  OS_GUI,  XXXXXXX,     KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_F14,  XXXXXXX,  \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_F13,  LLOCK,  \
                               XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX

#define _IDE \
    RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_W,    XXXXXXX, XXXXXXX, RESET,   \
    XXXXXXX, CLS_FUN, XXXXXXX, FND_USE, RENAME,  XXXXXXX,     XXXXXXX, KC_A,    KC_S,    KC_D,    XXXXXXX, XXXXXXX, \
    XXXXXXX, DBG_OVR, DBG_IN,  DBG_OUT, DBG_RES, DBG_EVL,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LLOCK,   \
                               DM_REC1, DM_RSTP, DM_PLY1,     XXXXXXX, XXXXXXX, XXXXXXX

#define _MOU \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    TO(DEF), OS_CTL,  OS_ALT,  OS_SFT,  OS_GUI,  XXXXXXX,     KC_F16,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, LLOCK,   \
                               XXXXXXX, XXXXXXX, XXXXXXX,     KC_BTN1, KC_BTN2, XXXXXXX

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
