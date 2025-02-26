// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_ESC,         KC_1,        KC_2,         KC_3,         KC_4,         KC_5,                 KC_6, KC_7,         KC_8,             KC_9,           KC_0,    KC_MINS,
        CW_TOGG,        KC_Q,        KC_W,         KC_E,         KC_R,         KC_T,                 KC_Y, KC_U,         KC_I,             KC_O,           KC_P,    KC_BSLS,
        KC_EQL,         KC_A,        KC_S,         KC_D,         KC_F,         KC_G,                 KC_H, KC_J,         KC_K,             KC_L,           KC_SCLN, KC_QUOT,
        LSFT_T(KC_GRV), ALT_T(KC_Z), LCTL_T(KC_X), LOPT_T(KC_C), LCMD_T(KC_V), KC_B,                 KC_N, RCMD_T(KC_M), ROPT_T(KC_COMMA), RCTL_T(KC_DOT), KC_SLSH, KC_RSFT,
                                                              LT(_LOWER,KC_BSPC), KC_TAB,        KC_ENT, LT(_RAISE,KC_SPC)
    ),
    [_LOWER] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                    KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______,  _______, KC_F12,
        _______, _______, _______, _______, _______, _______,                  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_LCBR, KC_RCBR,
        _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______,  KC_LBRC, KC_RBRC,
                                                     _______, _______,    _______, KC_0
    ),
    [_RAISE] = LAYOUT(
        RGB_TOG, QK_KB,   RGB_MOD, RGB_M_P, RGB_VAD, RGB_VAI,                      _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,                      KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______,
        _______, KC_MPRV, KC_MNXT, KC_MSTP, KC_MPLY, _______,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, C(S(KC_TAB)), C(KC_TAB), _______, _______, _______,
                                                     _______, _______,    _______, _______
    ),
};
