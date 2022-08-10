#include QMK_KEYBOARD_H
#include <stdio.h>

/*
Izumi Layout v5.5
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2022 Ian Hong @ianfromdover

Layers:
0, 7 base clmk
1, 8 nav
2, 9 num
3, 10 code
4, 11 fps
5, 12 sys
6, 13 oneshot
*/

#define MACRO_DELAY 20

enum custom_keycodes {
  // Mac App Macros
  SAFARI_M = SAFE_RANGE,
  NOTION_M,
  TELE_M,
  TXTEDT_M,
  TERMNL_M,
  FIGMA_M,
  MUSIC_M,
  MAIL_M,

  // Win App Macros
  CHROME_W,
  NOTION_W,
  TELE_W,
  NOTEPD_W,
  PSHELL_W,
  FIGMA_W,
  MUSIC_W,
  MAIL_W,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // ● ---------- CLMK Base Layers ---------- ●
  // Mac
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 LT(5, KC_NO),    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,  KC_U,   KC_Y,   KC_QUOT, LT(5, KC_NO),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,     KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,  KC_E,   KC_I,   KC_O, OSL(6),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  KC_CAPS, LCTL_T(KC_Z), LALT_T(KC_X), KC_C, KC_D,    KC_V,               KC_K, KC_H, KC_COMM, RALT_T(KC_DOT), RCTL_T(KC_SLSH), TG(4),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                       OSM(MOD_LSFT), LT(2, KC_BSPC), LT(3, KC_ESC),     KC_ENT, LT(1, KC_SPC), RGUI_T(KC_DEL)
                                      //`--------------------------'  `--------------------------'
  ),

  // Win
  [7] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 LT(12, KC_NO),    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,   KC_Y,   KC_QUOT, LT(12, KC_NO),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,     KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                       KC_M,    KC_N,    KC_E,   KC_I,   KC_O,    OSL(13),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  KC_CAPS, LGUI_T(KC_Z), LALT_T(KC_X), KC_C, KC_D,    KC_V,               KC_K, KC_H, KC_COMM, RALT_T(KC_DOT), RGUI_T(KC_SLSH), TG(11),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                       OSM(MOD_LSFT), LT(9, KC_BSPC), LT(10, KC_ESC),     KC_ENT, LT(8, KC_SPC), RCTL_T(KC_DEL)
                                      //`--------------------------'  `--------------------------'
  ),

  // ● ---------- NAV Layers ---------- ●
  // Mac
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_NO, G(KC_GRV), G(KC_TAB), G(KC_LEFT), G(KC_RGHT), KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   G(KC_LBRC), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, G(KC_RBRC),                     KC_NO,   KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, KC_NO, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), KC_NO,                          KC_NO,   KC_WH_D, KC_WH_U, KC_NO,   KC_NO,   KC_NO, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TAB,  KC_BSPC,  KC_ESC,     KC_NO,  KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  // Win
  // idk about window switching within app, set it to switch by window and by app idk
  [8] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO, G(KC_TAB), A(KC_TAB), KC_HOME, KC_END, KC_NO,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   A(KC_LEFT), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, A(KC_RGHT),                     KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_NO,                          KC_NO,   KC_WH_D, KC_WH_U, KC_NO,   KC_NO,   KC_NO, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TAB,  KC_BSPC,  KC_ESC,     KC_NO,  KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  // ● ---------- NUM Layers ---------- ●
  // Mac
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_ASTR, KC_7,    KC_8,    KC_9,    KC_SLSH, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO,                        KC_PLUS, KC_4,    KC_5,    KC_6,    KC_0,    KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_DLR,  KC_1,    KC_2,    KC_3,    KC_PERC, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO,   KC_NO,   KC_NO,      KC_MINS, KC_SPC,  KC_DOT
                                      //`--------------------------'  `--------------------------'
  ),

  // Win
  [9] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_ASTR, KC_7,    KC_8,    KC_9,    KC_SLSH, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                        KC_PLUS, KC_4,    KC_5,    KC_6,    KC_0,    KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_DLR,  KC_1,    KC_2,    KC_3,    KC_PERC, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO,   KC_NO,   KC_NO,      KC_MINS, KC_SPC,  KC_DOT
                                      //`--------------------------'  `--------------------------'
  ),
  // ● ---------- CODE Layers ---------- ●
  // Mac
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_LT,   KC_LBRC, KC_RBRC, KC_GT,   KC_NO, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO,                        KC_PLUS, KC_COLN, KC_LPRN, KC_RPRN, KC_SCLN, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_DQUO, KC_AMPR, KC_PIPE, KC_BSLS, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO,   KC_NO,    KC_NO,     KC_UNDS, KC_SPC,  KC_GRV
                                      //`--------------------------'  `--------------------------'
  ),

  // Win
  [10] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_LT,   KC_LBRC, KC_RBRC, KC_GT,   KC_NO, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                        KC_PLUS, KC_COLN, KC_LPRN, KC_RPRN, KC_SCLN, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_DQUO, KC_AMPR, KC_PIPE, KC_BSLS, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO,   KC_NO,    KC_NO,     KC_UNDS, KC_SPC,  KC_GRV
                                      //`--------------------------'  `--------------------------'
  ),

  // ● ---------- FPS Layers ---------- ●
  // Mac
  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_1,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_3,    KC_WH_D, KC_MS_U, KC_WH_U, KC_6,    KC_7, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_2,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_4,    KC_MS_L, KC_MS_D, KC_MS_R, KC_8,    KC_9, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_5,    KC_WH_L, KC_BTN3, KC_WH_R, KC_0,    KC_TRNS, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_SPC, KC_LGUI,     KC_ENT,  KC_BTN1, KC_BTN2
                                      //`--------------------------'  `--------------------------'
  ),

  // Win
  [11] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_1,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_3,    KC_WH_D, KC_MS_U, KC_WH_U, KC_6,    KC_7, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_2,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_4,    KC_MS_L, KC_MS_D, KC_MS_R, KC_8,    KC_9, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_5,    KC_WH_L, KC_BTN3, KC_WH_R, KC_0,    KC_TRNS, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_SPC, KC_LCTL,     KC_ENT,  KC_BTN1, KC_BTN2
                                      //`--------------------------'  `--------------------------'
  ),
  // ● ---------- System and Function Layers ---------- ●
  // Mac
  [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO,                        KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F11,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,                        KC_NO,   KC_F4,   KC_F5,   KC_F6,   KC_F10,   KC_NO, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   BL_DEC,  KC_BRID, KC_BRIU, BL_INC,  KC_NO,                        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_MUTE, KC_MPLY, KC_MSTP,     KC_NO,  KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  // Win
  [12] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                        KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F11,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,                        KC_NO,   KC_F4,   KC_F5,   KC_F6,   KC_F10,   KC_NO, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   BL_DEC,  KC_BRID, KC_BRIU, BL_INC,  KC_NO,                        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_MUTE, KC_MPLY, KC_MSTP,     KC_NO,  KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),
  // ● ---------- One-Shot Layers ---------- ●
  // Mac
  [6] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_NO,   KC_NO, SGUI(KC_3), SGUI(KC_4), KC_NO,                    KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   DF(0),   DF(7), C(G(KC_SPC)), C(KC_SPC), KC_NO,                   KC_NO,  SAFARI_M, NOTION_M,TELE_M,TXTEDT_M,G(KC_TAB),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,  TERMNL_M, FIGMA_M, MUSIC_M, MAIL_M,  KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO,   KC_NO,   KC_NO,       KC_NO,  G(KC_SPC), KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  // Win
  // Ctrl + Shift to change keyboard layout for the same language.
  [13] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_NO,   KC_NO, SGUI(KC_S), SGUI(KC_S), KC_NO,                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   DF(0),   DF(7), G(KC_DOT), G(KC_SPC), KC_NO,                      KC_NO,   CHROME_W,NOTION_W,TELE_W,  NOTEPD_W,A(KC_TAB),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   PSHELL_W,FIGMA_W, MUSIC_W, MAIL_W,  KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO,   KC_NO,   KC_NO,       KC_NO,  G(KC_SPC), KC_NO
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // ● ---------- Mac Macros ---------- ●
    case SAFARI_M:
      if (record -> event.pressed) {
        SEND_STRING(SS_LGUI(" ") SS_DELAY(MACRO_DELAY) "saf" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    case NOTION_M:
      if (record -> event.pressed) {
        SEND_STRING(SS_LGUI(" ") SS_DELAY(MACRO_DELAY) "not" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    case TELE_M:
      if (record -> event.pressed) {
        SEND_STRING(SS_LGUI(" ") SS_DELAY(MACRO_DELAY) "tel" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    case TXTEDT_M:
      if (record -> event.pressed) {
        SEND_STRING(SS_LGUI(" ") SS_DELAY(MACRO_DELAY) "text" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    case TERMNL_M:
      if (record -> event.pressed) {
        SEND_STRING(SS_LGUI(" ") SS_DELAY(MACRO_DELAY) "ter" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    case FIGMA_M:
      if (record -> event.pressed) {
        SEND_STRING(SS_LGUI(" ") SS_DELAY(MACRO_DELAY) "fig" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    case MUSIC_M:
      if (record -> event.pressed) {
        SEND_STRING(SS_LGUI(" ") SS_DELAY(MACRO_DELAY) "mus" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    case MAIL_M:
      if (record -> event.pressed) {
        SEND_STRING(SS_LGUI(" ") SS_DELAY(MACRO_DELAY) "mai" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    // ● ---------- Windows Macros ---------- ●
    case CHROME_W:
      if (record -> event.pressed) {
        SEND_STRING(SS_TAP(X_LEFT_GUI) SS_DELAY(MACRO_DELAY) "chr" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    case NOTION_W:
      if (record -> event.pressed) {
        SEND_STRING(SS_TAP(X_LEFT_GUI) SS_DELAY(MACRO_DELAY) "not" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    case TELE_W:    
      if (record -> event.pressed) {
        SEND_STRING(SS_TAP(X_LEFT_GUI) SS_DELAY(MACRO_DELAY) "tele" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    case NOTEPD_W:
      if (record -> event.pressed) {
        SEND_STRING(SS_TAP(X_LEFT_GUI) SS_DELAY(MACRO_DELAY) "notepa" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    case PSHELL_W:
      if (record -> event.pressed) {
        SEND_STRING(SS_TAP(X_LEFT_GUI) SS_DELAY(MACRO_DELAY) "powershel" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    case FIGMA_W:    
      if (record -> event.pressed) {
        SEND_STRING(SS_TAP(X_LEFT_GUI) SS_DELAY(MACRO_DELAY) "fig" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    case MUSIC_W:
      if (record -> event.pressed) {
        SEND_STRING(SS_TAP(X_LEFT_GUI) SS_DELAY(MACRO_DELAY) "itunes" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    case MAIL_W:  
      if (record -> event.pressed) {
        SEND_STRING(SS_TAP(X_LEFT_GUI) SS_DELAY(MACRO_DELAY) "outlook" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    }
  return true;
}
