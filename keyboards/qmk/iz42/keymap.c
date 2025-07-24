#include QMK_KEYBOARD_H
#include <stdio.h>

/*
 * Izumi Layout v7.1
 * 24 July 2025 10:08pm
 * Copyright 2019 @foostan
 * Copyright 2020 Drashna Jaelre <@drashna>
 * Copyright 2025 Ian Hong @ianfromdover
 *
 * TODO: add programmer alphabet, just copy iz68
 * 
 * Layer:
 * 0 base
 * 1 qwerty
 * 2 num
 * 3 code
 * 4 nav
 * 5 system, functions
 * 6 mouse
 * 7 oneshot
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
  FNDR_M,

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
  WAPP_W,
  FXPL_W
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // ● ---------- Base Layer ---------- ●
  // no programmer layer mod for alt. workaround: do in qwerty
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LT(5, KC_GRV),   KC_B,   KC_L,    KC_D,   KC_C,    KC_V,                         KC_Z,    KC_Y,  KC_O,    KC_U,    KC_COMM, LT(5, KC_DEL),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LALT_T(KC_TAB),  KC_N,   KC_R,    KC_T,   KC_S,    KC_G,                         KC_P,    KC_H,  KC_A,    KC_E,    KC_I,    KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LCTL_T(KC_CAPS), KC_Q,   KC_X,    KC_M,   KC_W,    KC_J,                         KC_K,    KC_F,  KC_QUOT, KC_SCLN,  KC_DOT, DF(1),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                       LM(1, MOD_LGUI), LT(2, KC_BSPC), LT(3, KC_ESC),     LT(7, KC_ENT), LT(4, KC_SPC), OSM(MOD_LSFT)
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
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_DLR,  KC_1,    KC_2,    KC_3,    KC_SLSH, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO,                        KC_PLUS, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_SPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   G(KC_Z), G(KC_X), G(KC_C), G(KC_V), KC_NO,                        KC_ASTR, KC_7,    KC_8,    KC_9,    KC_PERC, KC_NO,
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
  // no, add home and end on the left
  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO, A(KC_TAB), G(KC_TAB), KC_HOME, KC_END, KC_NO,                       KC_NO,   TG(6),G(KC_MINS), G(KC_EQL), G(KC_BSPC),KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   G(KC_LBRC), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, G(KC_RBRC),                     KC_NO,   KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, G(KC_ENT), 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   G(KC_Z), G(KC_X), G(KC_C), G(KC_V), KC_NO,                        KC_NO,   KC_WH_D, KC_WH_U, G(KC_LBRC), G(KC_RBRC), KC_NO, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TAB,  KC_BSPC,  KC_ESC,     KC_NO,  KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  // ● ---------- System Layer ---------- ●
  [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO,               KC_NO,C(A(KC_U)), C(A(KC_I)), C(A(KC_O)), C(A(KC_P)),KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CG_SWAP,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,             C(A(KC_H)),C(A(KC_J)),C(A(KC_K)),C(A(KC_L)),C(A(KC_SCLN)),KC_F1, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CG_NORM,   BL_DEC,  KC_BRID, KC_BRIU, BL_INC,  KC_NO,             KC_F4,C(A(KC_M)),C(A(KC_COMM)),C(A(KC_DOT)),C(A(KC_SLSH)),KC_F5,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_MUTE, KC_MPLY, KC_MSTP, C(A(G(KC_ENT))),C(A(KC_ENT)),KC_F2
                                      //`--------------------------'  `--------------------------'
  ),

  // ● ---------- Mouse Layer ---------- ●
  [6] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        TG(6),   KC_WH_D, KC_MS_U, KC_WH_U, KC_5,    KC_6, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_1,                        KC_3,    KC_MS_L, KC_MS_D, KC_MS_R, KC_7,    KC_8, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_2,                        KC_4,    KC_WH_L, KC_BTN3, KC_WH_R, KC_9,    KC_0,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_SPC, KC_LGUI,     KC_ENT,  KC_BTN1, KC_BTN2
                                      //`--------------------------'  `--------------------------'
  ),

  // ● ---------- One-Shot Layer ---------- ●
  [7] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO, G(S(KC_S)),  MIRO_W,  FIGMA_W, SPTFY_W, G(KC_LSFT),                C(S(KC_SCLN)),SPTFY_M,FIGMA_M,MIRO_M,SGUI(KC_3),SGUI(KC_4),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      G(KC_DOT),NOTEPD_W,NOTION_W,TELE_W, CHROME_W,FXPL_W,                      FNDR_M, SAFARI_M, TELE_M, NOTION_M,TXTEDT_M,C(G(KC_SPC)),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   MAIL_W,  WAPP_W,  MUSIC_W, PSHELL_W,KC_LGUI,                   G(KC_SPC), TRMNL_M, MUSIC_M, WAPP_M,  MAIL_M,  KC_NO,
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

    case FNDR_M:
      if (record -> event.pressed) {
        SEND_STRING(SS_LGUI(" ") SS_DELAY(MACRO_DELAY) "finde" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
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

    case FXPL_W:  
      if (record -> event.pressed) {
        SEND_STRING(SS_TAP(X_LEFT_GUI) SS_DELAY(MACRO_DELAY) "fil" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
      }
      return true;

    }
  return true;
}
