/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

/*
Import german macos keymap aliases.
see https://docs.qmk.fm/#/reference_keymap_extras
*/
#include "keymap_german_mac_iso.h"
#include "sendstring_german_mac_iso.h"

// Define home row mods for base layer
#define HM_U CTL_T(DE_U)
#define HM_I OPT_T(DE_I)
#define HM_A SFT_T(DE_A)
#define HM_E CMD_T(DE_E)

#define HM_D CTL_T(DE_D)
#define HM_T OPT_T(DE_T)
#define HM_R SFT_T(DE_R)
#define HM_N CMD_T(DE_N)

// Define home row mods for navigation/number layer
#define HM_STA CTL_T(KC_HOME)
#define HM_LFT OPT_T(KC_LEFT)
#define HM_DWN SFT_T(KC_DOWN)
#define HM_RGT CMD_T(KC_RIGHT)

#define HM_8 CTL_T(DE_8)
#define HM_7 OPT_T(DE_7)
#define HM_6 SFT_T(DE_6)
#define HM_5 CMD_T(DE_5)

// Define home row mods for symbols layer
/*
Some keycodes conflict in the case statement of process_record_user below.
Therefor the custom_keycodes get defined to resolve this conflict.
An example would be DE_7 and DE_SLSH. They are the same except one is shifted.
*/
enum custom_keycodes {
    CUSTOM_BSLS = SAFE_RANGE,
    CUSTOM_SLSH,
    CUSTOM_LCBR,
    CUSTOM_RCBR,

    CUSTOM_COLN,
    CUSTOM_MINS,
    CUSTOM_RPRN,
    CUSTOM_LPRN
};

#define HM_BSLS CTL_T(CUSTOM_BSLS)
#define HM_SLSH OPT_T(CUSTOM_SLSH)
#define HM_LCBR SFT_T(CUSTOM_LCBR)
#define HM_RCBR CMD_T(CUSTOM_RCBR)

#define HM_COLN CTL_T(CUSTOM_COLN)
#define HM_MINS OPT_T(CUSTOM_MINS)
#define HM_RPRN SFT_T(CUSTOM_RPRN)
#define HM_LPRN CMD_T(CUSTOM_LPRN)

// Define keyboard layer
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // BASE LAYER
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    DE_X,    DE_V,    DE_L,    DE_C,    DE_W,                         DE_K,    DE_H,    DE_G,    DE_F,    DE_Q, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    HM_U,    HM_I,    HM_A,    HM_E,    DE_O,                         DE_S,    HM_N,    HM_R,    HM_T,    HM_D, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX,    DE_Y,    DE_P,    DE_Z,                         DE_B,    DE_M, DE_COMM,  DE_DOT,    DE_J, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,   MO(1),  KC_SPC,    KC_LSFT,   MO(2),   MO(3)
                                      //`--------------------------'  `--------------------------'
  ),

  // NAVIGATION/NUMBER LAYER
    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_PGUP, KC_BSPC,   KC_UP,  KC_DEL, KC_PGDN,                      DE_COLN,    DE_9,    DE_0, DE_COMM,  DE_DOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  HM_STA,  HM_LFT,  HM_DWN,  HM_RGT,  KC_END,                      DE_MINS,    HM_5,    HM_6,    HM_7,    HM_8, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_ESC,  KC_TAB, XXXXXXX,  KC_ENT, KC_CAPS,                      DE_PLUS,    DE_1,    DE_2,    DE_3,    DE_4, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  // SYMBOLS LAYER
    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, DE_EURO, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,                      DE_EXLM, DE_LABK, DE_RABK,  DE_EQL, DE_AMPR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, HM_BSLS, HM_SLSH, HM_LCBR, HM_RCBR, DE_ASTR,                      DE_QUES, HM_LPRN, HM_RPRN, HM_MINS, HM_COLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, DE_HASH,  DE_DLR, DE_PIPE, DE_TILD,  DE_GRV,                      DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,   DE_AT,    XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  // F-KEY LAYER
    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LOPT, KC_LSFT, KC_LCMD, XXXXXXX,                      XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, _______
                                      //`--------------------------'  `--------------------------'
  )
};


/*
Intercept mod-tabs that contain non-basic keycodes e.g. home row mods on symbols or navigation layer.
Mod-hold is handled correctly but can also be intercepted if the need arises.
see: https://precondition.github.io/home-row-mods#using-non-basic-keycodes-in-mod-taps
see: https://docs.qmk.fm/#/mod_tap?id=changing-tap-function
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HM_STA:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_HOME); // Send KC_HOME on tap
                return false;        // Ignore further processing of key.
            }
            break;
        case HM_LFT:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LEFT); // Send KC_LEFT on tap
                return false;
            }
            break;
        case HM_DWN:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_DOWN); // Send KC_DOWN on tap
                return false;
            }
            break;
        case HM_RGT:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RIGHT); // Send KC_RIGHT on tap
                return false;
            }
            break;
        case HM_8:
            if (record->tap.count && record->event.pressed) {
                tap_code16(DE_8); // Send DE_8 on tap
                return false;
            }
            break;
        case HM_7:
            if (record->tap.count && record->event.pressed) {
                tap_code16(DE_7); // Send DE_7 on tap
                return false;
            }
            break;
        case HM_6:
            if (record->tap.count && record->event.pressed) {
                tap_code16(DE_6); // Send DE_6 on tap
                return false;
            }
            break;
        case HM_5:
            if (record->tap.count && record->event.pressed) {
                tap_code16(DE_5); // Send DE_5 on tap
                return false;
            }
            break;
        case HM_BSLS:
            if (record->tap.count && record->event.pressed) {
                tap_code16(DE_BSLS); // Send DE_BSLS on tap
                return false;
            }
            break;
        case HM_SLSH:
            if (record->tap.count && record->event.pressed) {
                tap_code16(DE_SLSH); // Send DE_SLSH on tap
                return false;
            }
            break;
        case HM_LCBR:
            if (record->tap.count && record->event.pressed) {
                tap_code16(DE_LCBR); // Send DE_LCBR on tap
                return false;
            }
            break;
        case HM_RCBR:
            if (record->tap.count && record->event.pressed) {
                tap_code16(DE_RCBR); // Send DE_RCBR on tap
                return false;
            }
            break;
        case HM_LPRN:
            if (record->tap.count && record->event.pressed) {
                tap_code16(DE_LPRN); // Send DE_LPRN on tap
                return false;
            }
            break;
        case HM_RPRN:
            if (record->tap.count && record->event.pressed) {
                tap_code16(DE_RPRN); // Send DE_RPRN on tap
                return false;
            }
            break;
        case HM_MINS:
            if (record->tap.count && record->event.pressed) {
                tap_code16(DE_MINS); // Send DE_MINS on tap
                return false;
            }
            break;
        case HM_COLN:
            if (record->tap.count && record->event.pressed) {
                tap_code16(DE_COLN); // Send DE_COLN on tap
                return false;
            }
            break;
    }
    return true;
}

