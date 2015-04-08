#include "led.h"

#include <stdlib.h>
#include "rgb_led.h"

void init_led_module() {
	init_rgb_led();
}

// Makes the RGB LED white
void led_on(led_t* self) {
    led_write(true, true, true);
}

// Turns the RGB LED off
void led_off(led_t* self) {
    led_write(false, false, false);
}

/**
 * Creates and returns an led_module singleton
 */
led_t* get_led() {
    static led_t* self = 0;

    if(self == 0) {
        init_led_module();

        self = (led_t*) malloc(sizeof(led_t));
        self->led_on = &led_on;
        self->led_off = &led_off;
    }

    return self;
}
