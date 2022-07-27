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

#ifdef HRM_ENABLE
#define HR REDPNK       
#else
#define HR WHITE       
#endif

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
