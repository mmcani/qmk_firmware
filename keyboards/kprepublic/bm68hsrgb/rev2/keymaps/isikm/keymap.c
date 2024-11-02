/* Copyright 2022 bdtc123
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H



/*====================================TAP DANCE====================================*/
#if defined(TAP_DANCE_ENABLE)
// Tap dance example below
enum {
    TD_1_F1,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_1_F1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),  // Tap once for 1, twice for F1 (time defined in config.h as TAPPING_TERM)
};
#define KM_1 TD(TD_1_F1)
#endif // TAP_DANCE_ENABLE
/*====================================TAP DANCE====================================*/



/*====================================LAYERS====================================*/
enum layers {
    BASE = 0,
    FNC1,
    FNC2
};

#define LALT_LB LALT_T(KC_LBRC)
#define RALT_RB RALT_T(KC_RBRC)
#define WN_LOCK LWIN(KC_L)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_65_ansi(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS, KC_DEL,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,           KC_ENT,  KC_PGUP,
        SC_LSPO,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  SC_RSPC, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, LALT_LB,                            KC_SPC,                    RALT_RB, TT(FNC1), TT(FNC2), KC_LEFT, KC_DOWN, KC_RGHT
        ),
    [FNC1]  = LAYOUT_65_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,  _______, KC_MUTE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, KC_VOLU,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, WN_LOCK, _______,  _______,           _______, KC_VOLD,
        _______,          _______, _______, KC_CALC, _______, _______, _______, KC_MYCM, _______, _______,  _______,  _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, TT(FNC1), KC_NO,    KC_MPRV, KC_MPLY, KC_MNXT
        ),
    [FNC2] = LAYOUT_65_ansi(
        _______, KC_BRID, KC_BRIU, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, QK_RBT,  EE_CLR,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
        RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______,  _______,           _______, _______,
        _______,          RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, _______, NK_TOGG, _______, _______, _______,  _______,  _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, KC_NO,    TT(FNC2), _______, _______, _______
        ),
};
/*====================================LAYERS====================================*/



/*====================================RGB MODS====================================*/
#define FN1_LAYER_COLOR RGB_TEAL
#define FN2_LAYER_COLOR RGB_MAGENTA

// helper function that sets no trans keys of the layer to the provided color, trans keys are set to dark
void rgb_matrix_set_color_by_keycode(bool darken_transparents, uint8_t led_min, uint8_t led_max, uint8_t layer, uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t key_row = 0; key_row < MATRIX_ROWS; ++key_row) {
        for (uint8_t key_col = 0; key_col < MATRIX_COLS; ++key_col) {
            const keypos_t key_position = {key_col, key_row};
            uint8_t led_index = g_led_config.matrix_co[key_row][key_col];
            if (keymap_key_to_keycode(layer, key_position) > KC_TRNS) {
                RGB_MATRIX_INDICATOR_SET_COLOR(led_index, red, green, blue);
            } else if (darken_transparents) {
                RGB_MATRIX_INDICATOR_SET_COLOR(led_index, 0, 0, 0);
            }
        }
    }
}

// rgb override, adjust colors based on color, fall back to default flags afterward
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t current_layer = get_highest_layer(layer_state|default_layer_state);
    switch (current_layer) {
        case FNC1:
            rgb_matrix_set_color_by_keycode(true, led_min, led_max, current_layer, FN1_LAYER_COLOR); break;
        case FNC2:
            rgb_matrix_set_color_by_keycode(false, led_min, led_max, current_layer, FN2_LAYER_COLOR); break;
        case BASE:
        default:
            if (!rgb_matrix_get_flags()) {  // if no led layers are set, set it to black, else don't base drivers will take over
                rgb_matrix_set_color_by_keycode(true, led_min, led_max, current_layer, RGB_OFF);
            }
            break;
    }
    return true;  // api is designed so if return is true it will do further led layers on top of this
}
/*====================================RGB MODS====================================*/