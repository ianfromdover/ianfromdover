#include QMK_KEYBOARD_H
#include <stdio.h>

/*
Izumi Layout v5.8
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2023 Ian Hong @ianfromdover

Layer:
0 base
1 qwerty
2 num
3 code
4 nav
5 sys
6 fps
7 oneshot
*/

#define MACRO_DELAY 20

enum custom_keycodes {
  // Mac App Macros
  SAFARI_M = SAFE_RANGE,
  NOTION_M,
  TELE_M,
  TXTEDT_M,
  TRMNL_M,
  FIGMA_M,
  MUSIC_M,
  MAIL_M,
  SPTFY_M,
  MIRO_M,
  WAPP_M,

  // Win App Macros
  CHROME_W,
  NOTION_W,
  TELE_W,
  NOTEPD_W,
  PSHELL_W,
  FIGMA_W,
  MUSIC_W,
  MAIL_W,
  SPTFY_W,
  MIRO_W,
  WAPP_W
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // ● ---------- Base Layer ---------- ●
  // no programmer layer mod for alt. workaround: do in qwerty
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LT(5, KC_GRV),   KC_X,   KC_L,    KC_Y,   KC_P,    KC_K,                         KC_Z,    KC_F,  KC_O,    KC_U,    KC_QUOT, LT(5, KC_DEL),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LALT_T(KC_TAB),  KC_C,   KC_R,    KC_S,   KC_T,    KC_G,                         KC_M,    KC_N,  KC_E,    KC_I,    KC_A,  G(KC_TAB),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LCTL_T(KC_CAPS), KC_Q,   KC_J,    KC_V,   KC_D,    KC_W,                         KC_B,    KC_H,  KC_COMM, KC_DOT,  KC_SLSH, DF(1),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                       OSM(MOD_LSFT), LT(2, KC_BSPC), LT(3, KC_ESC),     LT(7, KC_ENT), LT(4, KC_SPC), LM(1, MOD_LGUI)
                                      //`--------------------------'  `--------------------------'
  ),

  // ● ---------- QWERTY Layer ---------- ●
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LT(5, KC_GRV),    KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,  KC_I,    KC_O,    KC_P, LT(5, KC_DEL),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LALT_T(KC_TAB),  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LCTL_T(KC_CAPS), KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, DF(0),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                       OSM(MOD_LSFT), LT(2, KC_BSPC), LT(3, KC_ESC),     LT(7, KC_ENT), LT(4, KC_SPC), KC_RGUI
                                      //`--------------------------'  `--------------------------'
  ),

  // ● ---------- NUM Layer ---------- ●
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_DLR,  KC_7,    KC_8,    KC_9,    KC_SLSH, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO,                        KC_PLUS, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_SPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   G(KC_Z), G(KC_X), G(KC_C), G(KC_V), KC_NO,                        KC_ASTR, KC_1,    KC_2,    KC_3,    KC_PERC, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO,   KC_NO,   KC_NO,      KC_MINS, KC_0,    KC_DOT
                                      //`--------------------------'  `--------------------------'
  ),

  // ● ---------- CODE Layer ---------- ●
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_LT,   KC_LBRC, KC_RBRC, KC_GT,   KC_NO, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO,                        KC_PLUS, KC_COLN, KC_LPRN, KC_RPRN, KC_SCLN, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   G(KC_Z), G(KC_X), G(KC_C), G(KC_V), KC_NO,                        KC_NO,   KC_DQUO, KC_AMPR, KC_PIPE, KC_BSLS, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO,   KC_NO,    KC_NO,     KC_UNDS, KC_SPC,  KC_GRV
                                      //`--------------------------'  `--------------------------'
  ),

  // ● ---------- NAV Layer ---------- ●
  // consider having windows nav layer, triggered by variable
  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_NO, G(KC_GRV), G(KC_TAB), G(KC_LEFT), G(KC_RGHT), KC_NO,                      KC_NO,   TG(6),G(KC_MINS), G(KC_EQL), G(KC_BSPC),KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   G(KC_LBRC), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, G(KC_RBRC),                     KC_NO,   KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, KC_NO, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   G(KC_Z), G(KC_X), G(KC_C), G(KC_V), KC_NO,                        KC_NO,   KC_WH_D, KC_WH_U, G(KC_LBRC), G(KC_RBRC), KC_NO, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TAB,  KC_BSPC,  KC_ESC,     KC_NO,  KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  // ● ---------- System and Function Layer ---------- ●
  [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO,                        KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F11,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CG_SWAP,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,                      KC_NO,   KC_F4,   KC_F5,   KC_F6,   KC_F10,   KC_NO, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CG_NORM,   BL_DEC,  KC_BRID, KC_BRIU, BL_INC,  KC_NO,                      KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_MUTE, KC_MPLY, KC_MSTP,     KC_NO,  KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  // ● ---------- FPS Layer ---------- ●
  [6] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_3,    KC_WH_D, KC_MS_U, KC_WH_U, KC_6,    KC_7, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_1,                        KC_4,    KC_MS_L, KC_MS_D, KC_MS_R, KC_8,    KC_9, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_2,                        KC_5,    KC_WH_L, KC_BTN3, KC_WH_R, KC_0,    TG(6),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_SPC, KC_LGUI,     KC_ENT,  KC_BTN1, KC_BTN2
                                      //`--------------------------'  `--------------------------'
  ),

  // ● ---------- One-Shot Layer ---------- ●
  [7] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_NO,   MIRO_W,  FIGMA_W, SPTFY_W, G(KC_LSFT),                     C(KC_SPC), SPTFY_M, FIGMA_M, MIRO_M, SGUI(KC_3), SGUI(KC_4),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   NOTEPD_W,NOTION_W,TELE_W,  CHROME_W,G(KC_DOT),               C(G(KC_SPC)),SAFARI_M,TELE_M,NOTION_M,TXTEDT_M,KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   MAIL_W,  WAPP_W,  MUSIC_W, PSHELL_W,G(KC_SPC),                     G(KC_SPC), TRMNL_M, MUSIC_M, WAPP_M,  MAIL_M,  KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO,   KC_NO,   KC_NO,       KC_NO, KC_NO, KC_NO
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

    case TRMNL_M:
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

    case SPTFY_M:
      if (record -> event.pressed) {
        SEND_STRING(SS_LGUI(" ") SS_DELAY(MACRO_DELAY) "spo" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    case MIRO_M:
      if (record -> event.pressed) {
        SEND_STRING(SS_LGUI(" ") SS_DELAY(MACRO_DELAY) "miro" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    case WAPP_M:
      if (record -> event.pressed) {
        SEND_STRING(SS_LGUI(" ") SS_DELAY(MACRO_DELAY) "whats" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
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

    case SPTFY_W:  
      if (record -> event.pressed) {
        SEND_STRING(SS_TAP(X_LEFT_GUI) SS_DELAY(MACRO_DELAY) "spot" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    case MIRO_W:  
      if (record -> event.pressed) {
        SEND_STRING(SS_TAP(X_LEFT_GUI) SS_DELAY(MACRO_DELAY) "miro" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    case WAPP_W:  
      if (record -> event.pressed) {
        SEND_STRING(SS_TAP(X_LEFT_GUI) SS_DELAY(MACRO_DELAY) "whats" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    }
  return true;
}
