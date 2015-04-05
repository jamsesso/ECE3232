#include "led.h"

#include <stdlib.h>
#include <stdio.h>

void init_led_module(){}

void led_write(led_t* led, bool red_on, bool green_on, bool blue_on) {
    printf("Turning light to:\nR: %d\nG: %d\nB: %d\n",
        red_on ? 255 : 0,
        green_on ? 255 : 0,
        blue_on ? 255 : 0
    );
}

// Makes the RGB LED white
void led_on(led_t* led) {
    led_write(led, true, true, true);
}

// Turns the RGB LED off
void led_off(led_t* led) {
    led_write(led, false, false, false);
}

/**
 * Creates and returns an led_module singleton
 */
led_t* get_led() {
    static led_t* led = 0;

    if(led == 0) {
        init_led_module();

        led = (led_t*) malloc(sizeof(led_t));
        led->led_on = led_on;
        led->led_off = led_off;
        led->led_write = led_write;
    }

    return led;
}

