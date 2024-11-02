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


/*====================================UNICODE====================================*/
enum unicode_names {
    turkish_s,
    turkish_s_upper,

    turkish_c,
    turkish_c_upper,

    turkish_i,
    turkish_i_upper,

    turkish_g,
    turkish_g_upper,

    turkish_o,
    turkish_o_upper,

    turkish_u,
    turkish_u_upper,
};

const uint32_t unicode_map[] PROGMEM = {
    [turkish_s]  = 0x015F,          // ş
    [turkish_s_upper] = 0x015E,     // Ş
    [turkish_c]  = 0x00E7,          // ç
    [turkish_c_upper] = 0x00C7,     // Ç
    [turkish_i] = 0x0131,           // ı
    [turkish_i_upper] = 0x0130,     // İ
    [turkish_g] = 0x011F,           // ğ
    [turkish_g_upper] = 0x011E,     // Ğ
    [turkish_o] = 0x00F6,           // ö
    [turkish_o_upper] = 0x00D6,     // Ö
    [turkish_u] = 0x00FC,           // ü
    [turkish_u_upper] = 0x00DC,     // Ü
};

#define K_Tur_S XP(turkish_s, turkish_s_upper)
#define K_Tur_C XP(turkish_c, turkish_c_upper)
#define K_Tur_I XP(turkish_i, turkish_i_upper)
#define K_Tur_G XP(turkish_g, turkish_g_upper)
#define K_Tur_O XP(turkish_o, turkish_o_upper)
#define K_Tur_U XP(turkish_u, turkish_u_upper)
/*====================================UNICODE====================================*/



/*===============================TAP DANCE SETTINGS===============================*/
#if defined(TAP_DANCE_ENABLE)// Tap Dance declarations

enum {
    // numbers function keys
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

#define KM_S TD(TH_S)
#define KM_C TD(TH_C)
#define KM_I TD(TH_I)
#define KM_G TD(TH_G)
#define KM_O TD(TH_O)
#define KM_U TD(TH_U)


#endif // TAP_DANCE_ENABLE
/*===============================TAP DANCE SETTINGS===============================*/



/*====================================KEY MAPS====================================*/
enum layers{
    GAME_BASE = 0,
    WIN_BASE,
    RGB_MEDIA,
    FUNCTIONS,
};

#define LALT_LB LALT_T(KC_LBRC)
#define RALT_RB RALT_T(KC_RBRC)
#define KC_TERM LCA(KC_T)
#define K_MEDIA TT(RGB_MEDIA)
#define K_FUNC TT(FUNCTIONS)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [GAME_BASE] = LAYOUT_ansi_67(
        KC_ESC,  KM_1,     KM_2,     KM_3,    KM_4,    KM_5,    KM_6,    KM_7,    KM_8,    KM_9,    KM_10,    KM_11,    KM_12,    KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_HOME,
        SC_LSPO,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            SC_RSPC, KC_UP,
        KC_LCTL, KC_LWIN,  LALT_LB,                             KC_SPC,                             RALT_RB,  K_FUNC,   K_MEDIA,  KC_LEFT, KC_DOWN, KC_RGHT),
    [WIN_BASE] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_HOME,
        SC_LSPO,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            SC_RSPC, KC_UP,
        KC_LCTL, KC_LWIN,  LALT_LB,                             KC_SPC,                             RALT_RB,  K_FUNC,   K_MEDIA,  KC_LEFT, KC_DOWN, KC_RGHT),

    [RGB_MEDIA] = LAYOUT_ansi_67(
        KC_GRV,  KC_BRID,  KC_BRIU,  _______, _______, _______, _______, _______, _______, _______, KC_MPRV,  KC_MPLY,  KC_MNXT,  _______,          KC_MUTE,
        RGB_TOG, _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_HUI,  RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______,           RGB_RMOD, RGB_HUD, RGB_SAD, RGB_SPD, _______, NK_TOGG, _______, _______, _______,  _______,            _______, _______,
        _______, _______,  _______,                             _______,                            _______,  KC_NO,    K_MEDIA,  _______, _______, _______),

    [FUNCTIONS] = LAYOUT_ansi_67(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          C(KC_0),
        _______, _______,  _______,  _______, _______, KC_TERM, _______, K_Tur_U, K_Tur_I, K_Tur_O, _______,  _______,  _______,  _______,          KC_PAGE_UP,
        _______, _______,  K_Tur_S,  _______, _______, K_Tur_G, _______, _______, _______, _______, _______,  _______,            _______,          KC_PAGE_DOWN,
        _______,           _______,  _______, K_Tur_C, _______, _______, _______, KC_MYCM, _______, _______,  _______,            _______, KC_HOME,
        _______, _______,  _______,                             _______,                            _______,  K_FUNC,   KC_NO,    _______, KC_END,  _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [GAME_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [RGB_MEDIA] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [FUNCTIONS] = { ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL))},
};
#endif // ENCODER_MAP_ENABLE
/*====================================KEY MAPS====================================*/



/*====================================RGB MODS====================================*/
#define RGB_LAYER_COLOR RGB_ORANGE
#define FUNC_LAYER_COLOR RGB_SPRINGGREEN

// helper function that sets no trans keys of the layer to the provided color, trans keys are set turned off
void rgb_matrix_set_color_by_keycode(uint8_t led_min, uint8_t led_max, uint8_t layer, uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t key_row = 0; key_row < MATRIX_ROWS; ++key_row) {
        for (uint8_t key_col = 0; key_col < MATRIX_COLS; ++key_col) {
            if (keymap_key_to_keycode(layer, (keypos_t){key_col, key_row}) > KC_TRNS) {
                RGB_MATRIX_INDICATOR_SET_COLOR(g_led_config.matrix_co[key_row][key_col], red, green, blue);
            } else {
                RGB_MATRIX_INDICATOR_SET_COLOR(g_led_config.matrix_co[key_row][key_col], 0, 0, 0);
            }
        }
    }
}

// rgb override, adjust colors based on color, fall back to default flags afterward
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t current_layer = get_highest_layer(layer_state|default_layer_state);
    switch (current_layer) {
        case RGB_MEDIA:
            rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, RGB_LAYER_COLOR);
            break;
        case FUNCTIONS:
            rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, FUNC_LAYER_COLOR);
            break;
        case WIN_BASE:
        case GAME_BASE:
        default:
            if (!rgb_matrix_get_flags()) {  // if no led layers are set, set it to black, else the last led layers setting will take over
                rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, RGB_OFF);
            }
            break;
    }
    return true;  // api is designed so if return is true it will do further led layers on top of this, that way handling of caps lock etc.. takes priority
}
/*====================================RGB MODS====================================*/



/*====================================TAP DANCE====================================*/