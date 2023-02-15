#include QMK_KEYBOARD_H

/* Izumi68 Layout v1.0
 * 15 Feb 2022 6pm
 * Copyright 2022 Ian Hong @ianfromdover
 *
 * Note: karabiner makes sticky shift malfunction
 *
 * Layers:
 * 0 canary, main
 * 1 qwerty
 * 2 num
 * 3 code
 * 4 nav
 * 5 system, functions
 * 6 mouse
 * 7 one shot
 */

#define MACRO_DELAY 20

enum custom_keycodes {
    // Mac Macros
    SAFARI_M = SAFE_RANGE,
    NOTION_M,
    TELE_M,
    TXTEDT_M,
    TRMNL_M,
    FIGMA_M,
    MUSIC_M,
    SPTFY_M,
    MAIL_M,
    MIRO_M,
    WAPP_M,

    // Win Macros
    CHROME_W,
    NOTION_W,
    TELE_W,
    NOTEPD_W,
    PSHELL_W,
    FIGMA_W,
    MUSIC_W,
    SPTFY_W,
    MAIL_W,
    MIRO_W,
    WAPP_W
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // ● ---------- Izumi Layer ---------- ●
    [0] = LAYOUT_65_ansi(
            QK_GESC,          KC_1,    KC_2,    KC_3,   KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    DF(1), 
            LT(2,KC_TAB),     KC_X,    KC_L,    KC_Y,   KC_P,     KC_K,    KC_Z,    KC_F,    KC_O,    KC_U,    KC_QUOT, KC_LBRC, KC_RBRC, A(KC_BSPC), KC_DEL,
            LT(3,KC_CAPS),    KC_C,    KC_R,    KC_S,   KC_T,     KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_A,    KC_SCLN, LT(4,KC_ENT),     G(KC_TAB), 
            OSM(MOD_LSFT),    KC_J,    KC_V,    KC_D,   KC_W,     KC_Q,    KC_B,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_RSFT),    KC_UP,   G(KC_GRV),
            LM(1,MOD_LCTL),   LM(1,MOD_LALT), LM(1,MOD_LGUI),     KC_SPC,           LT(7,KC_BSLS),    LT(5,KC_GRV),     TG(6),   KC_LEFT, KC_DOWN, KC_RGHT
            ),

    // ● ---------- QWERTY Layer ---------- ●
    [1] = LAYOUT_65_ansi(
            QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, DF(0), 
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
            KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  G(KC_TAB), 
            KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   G(KC_GRV), 
            KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                        KC_RGUI, LT(5,KC_GRV), KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
            ),


    // ● ---------- Number Layer ---------- ●
    [2] = LAYOUT_65_ansi(
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, KC_DLR,  KC_7,    KC_8,    KC_9,    KC_SLSH, _______, _______, _______, _______, 
            _______, _______, KC_LCTL, KC_LGUI, KC_LSFT, _______, KC_PLUS, KC_4,    KC_5,    KC_6,    KC_EQL,  _______,          _______, _______, 
            _______,          _______, _______, _______, _______, _______, KC_MINS, KC_1,    KC_2,    KC_3,    KC_DOT,  _______, _______, _______, 
            _______, _______, _______,                   _______,                            KC_0,    _______, _______, _______, _______, _______
            ),

    // ● ---------- Code Layer ---------- ●
    [3] = LAYOUT_65_ansi(
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, KC_GRV,  KC_LT,   KC_LBRC, KC_RBRC, KC_GT,   _______, _______, _______, _______, 
            _______, _______, KC_LCTL, KC_LGUI, KC_LSFT, _______, KC_PLUS, KC_COLN, KC_LPRN, KC_RPRN, KC_SCLN, _______,          _______, _______, 
            _______,          _______, _______, _______, _______, _______, KC_UNDS, KC_DQUO, KC_AMPR, KC_PIPE, KC_BSLS, _______, _______, _______, 
            _______, _______, _______,                   _______,                            _______, _______, _______, _______, _______, _______
            ),

    // ● ---------- Navigation Layer ---------- ●
    [4] = LAYOUT_65_ansi(
            _______, _______, _______, _______,     _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, G(KC_LEFT),  G(KC_RGHT), _______, _______, _______, _______, KC_RGUI, KC_RALT, _______, _______, _______, _______, 
            _______, KC_LEFT, KC_DOWN, KC_UP,       KC_RGHT,    _______, _______, KC_RSFT, _______, KC_WH_D, KC_WH_U, _______,          _______, _______, 
            _______,          G(KC_Z), G(KC_X),     G(KC_C),    G(KC_V), _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______,                          _______,                            KC_RCTL, _______, _______, _______, _______, _______
            // these qmk keycodes dont work: undo, cut, copy, paste, browser
            ),

    // ● ---------- System, Function Layer ---------- ●
    [5] = LAYOUT_65_ansi(
            QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  XXXXXXX, 
            EE_CLR,  RGB_VAD, KC_BRID, KC_BRIU, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, 
            KC_MUTE, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, RGB_MOD, 
            C(KC_SPC),        XXXXXXX, XXXXXXX, RGB_SPD, RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SAI, RGB_RMOD,
            CG_NORM, CG_SWAP, XXXXXXX,                   KC_MPLY,                            XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD, RGB_HUI
            ),

    // ● ---------- Mouse Layer ---------- ●
    [6] = LAYOUT_65_ansi(
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, KC_WH_D, KC_MS_U, KC_WH_U, _______, _______, _______, _______, KC_ACL2, 
            _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, _______,          _______, KC_ACL1, 
            _______,          KC_Z,    KC_X,    KC_C,    KC_V,    _______, KC_BTN1, KC_BTN2, _______, _______, _______, _______, _______, KC_ACL0, 
            _______, _______, _______,                   _______,                            _______, _______, _______, _______, _______, _______
            ),

    // ● ---------- One Shot Layer ---------- ●
    [7] = LAYOUT_65_ansi(
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, G(KC_MINS), G(KC_EQL), G(KC_BSPC), XXXXXXX, 
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SPTFY_M, FIGMA_M, MIRO_M,  XXXXXXX, G(KC_LBRC), G(KC_RBRC), XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SAFARI_M, TELE_M, NOTION_M, TXTEDT_M, XXXXXXX,        XXXXXXX, XXXXXXX,
            XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TRMNL_M, MUSIC_M, WAPP_M, MAIL_M,  XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX,                   G(KC_SPC),                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
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

        case SPTFY_M:
            if (record -> event.pressed) {
                SEND_STRING(SS_LGUI(" ") SS_DELAY(MACRO_DELAY) "spo" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
            }
            return true;

        case MAIL_M:
            if (record -> event.pressed) {
                SEND_STRING(SS_LGUI(" ") SS_DELAY(MACRO_DELAY) "mai" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
            }
            return true;

        case MIRO_M:
            if (record -> event.pressed) {
                SEND_STRING(SS_LGUI(" ") SS_DELAY(MACRO_DELAY) "miro" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
            }
            return true;

        case WAPP_M:
            if (record -> event.pressed) {
                SEND_STRING(SS_LGUI(" ") SS_DELAY(MACRO_DELAY) "what" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
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

        case SPTFY_W:
            if (record -> event.pressed) {
                SEND_STRING(SS_TAP(X_LEFT_GUI) SS_DELAY(MACRO_DELAY) "spo" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
            }
            return true;

        case MAIL_W:
            if (record -> event.pressed) {
                SEND_STRING(SS_TAP(X_LEFT_GUI) SS_DELAY(MACRO_DELAY) "outlook" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
            }
            return true;
        case MIRO_W:
            if (record -> event.pressed) {
                SEND_STRING(SS_TAP(X_LEFT_GUI) SS_DELAY(MACRO_DELAY) "miro" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
            }
            return true;

        case WAPP_W:
            if (record -> event.pressed) {
                SEND_STRING(SS_TAP(X_LEFT_GUI) SS_DELAY(MACRO_DELAY) "what" SS_DELAY(MACRO_DELAY) SS_TAP(X_ENTER));
            }
            return true;


    }
    return true;
}

bool rgb_matrix_indicators_user(void) {
    /**
     * Layers:
     * 0 canary, main
     * 1 qwerty
     * 2 num
     * 3 code
     * 4 nav
     * 5 system, functions
     * 6 mouse
     * 7 one shot
     */
    int white[] = {0xFF, 0xFF, 0xFF};
    switch(get_highest_layer(layer_state | default_layer_state)) {
        case 1: // qwerty is grey
            rgb_matrix_set_color_all(0x40, 0x40, 0x40);
            break;

        case 2: // num is purple
            rgb_matrix_set_color_all(0x00, 0x00, 0x00); // turn all lights off

            // make layer's keys purple
            {
                // define the colours and lights to turn on
                int colour[] = {0x70, 0x20, 0xE0};
                int lights[] = {
                    14, 
                    21, 22, 23, 24, 25, 
                    36, 37, 38, 39, 40,
                    51, 52, 53, 54, 55, 
                    62
                };
                int white_lights[] = { // modifiers
                    32, 33, 34
                };

                // set the light colours
                int lights_size = sizeof(lights) / sizeof(lights[0]);
                int white_lights_size = sizeof(white_lights) / sizeof(white_lights[0]);
                for (int i = 0; i < lights_size; i++) {
                    rgb_matrix_set_color(lights[i], colour[0], colour[1], colour[2]);
                }
                for (int i = 0; i < white_lights_size; i++) {
                    rgb_matrix_set_color(white_lights[i], white[0], white[1], white[2]);
                }
            }
            break;

        case 3: // code is pink
            rgb_matrix_set_color_all(0x00, 0x00, 0x00); // turn all lights off

            // make layer's keys pink
            {
                int colour[] = {0xD0, 0x10, 0x80};
                int lights[] = {
                    14, 
                    21, 22, 23, 24, 25, 
                    36, 37, 38, 39, 40,
                    51, 52, 53, 54, 55
                };
                int lightsSize = sizeof(lights) / sizeof(lights[0]);

                for (int i = 0; i < lightsSize; i++) {
                    rgb_matrix_set_color(lights[i], colour[0], colour[1], colour[2]);
                }
            }

            // modifiers to white
            rgb_matrix_set_color(32, 0xFF, 0xFF, 0xFF); // ctl
            rgb_matrix_set_color(33, 0xFF, 0xFF, 0xFF); // cmd
            rgb_matrix_set_color(34, 0xFF, 0xFF, 0xFF); // sft
            break;

        case 4: // nav is orange
            rgb_matrix_set_color_all(0x00, 0x00, 0x00); // turn all lights off

            // make layer's keys orange
            {
                int colour[] = {0xDF, 0x50, 0x00};
                int lights[] = {
                    14, 18, 19,                 // home, end
                    31, 32, 33, 34, 39, 40, // arrows, wheels
                    45, 46, 47, 48          // undo, cut, copy, paste
                };
                int lightsSize = sizeof(lights) / sizeof(lights[0]);

                for (int i = 0; i < lightsSize; i++) {
                    rgb_matrix_set_color(lights[i], colour[0], colour[1], colour[2]);
                }
            }

            // modifiers to white
            rgb_matrix_set_color(62, 0xFF, 0xFF, 0xFF); // ctl
            rgb_matrix_set_color(24, 0xFF, 0xFF, 0xFF); // cmd
            rgb_matrix_set_color(25, 0xFF, 0xFF, 0xFF); // opt
            rgb_matrix_set_color(37, 0xFF, 0xFF, 0xFF); // sft
            break;

        case 5: // system is lime green
            // rgb_matrix_set_color_all(0x00, 0x00, 0x00); // turn all lights off

            // make layer's keys lime
            {
                int colour[] = {0x90, 0xFF, 0x05};
                int lights[] = {
                    14,
                    16, 17, 18, 19,     29,
                    30, 31, 32, 33, 34, 43,
                    47, 48, 56,         57,
                    61, 65, 66, 67
                };
                int lightsSize = sizeof(lights) / sizeof(lights[0]);

                for (int i = 0; i < lightsSize; i++) {
                    rgb_matrix_set_color(lights[i], colour[0], colour[1], colour[2]);
                }
            }
            break;

        case 6: // mouse is azure blue
            rgb_matrix_set_color_all(0x00, 0x00, 0x00); // turn all lights off

            // make layer's keys azure blue
            {
                int colour[] = {0x20, 0xB0, 0xFF};
                int lights[] = {
                    14, 23, 37, 38, 39
                };
                int lightsSize = sizeof(lights) / sizeof(lights[0]);

                for (int i = 0; i < lightsSize; i++) {
                    rgb_matrix_set_color(lights[i], colour[0], colour[1], colour[2]);
                }
            }
            rgb_matrix_set_color(50, 0xDF, 0x50, 0x00); // L, R mouse btns orange
            rgb_matrix_set_color(51, 0xDF, 0x50, 0x00);
            break;

        case 7: // oneshot is emerald green
            rgb_matrix_set_color_all(0x00, 0x00, 0x00); // turn all lights off

            // make layer's keys emerald green
            {
                int colour[] = {0x00, 0x80, 0x00};
                int lights[] = {
                    14,
                    13, 61,
                    22, 23, 24,
                    37, 38, 39, 40,
                    51, 52, 53, 54,
                };
                int lightsSize = sizeof(lights) / sizeof(lights[0]);

                for (int i = 0; i < lightsSize; i++) {
                    rgb_matrix_set_color(lights[i], colour[0], colour[1], colour[2]);
                }
            }
            break;

        default: // on Canary layer, do matrix effect
            break;
    }

    // CAPS: change caps and takodachi to white
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(30, white[0], white[1], white[2]);
        rgb_matrix_set_color(14, white[0], white[1], white[2]);
    }

    return true;
}

