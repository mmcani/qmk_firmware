/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
// #include "os_detection.h"



/*===============================TAP DANCE SETTINGS===============================*/
#if defined(TAP_DANCE_ENABLE)// Tap Dance declarations
enum {
    TD_1_F1,
    TD_2_F2,
    TD_3_F3,
    TD_4_F4,
    TD_5_F5,
    TD_6_F6,
    TD_7_F7,
    TD_8_F8,
    TD_9_F9,
    TD_0_F10,
    TD_MIN_F11,
    TD_EQL_F12,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_1_F1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
    [TD_2_F2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
    [TD_3_F3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
    [TD_4_F4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
    [TD_5_F5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
    [TD_6_F6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),
    [TD_7_F7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7),
    [TD_8_F8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8),
    [TD_9_F9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9),
    [TD_0_F10] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
    [TD_MIN_F11] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_F11),
    [TD_EQL_F12] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_F12),

};

#define KM_1 TD(TD_1_F1)
#define KM_2 TD(TD_2_F2)
#define KM_3 TD(TD_3_F3)
#define KM_4 TD(TD_4_F4)
#define KM_5 TD(TD_5_F5)
#define KM_6 TD(TD_6_F6)
#define KM_7 TD(TD_7_F7)
#define KM_8 TD(TD_8_F8)
#define KM_9 TD(TD_9_F9)
#define KM_10 TD(TD_0_F10)
#define KM_11 TD(TD_MIN_F11)
#define KM_12 TD(TD_EQL_F12)

#else

#define KM_1 KC_1
#define KM_2 KC_2
#define KM_3 KC_3
#define KM_4 KC_4
#define KM_5 KC_5
#define KM_6 KC_6
#define KM_7 KC_7
#define KM_8 KC_8
#define KM_9 KC_9
#define KM_10 KC_0
#define KM_11 KC_MINS
#define KM_12 KC_EQL
#endif // TAP_DANCE_ENABLE
/*===============================TAP DANCE SETTINGS===============================*/



/*====================================KEY MAPS====================================*/
enum layers{
    GAME_BASE = 0,
    WIN_BASE,
    FN1,
    FN2,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP  LGUI(KC_E)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [GAME_BASE] = LAYOUT_ansi_67(
        KC_ESC,  KM_1,     KM_2,     KM_3,    KM_4,    KM_5,    KM_6,    KM_7,    KM_8,    KM_9,    KM_10,    KM_11,    KM_12,    KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,                             KC_SPC,                             KC_RALT,  MO(FN2), MO(FN1), KC_LEFT, KC_DOWN, KC_RGHT),
    [WIN_BASE] = LAYOUT_ansi_67(
        KC_ESC,  KM_1,     KM_2,     KM_3,    KM_4,    KM_5,    KM_6,    KM_7,    KM_8,    KM_9,    KM_10,    KM_11,    KM_12,    KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,                             KC_SPC,                             KC_RALT,  MO(FN2), MO(FN1), KC_LEFT, KC_DOWN, KC_RGHT),

    [FN1] = LAYOUT_ansi_67(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______,           _______,  _______, _______, _______, _______, NK_TOGG, _______, _______, _______,  _______,            _______, _______,
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______),

    [FN2] = LAYOUT_ansi_67(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______, _______,
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [GAME_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [FN1]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [FN2]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE
/*====================================KEY MAPS====================================*/



/*====================================RGB MODS====================================*/
#define FN1_LAYER_COLOR RGB_ORANGE
#define FN2_LAYER_COLOR RGB_SPRINGGREEN

// helper function that sets no trans keys of the layer to the provided color
void rgb_matrix_set_color_by_keycode(uint8_t led_min, uint8_t led_max, uint8_t layer, uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t key_row = 0; key_row < MATRIX_ROWS; ++key_row) {
        for (uint8_t key_col = 0; key_col < MATRIX_COLS; ++key_col) {
            const keypos_t key_position = {key_col, key_row};
            if (keymap_key_to_keycode(layer, key_position) > KC_TRNS) {
                const uint8_t led_index = g_led_config.matrix_co[key_row][key_col];
                RGB_MATRIX_INDICATOR_SET_COLOR(led_index, red, green, blue);
            }
        }
    }
}

// rgb override, adjust colors based on color, fall back to default flags afterward
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t current_layer = get_highest_layer(layer_state|default_layer_state);
    switch (current_layer) {
        case FN1:
            rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, FN1_LAYER_COLOR);
            break;
        case FN2:
            rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, FN2_LAYER_COLOR);
            break;
        case WIN_BASE:
        default:
            if (!rgb_matrix_get_flags()) {  // if no led layers are set, set it to black, else the last led layers  setting will take over
                rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, RGB_OFF);
            }
            break;
    }
    return true;  // api is designed so if return is true it will do further led layers on top of this
}
/*====================================RGB MODS====================================*/
