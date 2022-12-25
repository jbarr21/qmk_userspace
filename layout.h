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
#define MED 7

// layer toggles
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)

// custom keycodes
#define LLOCK         0xfff0
#define CAP_WRD       0xfff1
#define OS_GUI        0xfff2
#define OS_SFT        0xfff3
#define OS_ALT        0xfff4
#define OS_CTL        0xfff5

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
#ifdef CALLUM_MODS_ENABLE
  #define OSM_GUI OS_GUI
  #define OSM_SFT OS_SFT
  #define OSM_ALT OS_ALT
  #define OSM_CTL OS_CTL
#else
  #define OSM_GUI OSM(MOD_LGUI)
  #define OSM_SFT OSM(MOD_LSFT)
  #define OSM_ALT OSM(MOD_LALT)
  #define OSM_CTL OSM(MOD_LCTL)
#endif
#define OSM_HYP OSM(MOD_HYPR)
#define OSM_MEH OSM(MOD_MEH)

// OS X shortcuts
#define UNDO    G(KC_Z)
#define REDO    G(S(KC_Z))
#define CUT     G(KC_X)
#define COPY    G(KC_C)
#define PASTE   G(KC_V)
#define CLOSE   G(KC_W)

#define VIMAC    G(S(A(C(KC_F))))
#define EMOJ     G(C(KC_SPC))
#define ALFR     G(KC_SPC)
#define CTXS     A(KC_TAB)
#define HIST_BK  G(KC_LBRC)
#define HIST_FW  G(KC_RBRC)
#define TAB_LT   S(G(KC_LBRC))
#define TAB_RT   S(G(KC_RBRC))
#define APP_WIN  G(KC_GRV)
#define TOG_SCR  KC_F19

#define KC_MOU_EMOJ TD(DANCE_0)
#define KC_IDE_ALFR TD(DANCE_1)

// IJ shortcuts
#define CLS_FUN  G(KC_F12)
#define FND_USE  A(KC_F7)
#define RENAME   S(KC_F6)
#define BRK_PT   G(KC_F8)
#define DBG_OVR  KC_F8
#define DBG_IN   KC_F7
#define DBG_OUT  S(KC_F8)
#define DBG_RES  A(G(KC_R))
#define DBG_EVL  A(KC_F8)

// Layout aliases
#define LAYOUT_sweeeeep_w(...)         LAYOUT_sweeeeep(__VA_ARGS__)
#define LAYOUT_corne_w(...)            LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_moonlander_w(...)       LAYOUT_moonlander(__VA_ARGS__)

#define _DEF \
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, \
    HR_A,    HR_R,    HR_S,    HR_T,    KC_D,        KC_H,    HR_N,    HR_E,    HR_I,    HR_O,    \
    LT(MED,KC_Z), KC_X, KC_C,  KC_V,    KC_B,        KC_K,    KC_M,    KC_COMM, KC_DOT,  LT(MED,KC_SLSH), \
      LT(MOU,KC_ESC), LT(NAV,KC_BSPC), LT(NUM,KC_TAB),        LT(IDE,KC_ENT), LT(SYM,KC_SPC), OSM_SFT

#define _SYM \
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_DQUO, KC_QUOT, \
    KC_PLUS, KC_UNDS, KC_EQL,  KC_MINS, KC_GRV,      KC_PIPE, OSM_GUI, OSM_SFT, OSM_ALT, OSM_CTL, \
    KC_LT,   KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD,     KC_BSLS, KC_RPRN, KC_RCBR, KC_RBRC, KC_GT,   \
                      XXXXXXX, XXXXXXX, XXXXXXX,     MO(MED), XXXXXXX, XXXXXXX

#define _NAV \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_CAPS, HIST_BK, TAB_LT,  TAB_RT,  HIST_FW, \
    OSM_CTL, OSM_ALT, OSM_SFT, OSM_GUI, XXXXXXX,     APP_WIN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  \
                      XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX

#define _NUM \
    KC_PLUS, KC_SLSH, KC_ASTR, KC_MINS, XXXXXXX,     XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, \
    OSM_CTL, OSM_ALT, OSM_SFT, OSM_GUI, XXXXXXX,     XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, \
                      XXXXXXX, XXXXXXX, XXXXXXX,     LT(FUN,KC_DOT),  KC_0,    XXXXXXX

#define _FUN \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_F15,  \
    OSM_CTL, OSM_ALT, OSM_SFT, OSM_GUI, XXXXXXX,     KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_F14,  \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_F13,  \
                      XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX

#define _IDE \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_A,    KC_S,    KC_W,    KC_D,    \
    OSM_CTL, CLS_FUN, FND_USE, RENAME,  BRK_PT,      XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    \
    DBG_OVR, DBG_IN,  DBG_OUT, DBG_RES, DBG_EVL,     XXXXXXX, DM_PLY1, DM_RSTP, DM_REC1, XXXXXXX, \
                      XXXXXXX, XXXXXXX, MO(FUN),     XXXXXXX, MO(MED), XXXXXXX

#define _MOU \
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    OSM_CTL, OSM_ALT, OSM_SFT, OSM_GUI, XXXXXXX,     KC_F16,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, \
                      XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_BTN1, KC_BTN2

#define _MED \
    RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RGB_TOG,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, \
    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,     XXXXXXX, OSM_GUI, OSM_SFT, OSM_ALT, OSM_CTL, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                      XXXXXXX, KC_MPLY, KC_MUTE,     XXXXXXX, XXXXXXX, XXXXXXX

// 3x5_3 to 3x6_3 conversion
#define C_42(k) SPLIT_36_TO_42(k)
#define SPLIT_36_TO_42( \
    k01, k02, k03, k04, k05,    k06, k07, k08, k09, k10, \
    k11, k12, k13, k14, k15,    k16, k17, k18, k19, k20, \
    k21, k22, k23, k24, k25,    k26, k27, k28, k29, k30, \
              k31, k32, k33,    k34, k35, k36 \
) \
    KC_NO,  k01, k02, k03, k04, k05,    k06, k07, k08, k09, k10, KC_BSLS, \
    KC_ESC, k11, k12, k13, k14, k15,    k16, k17, k18, k19, k20, KC_QUOT, \
    KC_NO,  k21, k22, k23, k24, k25,    k26, k27, k28, k29, k30, LLOCK,   \
                      k31, k32, k33,    k34, k35, k36

// 3x5_3 to moonlander conversion
#define C_ML(k) SPLIT_36_TO_ML(k)
#define SPLIT_36_TO_ML( \
         k01, k02, k03, k04, k05,    k06, k07, k08, k09, k10, \
         k11, k12, k13, k14, k15,    k16, k17, k18, k19, k20, \
         k21, k22, k23, k24, k25,    k26, k27, k28, k29, k30, \
                   k31, k32, k33,    k34, k35, k36 \
) \
    KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
    KC_NO,  k01,   k02,   k03,   k04,   k05,   KC_NO,   KC_NO, k06,   k07,   k08,   k09,   k10,   KC_NO, \
    KC_ESC, k11,   k12,   k13,   k14,   k15,   KC_NO,   KC_NO, k16,   k17,   k18,   k19,   k20,   KC_NO, \
    KC_NO,  k21,   k22,   k23,   k24,   k25,                   k26,   k27,   k28,   k29,   k30,   KC_NO, \
    KC_NO,  KC_NO, KC_NO, KC_NO, k31,          OSM_HYP, OSM_MEH,      k36,   KC_NO, KC_NO, KC_NO, KC_NO, \
                         k32,   k33,   KC_NO,                 KC_NO, k34,   k35
