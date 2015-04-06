#include "rgb_led.h"

#include <stdlib.h>
#include <stdio.h>

void init_rgb_led(){}

void led_write(bool red_on, bool green_on, bool blue_on) {
    printf("Turning light to:\nR: %d\nG: %d\nB: %d\n",
        red_on ? 255 : 0,
        green_on ? 255 : 0,
        blue_on ? 255 : 0
    );
}

