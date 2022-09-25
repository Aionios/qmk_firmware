// !!! DO NOT ADD #pragma once !!! //
#define RGB_CP_WISTERIA         0xBF, 0x98, 0xD1
#define RGB_CP_PAISINBLACK      0x27, 0x29, 0x32
#define RGB_CP_BLOODRED         0x71, 0x0, 0x0
#define RGB_CP_RICHLEMON        0xFD, 0xF5, 0x0
#define RGB_CP_KEPPEL           0x1A, 0xC5, 0xB0
#define RGB_CP_ELECTRICBLUE     0x37, 0xEB, 0xF3
#define RGB_CP_BLUSHINGPURPLE   0x93, 0x70, 0xDB
#define RGB_CP_FROSTBITE        0xE5, 0x55, 0xAE
#define RGB_CP_STEELPINK        0xCB, 0x1D, 0xCD
#define RGB_CP_PALESILVER       0xD1, 0xC5, 0xC0

#define BASIC_EFFECT_COLOR     RGB_CP_ELECTRICBLUE
// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(basic_solid_effect)
RGB_MATRIX_EFFECT(basic_dark_effect)
RGB_MATRIX_EFFECT(mouse_layer_effect)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// e.g: A simple effect, self-contained within a single method
static void gradient_side_bar(void)
{
    // left side
    rgb_matrix_set_color(99, 0xBF, 0x98, 0xD1);
    rgb_matrix_set_color(100, 0xDF, 0x96, 0xD1);
    rgb_matrix_set_color(101, 0xFF, 0x94, 0xC9);
    rgb_matrix_set_color(102, 0xFF, 0x93, 0xB8);
    rgb_matrix_set_color(103, 0xFF, 0x97, 0xA1);
    rgb_matrix_set_color(104, 0xFF, 0xA1, 0x86);
    rgb_matrix_set_color(105, 0xFF, 0xB1, 0x67);
    rgb_matrix_set_color(106, 0xFF, 0xC6, 0x48);
    rgb_matrix_set_color(107, 0xFF, 0xDD, 0x25);
    rgb_matrix_set_color(108, 0xFD, 0xF5, 0x0);
    // right side
    rgb_matrix_set_color(109, 0xBF, 0x98, 0xD1);
    rgb_matrix_set_color(110, 0xDF, 0x96, 0xD1);
    rgb_matrix_set_color(111, 0xFF, 0x94, 0xC9);
    rgb_matrix_set_color(112, 0xFF, 0x93, 0xB8);
    rgb_matrix_set_color(113, 0xFF, 0x97, 0xA1);
    rgb_matrix_set_color(114, 0xFF, 0xA1, 0x86);
    rgb_matrix_set_color(115, 0xFF, 0xB1, 0x67);
    rgb_matrix_set_color(116, 0xFF, 0xC6, 0x48);
    rgb_matrix_set_color(117, 0xFF, 0xDD, 0x25);
    rgb_matrix_set_color(118, 0xFD, 0xF5, 0x0);
}

static bool basic_solid_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  for (int i = 0; i < 13; ++i) {
    rgb_matrix_set_color(i, RGB_CP_RICHLEMON);   // Esc, F1 ~ F12
  }
  rgb_matrix_set_color(13, BASIC_EFFECT_COLOR); // Print Screen
  rgb_matrix_set_color(14, RGB_CP_BLOODRED);    // Del
  for (int i = 15; i < 18; ++i) {
    rgb_matrix_set_color(i, BASIC_EFFECT_COLOR);
  }
  for (int i = 18; i < 31; ++i) {
    rgb_matrix_set_color(i, RGB_CP_WISTERIA);   // num, -, =
  }
  for (int i = 31; i < 88; ++i) {
    rgb_matrix_set_color(i, BASIC_EFFECT_COLOR);
  }
  rgb_matrix_set_color(88, RGB_CP_PALESILVER);  // Win
  rgb_matrix_set_color(89, BASIC_EFFECT_COLOR);
  rgb_matrix_set_color(90, BASIC_EFFECT_COLOR);
  rgb_matrix_set_color(91, BASIC_EFFECT_COLOR);
  rgb_matrix_set_color(92, RGB_CP_PALESILVER);  // Fn
  for (int i = 93; i < 99; ++i) {
    rgb_matrix_set_color(i, BASIC_EFFECT_COLOR);
  }
  gradient_side_bar();
  return rgb_matrix_check_finished_leds(led_max);
}

static bool basic_dark_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  rgb_matrix_set_color_all(RGB_BLACK);           // set all to azure
  rgb_matrix_set_color(14, RGB_CP_BLOODRED);     // Set Del to dark red
  rgb_matrix_set_color(88, RGB_CP_RICHLEMON);     // Win
  rgb_matrix_set_color(92, RGB_CP_RICHLEMON);     // Fn
  return rgb_matrix_check_finished_leds(led_max);
}

static bool mouse_layer_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  rgb_matrix_set_color_all(RGB_BLACK);
  rgb_matrix_set_color(38, RGB_CP_RICHLEMON);  // W
  rgb_matrix_set_color(55, RGB_CP_RICHLEMON);  // A
  rgb_matrix_set_color(56, RGB_CP_RICHLEMON);  // S
  rgb_matrix_set_color(57, RGB_CP_RICHLEMON);  // D
  rgb_matrix_set_color(39, RGB_CP_WISTERIA);   // E
  rgb_matrix_set_color(73, RGB_CP_WISTERIA);   // C
  rgb_matrix_set_color(70, RGB_CP_STEELPINK);  // SHIFT_L
  rgb_matrix_set_color(87, RGB_CP_STEELPINK);  // CTRL_L
  rgb_matrix_set_color(90, RGB_CP_STEELPINK);  // SPACE
  rgb_matrix_set_color(93, RGB_CP_ELECTRICBLUE); // CTRL_R (Toggle moouse mode)
  return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
