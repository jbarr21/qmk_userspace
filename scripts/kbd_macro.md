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

 #define RGB_DEF \
     ______, ______, ______, ______, ______, ______,    ______, ______, ______, ______, ______, ______, \
     ______, REDPNK, REDPNK, REDPNK, WHITE,  ______,    ______, WHITE,  ______, ______, PURPLE, ______, \
     ______, ______, ______, ______, ______, ______,    ______, ______, ______, ______, ______, ______, \
                             RED,    YELLOW, GREEN,     GREEN,  YELLOW, RED

// #define RGB_LAYER C_RGB_ML(RGB_DEF)

  // [0] = { RGB_moonlander_w(RGB_LAYER) },