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

// Define home row mods for base layer
#define HM_U CTL_T(KC_U)
#define HM_I OPT_T(KC_I)
#define HM_A SFT_T(KC_A)
#define HM_E CMD_T(KC_E)

#define HM_D CTL_T(KC_D)
#define HM_T OPT_T(KC_T)
#define HM_R SFT_T(KC_R)
#define HM_N CMD_T(KC_N)

// Define home row mods for navigation/number layer
#define HM_STA CTL_T(KC_HOME)
#define HM_LFT OPT_T(KC_LEFT)
#define HM_DWN SFT_T(KC_DOWN)
#define HM_RGT CMD_T(KC_RIGHT)

#define HM_8 CTL_T(KC_8)
#define HM_7 OPT_T(KC_7)
#define HM_6 SFT_T(KC_6)
#define HM_5 CMD_T(KC_5)

// Define home row mods for symbols layer
#define HM_BSLS CTL_T(KC_BSLS)
#define HM_SLSH OPT_T(KC_SLSH)
#define HM_LCBR SFT_T(KC_LCBR)
#define HM_RCBR CMD_T(KC_RCBR)

#define HM_LPRN CTL_T(KC_LPRN)
#define HM_RPRN OPT_T(KC_RPRN)
#define HM_MINS SFT_T(KC_MINS)
#define HM_COLN CMD_T(KC_COLN)

// Define symbols
#define KC_EUR LSA(KC_2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // BASE LAYER
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_X,    KC_V,    KC_L,    KC_C,    KC_W,                         KC_K,    KC_H,    KC_G,    KC_F,    KC_Q, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    HM_U,    HM_I,    HM_A,    HM_E,    KC_O,                         KC_S,    HM_N,    HM_R,    HM_T,    HM_D, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX,    KC_Y,    KC_P,    KC_Z,                         KC_B,    KC_M, KC_COMM,  KC_DOT,    KC_J, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,   MO(1),  KC_SPC,    KC_LSFT,   MO(2),   MO(3)
                                      //`--------------------------'  `--------------------------'
  ),

  // NAVIGATION/NUMBER LAYER
    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_PGUP, KC_BSPC,   KC_UP,  KC_DEL, KC_PGDN,                      KC_COLN,    KC_9,    KC_0, KC_COMM,  KC_DOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  HM_STA,  HM_LFT,  HM_DWN,  HM_RGT,  KC_END,                     KC_MINUS,    HM_5,    HM_6,    HM_7,    HM_8, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_ESC,  KC_TAB, XXXXXXX,  KC_ENT, KC_CAPS,                      KC_PLUS,    KC_1,    KC_2,    KC_3,    KC_4, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  // SYMBOLS LAYER
    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  KC_EUR, KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC,                      KC_EXLM,   KC_LT,   KC_GT,  KC_EQL, KC_AMPR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, HM_BSLS, HM_SLSH, HM_LCBR, HM_RCBR, KC_ASTR,                      KC_QUES, HM_LPRN, HM_RPRN, HM_MINS, HM_COLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_HASH,  KC_DLR, KC_PIPE, KC_TILD,  KC_GRV,                      KC_PLUS, KC_PERC, KC_DQUO, KC_QUOT, KC_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,   KC_AT,    XXXXXXX, _______, XXXXXXX
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
