#include QMK_KEYBOARD_H

/*====================================KEY MAPS====================================*/
// clang-format off
enum layers{
    GAME_BASE = 0,
    WIN_BASE,
    RGB_MEDIA,
    FUNCTIONS,
    EXTRA,
};


#define LALT_LB LALT_T(KC_LBRC)
#define RALT_RB RALT_T(KC_RBRC)
#define KC_TERM LCA(KC_T)
#define K_MEDIA TT(RGB_MEDIA)
#define K_FUNC TT(FUNCTIONS)
#define K_EXTRA TT(EXTRA)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[GAME_BASE] = LAYOUT_ansi_68(
     QK_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,           KC_DEL,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,           KC_HOME,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,            KC_PGUP,
     SC_LSPO,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                      SC_RSPC,  KC_UP,   KC_PGDN,
     KC_LCTL,  KC_LGUI,  LALT_LB,                                KC_SPC,                                 RALT_RB,  K_FUNC,   K_MEDIA, KC_LEFT,  KC_DOWN, KC_RGHT),

[WIN_BASE] = LAYOUT_ansi_68(
     QK_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,           KC_DEL,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,           KC_HOME,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,            KC_PGUP,
     SC_LSPO,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                      SC_RSPC,  KC_UP,   KC_PGDN,
     KC_LCTL,  KC_LGUI,  LALT_LB,                                KC_SPC,                                 RALT_RB,  K_FUNC,   K_MEDIA,  KC_LEFT,  KC_DOWN, KC_RGHT),

[RGB_MEDIA] = LAYOUT_ansi_68(
     BAT_LVL,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_BRID,  KC_BRIU,            EE_CLR,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            QK_RBT,
     _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            QK_MAKE,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,
     _______,  _______,  _______,                                _______,                                _______,  KC_NO,    K_MEDIA,  _______,  _______,  _______),

[FUNCTIONS] = LAYOUT_ansi_68(
     KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            KC_MUTE,
     _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  KC_TERM,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_VOLU,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            KC_VOLD,
     _______,  _______,  _______,  KC_CALC,  _______,  _______,  NK_TOGG,  KC_MYCM,  _______,  _______,  _______,                      _______,  _______,  _______,
     _______,  _______,  _______,                                _______,                                _______,  K_FUNC,   KC_NO,    KC_MPRV,  KC_MPLY,  KC_MNXT),

[EXTRA] = LAYOUT_ansi_68(
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,           _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,
     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______),
};
/*====================================KEY MAPS====================================*/



/*====================================RGB MODS====================================*/
#define RGB_LAYER_COLOR RGB_ORANGE
#define FUNC_LAYER_COLOR RGB_SPRINGGREEN

// helper function that sets no trans keys of the layer to the provided color, trans keys are set turned off
void rgb_matrix_set_color_by_keycode(bool set_other_keys_dark, uint8_t led_min, uint8_t led_max, uint8_t layer, uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t key_row = 0; key_row < MATRIX_ROWS; ++key_row) {
        for (uint8_t key_col = 0; key_col < MATRIX_COLS; ++key_col) {
            if (keymap_key_to_keycode(layer, (keypos_t){key_col, key_row}) > KC_TRNS) {
                RGB_MATRIX_INDICATOR_SET_COLOR(g_led_config.matrix_co[key_row][key_col], red, green, blue);
            } else if (set_other_keys_dark) {
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
            rgb_matrix_set_color_by_keycode(false, led_min, led_max, current_layer, RGB_LAYER_COLOR);
            break;
        case FUNCTIONS:
            rgb_matrix_set_color_by_keycode(true, led_min, led_max, current_layer, FUNC_LAYER_COLOR);
            break;
        case WIN_BASE:
        case GAME_BASE:
        default:
            if (!rgb_matrix_get_flags()) {  // if no led layers are set, set it to black, else the last led layers setting will take over
                rgb_matrix_set_color_by_keycode(false, led_min, led_max, current_layer, RGB_OFF);
            }
            break;
    }
    return true;  // api is designed so if return is true it will do further led layers on top of this, that way handling of caps lock etc.. takes priority
}
/*====================================RGB MODS====================================*/