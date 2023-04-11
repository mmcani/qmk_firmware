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

enum layers {
    BASE = 0,
    FNC,
    FNC2
};

enum my_keycodes {
    // RGB Keys
    RM_TOGG = SAFE_RANGE,   // Toggle RGB Backlight
    RM_MOD,                 // Switch the next RGB mode
    RM_HUI,                 // increase RGB hue
    RM_HUD,                 // decrease RGB hue
    RM_SAI,                 // increase saturation
    RM_SAD,                 // decrease saturation
    RM_VAI,                 // increase brightness
    RM_VAD,                 // decrease brightness
    SIZE_RM_KEYS
};


typedef void ( * const void_fnc_ptr )(void);
static const void_fnc_ptr key_to_funcs[] PROGMEM = {  // mapping of functions to keys
    &rgb_matrix_toggle,
    &rgb_matrix_step,
    &rgb_matrix_increase_hue,
    &rgb_matrix_decrease_hue,
    &rgb_matrix_increase_sat,
    &rgb_matrix_decrease_sat,
    &rgb_matrix_increase_val,
    &rgb_matrix_decrease_val,
};

bool handle_rgb_matrix_keys(uint16_t keycode, const keyrecord_t *record) {
    if (keycode >= SIZE_RM_KEYS) {
        return false;
    }

    if (record->event.pressed) {
        key_to_funcs[keycode]();
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (handle_rgb_matrix_keys(keycode, record)) {
        return false;  // stop further processing
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_65_ansi(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS, KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,           KC_ENT,  KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(FNC),  MO(FNC2), KC_LEFT, KC_DOWN, KC_RGHT
        ),
    [FNC]  = LAYOUT_65_ansi(
        QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,  KC_DEL,  QK_BOOT,
        _______, RM_TOGG, RM_MOD,  RM_HUI,  RM_HUD,  RM_SAI,  RM_SAD,  RM_VAI,  RM_VAD,  _______, _______,  _______,  _______, _______, _______,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,           _______, _______,
        _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______,  _______,  _______, KC_VOLU, _______,
        _______, _______, _______,                            _______,                   _______, _______,  _______,  _______, KC_VOLD, _______
        ),
    [FNC2] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,           _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______,  _______,  _______, _______, _______
        ),
};
