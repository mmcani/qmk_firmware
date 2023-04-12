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

#include "os_detection.h"

// clang-format off

enum layers{
    MAC_BASE,
    WIN_BASE,
    _FN1,
    _FN2,
    _FN3
};

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

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define FN1_LAYER_COLOR RGB_ORANGE
#define FN2_LAYER_COLOR RGB_PURPLE


void rgb_matrix_set_color_by_keycode(uint8_t led_min, uint8_t led_max, uint8_t layer, uint8_t red, uint8_t green, uint8_t blue) {
    if (get_highest_layer(layer_state) > 0) {
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];
                if (index >= led_min && index < led_max && index != NO_LED
                    && keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, red, green, blue);
                }
            }
        }
    }
}


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t current_layer = get_highest_layer(layer_state);
    switch (current_layer) {
        case _FN2:
            rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, FN1_LAYER_COLOR);
            break;
        case _FN3:
            rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, FN2_LAYER_COLOR);
            break;
        case MAC_BASE:
        case WIN_BASE:
        default:
            rgb_matrix_set_color_all(RGB_OFF);
            break;
    }

    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 255, 0, 0);
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 0, 0, 0);
    }
    return false;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_67(
        KC_ESC,  KM_1,     KM_2,     KM_3,    KM_4,    KM_5,    KM_6,    KM_7,    KM_8,    KM_9,    KM_10,    KM_11,    KM_12,    KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LOPT,  KC_LCMD,                             KC_SPC,                             KC_RCMD,  MO(_FN1), MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_67(
        KC_ESC,  KM_1,     KM_2,     KM_3,    KM_4,    KM_5,    KM_6,    KM_7,    KM_8,    KM_9,    KM_10,    KM_11,    KM_12,    KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,                             KC_SPC,                             KC_RALT,  MO(_FN2), MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN1] = LAYOUT_ansi_67(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_NO,   KC_NO,   RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______,           _______,  _______, _______, _______, _______, NK_TOGG, _______, _______, _______,  _______,            _______, _______,
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______),

    [_FN2] = LAYOUT_ansi_67(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______,           _______,  _______, _______, _______, _______, NK_TOGG, _______, _______, _______,  _______,            _______, _______,
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______),

    [_FN3] = LAYOUT_ansi_67(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______, _______,
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN1]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_FN2]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_FN3]   = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI)}
};
#endif // ENCODER_MAP_ENABLE
