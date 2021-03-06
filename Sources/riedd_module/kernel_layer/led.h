#ifndef LED_MODULE_INCLUDED_H
#define LED_MODULE_INCLUDED_H

#include <stdbool.h>

typedef struct led_struct {
    // Makes the RGB LED white
    void (*led_on) (struct led_struct*);

    // Turns the RGB LED off
    void (*led_off) (struct led_struct*);
} led_t;

/**
 * Creates and returns an led_module singleton
 */
led_t* get_led();

#endif
