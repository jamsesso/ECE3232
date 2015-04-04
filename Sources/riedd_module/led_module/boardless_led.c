#include "led.h"

#include <stdlib.h>
#include <stdio.h>

void init_led_module(){}

void led_write(led_t* self, bool red_on, bool green_on, bool blue_on) {
    printf("Turning light to:\nR: %d\nG: %d\nB: %d\n",
        red_on ? 255 : 0,
        green_on ? 255 : 0,
        blue_on ? 255 : 0
    );
}

// Makes the RGB LED white
void led_on(led_t* self) {
    led_write(self, true, true, true);
}

// Turns the RGB LED off
void led_off(led_t* self) {
    led_write(self, false, false, false);
}

/**
 * Creates and returns an led_module singleton
 */
led_t* get_led() {
    static led_t* self = 0;

    if(self == 0) {
        init_led_module();

        self = (led_t*) malloc(sizeof(led_t));
        self->led_on = led_on;
        self->led_off = led_off;
        self->led_write = led_write;
    }

    return self;
}

