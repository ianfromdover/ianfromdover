#pragma once
/*ian
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 425
#define TAP_HOLD_CAPS_DELAY 80
ian*/

// This is a 7-bit address, that gets left-shifted and bit 0
// set to 0 for write, 1 for read (as per I2C protocol)
// The address will vary depending on your wiring:
// 0b1110100 AD <-> GND
// 0b1110111 AD <-> VCC
// 0b1110101 AD <-> SCL
// 0b1110110 AD <-> SDA
#ifdef RGB_MATRIX_ENABLE
#    define DRIVER_ADDR_1 0b1110100
#    define DRIVER_ADDR_2 0b1110111
#    define DRIVER_COUNT 2
#    define DRIVER_1_LED_TOTAL 35
#    define DRIVER_2_LED_TOTAL 33
#    define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)
#endif

#define TAPPING_TERM 200
#define ONESHOT_TIMEOUT 1500

#define MOUSEKEY_MAX_SPEED 6

// USK Polling Rate to 1000hz
#define USB_POLLING_INTERVAL_MS 1

/* Reset default from dz65rgb/v2 config.h */
/*ian
#	undef DISABLE_RGB_MATRIX_SPLASH
#	undef DISABLE_RGB_MATRIX_SOLID_SPLASH
#	undef RGB_MATRIX_LED_FLUSH_LIMIT
#	undef RGB_MATRIX_DEFAULT_MODE
#	undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#	define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
#	define RGB_MATRIX_LED_FLUSH_LIMIT 16 // default: 26
#	define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_TYPING_HEATMAP
#	define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#	define RGB_MATRIX_DEFAULT_HUE 10
#	define RGB_MATRIX_DEFAULT_SAT 255
#	define RGB_MATRIX_DEFAULT_VAL 200
#	define RGB_MATRIX_DEFAULT_SPD 75
ian*/
/* Active RBG Modes */
/* #	undef ENABLE_RGB_MATRIX_TYPING_HEATMAP   		// How hot is your WPM! */
/* #	undef ENABLE_RGB_MATRIX_SPLASH           		// Full gradient & value pulse away from a single key hit then fades value out */
/* #	undef ENABLE_RGB_MATRIX_SOLID_SPLASH     		// Hue & value pulse away from a single key hit then fades value out */
/* Disabling to optimize firmware size */
/*ian
#    undef ENABLE_RGB_MATRIX_ALPHAS_MODS             // Static dual hue, speed is hue for secondary hue
#    undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT     // Static gradient left to right, speed controls how much gradient changes
#    undef ENABLE_RGB_MATRIX_BREATHING               // Single hue brightness cycling animation
#    undef ENABLE_RGB_MATRIX_BAND_VAL                // Single hue band fading brightness scrolling left to right
#    undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL       // Single hue 3 blade spinning pinwheel fades brightness
#    undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL         // Single hue spinning spiral fades brightness
#    undef ENABLE_RGB_MATRIX_CYCLE_ALL               // Full keyboard solid hue cycling through full gradient
#    undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT        // Full gradient scrolling left to right
#    undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN           // Full gradient scrolling top to bottom
#    undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN            // Full gradient scrolling out to in
#    undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL       // Full dual gradients scrolling out to in
#    undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON  // Full gradent Chevron shapped scrolling left to right
#    undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL          // Full gradient spinning pinwheel around center of keyboard
#    undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL            // Full gradient spinning spiral around center of keyboard
#    undef ENABLE_RGB_MATRIX_DUAL_BEACON             // Full gradient spinning around center of keyboard
#    undef ENABLE_RGB_MATRIX_RAINBOW_BEACON          // Full tighter gradient spinning around center of keyboard
#    undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS       // Full dual gradients spinning two halfs of keyboard
#    undef ENABLE_RGB_MATRIX_RAINDROPS               // Randomly changes a single key's hue
#    undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS     // Randomly changes a single key's hue and saturation
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE          // Static single hue, pulses keys hit to shifted hue then fades to current hue
#endif ian*/ /* RBG MATRIX */

/* Firmware size Optimizations */
/*ian
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT
ian*/
