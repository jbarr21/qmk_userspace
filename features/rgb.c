#include QMK_KEYBOARD_H

//extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

// colors (HSV)
#define ___            {0,0,0}
#define ______         {0,0,0}
#define BLUE     {154,255,255}
#define REDPNK   {249,228,255}
#define GREEN    {105,255,255}
#define YELLOW   { 35,255,255}
#define ORANGE   { 14,255,255}
#define PURPLE   {206,255,255}
#define GRAY     {  0,  0,183}
#define WHITE    {  0,  0,255}
#define RED      {  0,255,255}

#ifndef HRM_DISABLE
#define HR REDPNK       
#else
#define HR WHITE       
#endif

/* fold
#define RGB_DEF \
    ______, ______, ______, ______, ______, ______,    ______, ______, ______, ______, ______, ______, \
    ______, REDPNK, REDPNK, REDPNK, WHITE,  ______,    ______, WHITE,  ______, ______, PURPLE, ______, \
    ______, ______, ______, ______, ______, ______,    ______, ______, ______, ______, ______, ______, \
                            RED,    YELLOW, GREEN,     GREEN,  YELLOW, RED

#define RGB_moonlander_w(...)  RGB_moonlander(__VA_ARGS__)
#define C_RGB_ML(k) SPLIT_42_TO_ML_RGB(k)
#define SPLIT_42_TO_ML_RGB( \
    k01, k02, k03, k04, k05, k06,    k07, k08, k09, k10, k11, k12, \
    k13, k14, k15, k16, k17, k18,    k19, k20, k21, k22, k23, k24, \
    k25, k26, k27, k28, k29, k30,    k31, k32, k33, k34, k35, k36, \
                   k37, k38, k39,    k40, k41, k42 \
) \
    ___, k01, k13, k25, ___, \
    ___, k02, k14, k26, ___, \
    ___, k03, k15, k27, ___, \
    ___, k04, k16, k28, ___, \
    ___, k05, k17, k29, k37, \
    ___, k06, k18, k30       \
    ___, ___, ___,           \
    k38, k39, ___,           \
    YELLOW,                  \
    ___, k12, k24, k36, ___, \
    ___, k11, k23, k35, ___, \
    ___, k10, k22, k34, ___, \
    ___, k09, k21, k33, ___, \
    ___, k08, k20, k32, k42, \
    ___, k07, k19, k31,      \
    ___, ___, ___,           \
    k41, k40, ___,           \
    GREEN
    */

// #define DEF RED, GREEN, BLUE, WHITE
// #define DEF "RED", "GREEN", "BLUE", "WHITE"
// #define REV_w(...)      REV(__VA_ARGS__)
// #define REV(a, b, c, d) d, c, b, a
// const uint8_t PROGMEM3 ledmap[DRIVER_LED_TOTAL][3] = { REV_w(DEF) }

// #define DEF RED, GREEN, BLUE, WHITE
// #define REV_w(...) REV(__VA_ARGS__)
// #define REV(a, b, c, d) d, c, b, a
//
// // Reverse the order of the defines
// #define REV_DEF REV_w(DEF)
// const uint8_t PROGMEM2 ledmap[DRIVER_LED_TOTAL][3] = { REV_DEF }


