#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _MV_1,
    _MV_2,
    _WND,
};

/*
 * Tap Dance declarations
 * See: See: https://docs.qmk.fm/#/feature_tap_dance
 */
enum {
    TD_ESC_CAPS
};

/*
 * Tap Dance definitions
 */
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for esc, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -   |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  /   |Shift |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |  Alt |  GUI |Lower | Bksp |    Space    |Enter |Raise |   =  |   [  |  ]   |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_planck_mit(
        TD(TD_ESC_CAPS), KC_Q,                 KC_W,          KC_E,           KC_R,           KC_T,   KC_Y, KC_U,           KC_I,              KC_O,                 KC_P,                  KC_MINS,
        KC_TAB,          KC_A,                 LT(_WND,KC_S), LT(_MV_2,KC_D), LT(_MV_1,KC_F), KC_G,   KC_H, KC_J,           KC_K,              KC_L,                 KC_SCLN,               KC_QUOT,
        KC_LSFT,         KC_Z,                 KC_X,          LT(_MV_2,KC_C), LT(_MV_1,KC_V), KC_B,   KC_N, LT(_MV_1,KC_M), LT(_MV_2,KC_COMM), KC_DOT,               KC_SLSH,               KC_RSFT,
        KC_LCTL,         MT(MOD_LALT, KC_GRV), KC_LGUI,       MO(_LOWER),     KC_BSPC,        KC_SPC,       KC_ENT,         MO(_RAISE),        MT(MOD_RGUI, KC_EQL), MT(MOD_RALT, KC_LBRC), MT(MOD_RCTL, KC_RBRC)
    ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  |   |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      | Vol- | Vol+ | Mute | Play |      | Left | Down |  Up  |Right |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Reset|      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_mit(
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN, KC_PIPE,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
        RESET,   _______, _______, _______, _______,     _______,      _______, _______, _______,  _______, _______
    ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |r_TOG |r_Mode|r_Hue+|r_Hue-|      |      |   -  |   =  |   [  |   ]  |  \   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |BL_TOG|BL_STEP|     |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_mit(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______, BL_TOGG, BL_STEP, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
    ),
     /* Movement 1 - text + tab navigation
     * ,-----------------------------------------------------------------------------------.
     * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |      | left | down |  up  |right |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |   [  |   ]  |
     * `-----------------------------------------------------------------------------------'
     */
    [_MV_1] = LAYOUT_planck_mit(
        _______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4),    LGUI(KC_5), LGUI(KC_6),    LGUI(KC_7),    LGUI(KC_8),  LGUI(KC_9),     LGUI(KC_0), _______,
        _______, _______,    _______,    _______,    _______,       _______,    LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_UP), LALT(KC_RIGHT), _______,    _______,
        _______, _______,    _______,    _______,    _______,       _______,    _______,       _______,       _______,     _______,        _______,    _______,
        _______, _______,    _______,    _______,    LALT(KC_BSPC),           _______,         _______,       _______,     _______,        LGUI(LSFT(KC_LBRC)), LGUI(LSFT(KC_RBRC))
    ),
    /* Movement 2 - text + history navigation + number commands
     * ,-----------------------------------------------------------------------------------.
     * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |      | left | down |  up  |right |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |   [  |   ]  |
     * `-----------------------------------------------------------------------------------'
     */
    [_MV_2] = LAYOUT_planck_mit(
        _______, LGUI(LSFT(KC_1)), LGUI(LSFT(KC_2)), LGUI(LSFT(KC_3)), LGUI(LSFT(KC_4)), LGUI(LSFT(KC_5)), LGUI(LSFT(KC_6)), LGUI(LSFT(KC_7)), LGUI(LSFT(KC_8)), LGUI(LSFT(KC_9)), LGUI(LSFT(KC_0)), _______,
        _______, _______,          _______,          _______,          _______,          _______,          LGUI(KC_LEFT),    LGUI(KC_DOWN),    LGUI(KC_UP),      LGUI(KC_RIGHT),   _______,          _______,
        _______, _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,
        _______, _______,          _______,          _______,          LGUI(KC_BSPC),                  _______,              _______,          _______,          _______,          LGUI(KC_LBRC),    LGUI(KC_RBRC)
    ),
    /* WND - window layout management
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |      | left | down |  up  |right |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |   [  |   ]  |
     * `-----------------------------------------------------------------------------------'
     */
    [_WND] = LAYOUT_planck_mit(
        _______, _______, _______, _______, _______,             _______,    _______,             _______,             _______,           _______,              _______, _______,
        _______, _______, _______, _______, _______,             _______,    LCTL(LALT(KC_LEFT)), LCTL(LALT(KC_DOWN)), LCTL(LALT(KC_UP)), LCTL(LALT(KC_RIGHT)), _______, _______,
        _______, _______, _______, _______, _______,             _______,    _______,             _______,             _______,           _______,              _______, _______,
        _______, _______, _______, _______, LCTL(LALT(KC_BSPC)),         _______,                 LCTL(LALT(KC_ENT)),  _______,           _______,              _______, _______
    )
};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void led_set_user(uint8_t usb_led) {

    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_COMPOSE)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_KANA)) {

    } else {

    }

}
