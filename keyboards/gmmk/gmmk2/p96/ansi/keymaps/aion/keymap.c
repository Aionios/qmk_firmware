/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any lazzer version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *asdsdSSSS
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <color.h>
#include QMK_KEYBOARD_H

#define INDICATOR_COLOR RGB_CP_FROSTBITE


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
enum custom_layers {
    _BL,
    _FL,
    _ML,
};

enum my_keycodes {
  TBE_KEY = SAFE_RANGE, // Toggle basic/dark effect
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
   */
[_BL] = LAYOUT(
  KC_GESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   KC_INS,   KC_PGUP,  KC_PGDN,
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,   KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,   KC_P4,    KC_P5,    KC_P6,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_P1,    KC_P2,    KC_P3,    KC_PENT,
  KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(_FL),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT),

  /* Keymap _FL: Function Layer
   */
[_FL] = LAYOUT(
    QK_BOOT,  KC_MYCM,  KC_WHOM,  KC_CALC,  KC_MSEL,  KC_MPRV,  KC_MRWD,  KC_MPLY,  KC_MSTP,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,
  _______,  RGB_HUI,  RGB_HUD,  RGB_SPD,  RGB_SPI,  _______,  _______,  _______,  DM_REC1,  DM_PLY1,  DM_RSTP,  _______,   RGB_VAI,  _______,  _______,  _______,  _______,
	_______,  UC_M_WI,  _______,                      _______,                                TBE_KEY,  _______,  TG(_ML), RGB_RMOD,   RGB_VAD,  RGB_MOD,  _______,  _______),

  /* Keymap _ML: Mouse Layer
   */
[_ML] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  KC_MS_U,  KC_WH_U,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,
  KC_BTN2,  _______,  _______,  KC_WH_D,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   XXXXXXX,  _______,  _______,  _______,  _______,
	KC_BTN3,  _______,  _______,                      KC_BTN1,                                _______,  _______,  TG(_ML), XXXXXXX,   XXXXXXX,  XXXXXXX,  _______,  _______)
};


void keyboard_post_init_user(void) {
  // Call the post init code.
  rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_basic_dark_effect); // sets mode to custom
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TBE_KEY:
      if (!record->event.pressed) { // Change when release
        if (RGB_MATRIX_CUSTOM_basic_solid_effect != rgb_matrix_get_mode()) {
          rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_basic_solid_effect);
        } else {
          rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_basic_dark_effect);
        }

      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  static uint8_t s_rgb_previous_mode = RGB_MATRIX_CUSTOM_basic_dark_effect;
  static bool lock_previsou_mode = false;
  switch (get_highest_layer(state)) {
  case _ML:
    if (!lock_previsou_mode) {
      s_rgb_previous_mode = rgb_matrix_get_mode();
      lock_previsou_mode = true;
    }
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_mouse_layer_effect);
      break;
    default: //  for any other layers, or the default layer
      lock_previsou_mode = false;
      if (RGB_MATRIX_CUSTOM_mouse_layer_effect == rgb_matrix_get_mode())
        rgb_matrix_mode_noeeprom(s_rgb_previous_mode);
     break;
  }
  return state;
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    led_t led_state = host_keyboard_led_state();
    uint8_t rgb_mode = rgb_matrix_get_mode();
    if (rgb_mode == RGB_MATRIX_CUSTOM_basic_solid_effect ||
        rgb_mode == RGB_MATRIX_CUSTOM_basic_dark_effect) {
        if (led_state.caps_lock) {
          // Caps Lock key = 54
          rgb_matrix_set_color(54, INDICATOR_COLOR);
        } else {
          if (rgb_mode == RGB_MATRIX_CUSTOM_basic_solid_effect)
            rgb_matrix_set_color(54, BASIC_EFFECT_COLOR);
          else // dark
            rgb_matrix_set_color(54, RGB_BLACK);
        }
        if (led_state.num_lock) {
          // Num Lock key = 32
          rgb_matrix_set_color(32, INDICATOR_COLOR);
        } else {
          if (rgb_mode == RGB_MATRIX_CUSTOM_basic_solid_effect)
            rgb_matrix_set_color(32, BASIC_EFFECT_COLOR);
          else // dark
            rgb_matrix_set_color(32, RGB_BLACK);
        }
    } // else do nothing

}
