#ifndef RGB_LED_INCLUDED_H
#define RGB_LED_INCLUDED_H

#include <stdbool.h>

/**
 * Configures PortA1, PortA2, and PortD5 to control
 * red, green, and blue of the RGB LED respectively
 */
void init_rgb_led();

// Turns on the RGB LED with respect to the user's input
void led_write(bool red_on, bool green_on, bool blue_on);

#endif
