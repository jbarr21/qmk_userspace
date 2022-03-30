#include QMK_KEYBOARD_H

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

// colors
#define ____           {0,0,0}
#define BLUE     {154,255,255}
#define RED_PNK  {249,228,255}
#define GREEN    {105,255,255}
#define YELLOW   { 35,255,255}
#define ORANGE   { 14,255,255}
#define PURPLE   {206,255,255}
#define GRAY     {  0,  0,183}
#define RED      {  0,255,255}

// left then right hand, top to bottom moving inward
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = {
      ____, BLUE, BLUE, ORANGE, ____,
      ____, BLUE, RED_PNK, BLUE, ____,
      ____, BLUE, RED_PNK, BLUE, ____,
      ____, BLUE, RED_PNK, BLUE, ____,
      ____, BLUE, RED_PNK, BLUE, GREEN,
      ____, BLUE, BLUE, BLUE,
      ____, ____, ____,
      BLUE, BLUE, ____,
      YELLOW,
      ____, BLUE, BLUE, YELLOW, ____,
      ____, BLUE, RED_PNK, BLUE, ____,
      ____, BLUE, RED_PNK, BLUE, ____,
      ____, BLUE, RED_PNK, BLUE, ____,
      ____, BLUE, RED_PNK, BLUE, PURPLE,
      ____, BLUE, BLUE, BLUE,
      ____, ____, ____,
      BLUE, ORANGE, ____,
      GREEN
    },

    [1] = {
      ____, ____, ____, ____, ____,
      ____, ____, RED_PNK, ORANGE, ____,
      ____, ____, RED_PNK, ORANGE, ____,
      ____, ____, RED_PNK, ORANGE, ____,
      ____, ____, RED_PNK, ORANGE, ____,
      ____, ____, ____, ____,
      ____, ____, ____,
      ____, ____, ____,
      YELLOW,
      ____, ____, ____, YELLOW, ____,
      ____, YELLOW, GREEN, BLUE, ____,
      ____, YELLOW, GREEN, BLUE, ____,
      ____, YELLOW, GREEN, BLUE, ____,
      ____, YELLOW, GREEN, BLUE, ____,
      ____, ____, ____, ____,
      ____, ____, ____,
      YELLOW, GREEN, ____,
      GREEN
    },

    [2] = {
      ____, ____, ____, ____, ____,
      ____, GREEN, RED_PNK, YELLOW, ____,
      ____, GREEN, RED_PNK, YELLOW, ____,
      ____, GREEN, RED_PNK, YELLOW, ____,
      ____, GREEN, RED_PNK, YELLOW, ____,
      ____, ORANGE, ORANGE, ORANGE,
      ____, ____, ____,
      YELLOW, ____, ____,
      ____,
      ____, ____, ____, YELLOW, ____,
      ____, YELLOW, BLUE, BLUE, ____,
      ____, GREEN, GREEN, GREEN, ____,
      ____, GREEN, GREEN, GREEN, ____,
      ____, GREEN, GREEN, GREEN, GREEN,
      ____, YELLOW, BLUE, BLUE,
      ____, ____, ____,
      YELLOW, RED_PNK, ____,
      ____
    },

    [3] = {
      ____, ____, ____, ____, ____,
      ____, ____, RED_PNK, ____, ____,
      ____, ____, RED_PNK, ____, ____,
      ____, ____, RED_PNK, ____, ____,
      ____, ____, RED_PNK, ____, ____,
      ____, ____, ____, ____,
      ____, ____, ____,
      ____, ____, ____,
      ____,
      ____, ____, ____, YELLOW, ____,
      ____, YELLOW, GREEN, BLUE, ____,
      ____, YELLOW, GREEN, BLUE, ____,
      ____, YELLOW, GREEN, BLUE, ____,
      ____, YELLOW, GREEN, BLUE, ____,
      ____, ____, ORANGE, ____,
      ____, ____, ____,
      GREEN, GREEN, ____,
      ____
    },

    [4] = {
      ____, ____, ____, ____, ____,
      ____, BLUE, RED_PNK, BLUE, ____,
      ____, BLUE, RED_PNK, BLUE, ____,
      ____, BLUE, RED_PNK, BLUE, ____,
      ____, BLUE, RED_PNK, BLUE, ____,
      ____, BLUE, BLUE, BLUE,
      ____, ____, ____,
      ORANGE, ____, ____,
      ____,
      ____, ____, ____, YELLOW, ____,
      ____, BLUE, RED_PNK, BLUE, ____,
      ____, BLUE, RED_PNK, BLUE, ____,
      ____, BLUE, RED_PNK, BLUE, ____,
      ____, BLUE, RED_PNK, BLUE, ____,
      ____, BLUE, BLUE, BLUE,
      ____, ____, ____,
      ____, ____, ____,
      ____
    },

    [5] = {
      ____, ____, ____, ____, ____,
      ____, ____, RED_PNK, ____, ____,
      ____, ____, RED_PNK, ____, ____,
      ____, ____, RED_PNK, ____, ____,
      ____, ____, RED_PNK, ____, ____,
      ____, ____, ____, ____,
      ____, ____, ____,
      ____, ____, ____,
      ____,
      ____, ORANGE, ORANGE, ORANGE, ____,
      ____, ORANGE, ORANGE, ORANGE, ____,
      ____, YELLOW, YELLOW, YELLOW, ____,
      ____, YELLOW, YELLOW, YELLOW, ____,
      ____, YELLOW, YELLOW, YELLOW, ____,
      ____, ____, ____, ____,
      ____, ____, ____,
      ____, ____, ____,
      ____
    },

    [6] = {
      ____, GRAY, ____, ____, ____,
      ____, ____, PURPLE, PURPLE, ____,
      ____, ____, PURPLE, PURPLE, ____,
      ____, ____, PURPLE, PURPLE, ____,
      ____, ____, PURPLE, PURPLE, RED_PNK,
      ____, ____, ____, PURPLE,
      ____, ____, ____,
      YELLOW, GREEN, ____,
      ____,
      ____, RED, ____, YELLOW, ____,
      ____, ____, ____, ____, ____,
      ____, ____, GREEN, ____, ____,
      ____, GREEN, GREEN, ____, ____,
      ____, ____, GREEN, ____, ____,
      ____, ____, ____, ____,
      ____, ____, ____,
      ____, ____, ____,
      ____
    },

    [7] = {
      ____, ____, ____, ____, ____,
      ____, ____, ____, ____, ____,
      ____, ____, ____, ____, ____,
      ____, ____, ____, ____, ____,
      ____, ____, ____, ____, ____,
      ____, ____, ____, ____,
      ____, ____, ____,
      ____, ____, ____,
      ____,
      ____, ____, ____, ____, ____,
      ____, ____, ____, ____, ____,
      ____, ____, ____, ____, ____,
      ____, GRAY, ____, ____, ____,
      ____, ____, ____, ____, ____,
      ____, ____, ____, ____,
      ____, ____, ____,
      ____, ____, ____,
      ____
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
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
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