// left then right hand, top to bottom moving inward
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    // DEF
    [0] = {
      ______, BLUE, BLUE, GREEN, ______, \
      ______, BLUE, HR,   BLUE, ______, \
      ______, BLUE, HR,   BLUE, ______, \
      ______, BLUE, HR,   BLUE, ______, \
      ______, BLUE, HR,   BLUE, RED, \
      ______, BLUE, BLUE, BLUE, \
      ______, ______, ______, \
      BLUE, BLUE, ______, \
      YELLOW, \
      ______, BLUE, BLUE, PURPLE, ______, \
      ______, BLUE, HR,   BLUE, ______, \
      ______, BLUE, HR,   BLUE, ______, \
      ______, BLUE, HR,   BLUE, ______, \
      ______, BLUE, HR,   BLUE, GREEN, \
      ______, BLUE, BLUE, BLUE, \
      ______, ______, ______, \
      BLUE, ORANGE, ______, \
      GREEN
    },

    // SYM
    [1] = {
      ______, ______, ______, ______, ______,
      ______, BLUE, BLUE, BLUE, ______,
      ______, BLUE, BLUE, BLUE, ______,
      ______, BLUE, BLUE, BLUE, ______,
      ______, BLUE, BLUE, BLUE, ______,
      ______, BLUE, BLUE, BLUE,
      ______, ______, ______,
      ______, ______, ______,
      ______,
      ______, ______, ______, YELLOW, ______,
      ______, BLUE, REDPNK, BLUE, ______,
      ______, BLUE, REDPNK, BLUE, ______,
      ______, BLUE, REDPNK, BLUE, ______,
      ______, BLUE, REDPNK, BLUE, ______,
      ______, BLUE, BLUE, BLUE,
      ______, ______, ______,
      ______, ______, ______,
      ______
    },
    
    // NAV
    [2] = {
      ______, ______, ______, ______, ______,
      ______, GREEN, REDPNK, BLUE, ______,
      ______, GREEN, REDPNK, BLUE, ______,
      ______, GREEN, REDPNK, BLUE, ______,
      ______, GREEN, REDPNK, BLUE, ______,
      ______, ORANGE, ORANGE, ORANGE,
      ______, ______, ______,
      ______, ______, ______,
      YELLOW,
      ______, ______, ______, YELLOW, ______,
      ______, YELLOW, GREEN, BLUE, ______,
      ______, YELLOW, GREEN, BLUE, ______,
      ______, YELLOW, GREEN, BLUE, ______,
      ______, YELLOW, GREEN, BLUE, ______,
      ______, ______, ORANGE, ______,
      ______, ______, ______,
      ______, ______, ______,
      GREEN
    },

    // NUM
    [3] = {
      ______, ______, ______, ______, ______,
      ______, ______, REDPNK, ______, ______,
      ______, ______, REDPNK, ______, ______,
      ______, ______, REDPNK, ______, ______,
      ______, ______, REDPNK, YELLOW, ______,
      ______, ______, ______, ______,
      ______, ______, ______,
      ______, ______, ______,
      YELLOW,
      ______, ______, ______, YELLOW, ______,
      ______, ______, ______, ______, ______,
      ______, GREEN, GREEN, GREEN, ______,
      ______, GREEN, GREEN, GREEN, ______,
      ______, GREEN, GREEN, GREEN, GREEN,
      ______, ______, ______, ______,
      ______, ______, ______,
      YELLOW, REDPNK, ______,
      GREEN

    /* Callum NUM   
      ______, ______, ______, ______, ______,
      ______, GREEN, REDPNK, YELLOW, ______,
      ______, GREEN, REDPNK, YELLOW, ______,
      ______, GREEN, REDPNK, YELLOW, ______,
      ______, GREEN, REDPNK, YELLOW, ______,
      ______, GREEN, ORANGE, YELLOW,
      ______, ______, ______,
      ______, ______, ______,
      ______,
      ______, ______, ______, YELLOW, ______,
      ______, GREEN, REDPNK, YELLOW, ______,
      ______, GREEN, REDPNK, YELLOW, ______,
      ______, GREEN, REDPNK, YELLOW, ______,
      ______, GREEN, REDPNK, YELLOW, ______,
      ______, GREEN, ORANGE, YELLOW,
      ______, ______, ______,
      ______, ______, ______,
      ______
    */
    },

    // FUN
    [4] = {
      ______, ______, ______, ______, ______,
      ______, ______, REDPNK, ______, ______,
      ______, ______, REDPNK, ______, ______,
      ______, ______, REDPNK, ______, ______,
      ______, ______, REDPNK, ______, ______,
      ______, ______, ______, ______,
      ______, ______, ______,
      ______, ______, ______,
      YELLOW,
      ______, ______, ______, YELLOW, ______,
      ______, ORANGE, ORANGE, ORANGE, ______,
      ______, YELLOW, YELLOW, YELLOW, ______,
      ______, YELLOW, YELLOW, YELLOW, ______,
      ______, YELLOW, YELLOW, YELLOW, ______,
      ______, ORANGE, ORANGE, ORANGE,
      ______, ______, ______,
      ______, ______, ______,
      GREEN
    },

    // IDE
    [5] = {
      ______, RED, ______, ______, ______,
      ______, ______, PURPLE, PURPLE, ______,
      ______, ______, ______, PURPLE, ______,
      ______, ______, PURPLE, PURPLE, ______,
      ______, ______, PURPLE, PURPLE, REDPNK,
      ______, ______, ______, PURPLE,
      ______, ______, ______,
      YELLOW, GREEN, ______,
      ______,
      ______, RED, ______, YELLOW, ______,
      ______, ______, ______, ______, ______,
      ______, ______, GREEN, ______, ______,
      ______, GREEN, GREEN, ______, ______,
      ______, ______, GREEN, ______, ______,
      ______, ______, ______, ______,
      ______, ______, ______,
      ______, ______, ______,
      ______
    },

    // MOU
    [6] = {
      ______, ______, ______, ______, ______,
      ______, ______, REDPNK, ______, ______,
      ______, ______, REDPNK, ______, ______,
      ______, ______, REDPNK, ______, ______,
      ______, ______, REDPNK, ______, ______,
      ______, ______, ______, ______,
      ______, ______, ______,
      ______, ______, ______,
      ______,
      ______, ______, ______, YELLOW, ______,
      ______, ______, GREEN, BLUE, ______,
      ______, ______, GREEN, BLUE, ______,
      ______, ______, GREEN, BLUE, ______,
      ______, ______, GREEN, BLUE, ______,
      ______, ______, ORANGE, ______,
      ______, ______, ______,
      GREEN, GREEN, ______,
      ______
    },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (/*g_suspend_state ||*/ keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}
