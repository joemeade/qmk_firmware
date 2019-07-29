/* Copyright 2018 Noah Frederick
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

#pragma once

#include "quantum.h"
#include "version.h"

#ifdef STENO_ENABLE
#include "keymap_steno.h"
#else
#include "keymap_plover.h"
#endif

#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"
#endif

enum user_layers {
  QWERTY_LAYER,
  LOWER_LAYER,
  RAISE_LAYER,
  NAV_LAYER,
  GUI_LAYER,
  ADJUST_LAYER
};

enum user_keycodes {
  LEADER = SAFE_RANGE,
  QWERTY,
  COLEMAK,
  STCH_EX,
  STENO,
  STN_EXIT,
  SEND_MAKE,
  SEND_VERSION,
  DYNAMIC_MACRO_RANGE
};

// Dynamic macros add additional keycodes.
#define NEW_SAFE_RANGE (DYNAMIC_MACRO_PLAY2 + 1)

#define LOWER MO(LOWER_LAYER)
#define RAISE MO(RAISE_LAYER)

/* #define GUI_L LT(GUI_LAYER, KC_LBRC) */
#define NAV_LBRC LT(NAV_LAYER, KC_LBRC)
#define GUI_R LT(GUI_LAYER, KC_RBRC)

// TODO: make these tap to curly braces
#define HYPER_L ALL_T(LSFT(KC_LBRC))
#define HYPER_R ALL_T(LSFT(KC_RCBR))
/* #define MEH */
/* KC_LCBR, KC_RCBR */
#define CTL_ESC CTL_T(KC_ESC)
#define CTL_ENT CTL_T(KC_ENT)

/* #define CAPITAL OSM(MOD_LSFT) */

#define NAV_BSP LT(NAV_LAYER, KC_BSPC)
#define NAV_ENT LT(NAV_LAYER, KC_ENT)

#define GUI_GRV LGUI(KC_GRV)

// Dashes (macOS)
/* #define KC_NDSH LALT(KC_MINS) */
/* #define KC_MDSH S(LALT(KC_MINS)) */

// Window manager keys
#define WM_FULL LALT(LGUI(KC_F))
#define WM_NEXT LCTL(LALT(LGUI(KC_RGHT)))
#define WM_PREV LCTL(LALT(LGUI(KC_LEFT)))
/*
 *  H left   half
 *  L right  half
 *  K top    half
 *  J bottom half
 *
 *  Y top left
 *  O top right
 *  N bottom left
 *  . bottom right
 *
 *  U left third
 *  I right third
 *  center third
 *
 *  M left two thirds
 *  , right two thirds
 *
 *  maximize
 *  center
 *  restore
 *
 *  next display
 *  prev display 
 */
#define WM_NW   LCTL(LGUI(KC_LEFT))
#define WM_N    LALT(LGUI(KC_UP))
#define WM_NE   LCTL(LGUI(KC_RGHT))
#define WM_E    LALT(LGUI(KC_RGHT))
#define WM_SE   S(LCTL(LGUI(KC_RGHT)))
#define WM_S    LALT(LGUI(KC_DOWN))
#define WM_SW   S(LCTL(LGUI(KC_LEFT)))
#define WM_W    LALT(LGUI(KC_LEFT))
#define WM_CNTR LALT(LGUI(KC_C))

// Unify backlight controls
#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
#define LIT_TOG RGB_TOG
#define LIT_DEC RGB_VAD
#define LIT_INC RGB_VAI
#else
#define LIT_TOG BL_TOGG
#define LIT_DEC BL_DEC
#define LIT_INC BL_INC
#endif

// Alias layout macros that expand groups of keys.
#define LAYOUT_planck_grid_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)
#define LAYOUT_planck_mit_wrapper(...) LAYOUT_planck_mit(__VA_ARGS__)
#define LAYOUT_preonic_grid_wrapper(...) LAYOUT_preonic_grid(__VA_ARGS__)

#define _________________QWERTY_L1_________________ KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________ KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________ KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________LOWER_L1__________________ KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________LOWER_L2__________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define _________________LOWER_L3__________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define _________________LOWER_L4__________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC

#define _________________LOWER_R1__________________    KC_6, KC_7,        KC_8,      KC_9,     KC_KP_PLUS
#define _________________LOWER_R2__________________ XXXXXXX, KC_4,        KC_5,      KC_6,    KC_KP_MINUS
#define _________________LOWER_R3__________________ XXXXXXX, KC_1,        KC_2,      KC_3, KC_KP_ASTERISK
#define _________________LOWER_R4__________________ KC_BSPC, KC_0, KC_KP_ENTER, KC_KP_DOT,    KC_KP_SLASH

#define _________________RAISE_L1__________________ KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________RAISE_L2__________________ KC_LPRN, KC_LBRC, KC_LCBR, XXXXXXX, XXXXXXX
#define _________________RAISE_L3__________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define _________________RAISE_R1__________________ KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL
#define _________________RAISE_R2__________________ XXXXXXX, XXXXXXX, KC_RCBR, KC_RBRC, KC_RPRN
#define _________________RAISE_R3__________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLASH

#define __________________NAV_L1___________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________NAV_L2___________________ XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END
#define __________________NAV_L3___________________ XXXXXXX, LGUI(KC_LEFT), LGUI(KC_UP), LGUI(KC_DOWN), LGUI(KC_RGHT)

#define __________________NAV_R1___________________ LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RGHT), XXXXXXX
#define __________________NAV_R2___________________       KC_LEFT,       KC_DOWN,       KC_UP,       KC_RGHT, XXXXXXX
#define __________________NAV_R3___________________ LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_UP), LALT(KC_RGHT), XXXXXXX

#define __________________GUI_L1___________________ KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_D, XXXXXXX
#define __________________GUI_L2___________________ KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, XXXXXXX
#define __________________GUI_L3___________________ KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, XXXXXXX

#define __________________GUI_R1___________________ XXXXXXX, WM_PREV, WM_NW,   WM_N,    WM_NE
#define __________________GUI_R2___________________ XXXXXXX, WM_FULL, WM_W,    WM_CNTR, WM_E
#define __________________GUI_R3___________________ XXXXXXX, WM_NEXT, WM_SW,   WM_S,    WM_SE

#define __________VOLUME_________ KC_MUTE, KC_VOLD, KC_VOLU
#define __________MEDIA__________ KC_MPRV, KC_MPLY, KC_MNXT

#define __________________BASE_L0__________________ _________________LOWER_L1__________________
#define __________________BASE_R0__________________ _________________LOWER_R1__________________
