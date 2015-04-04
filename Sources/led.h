#ifndef LED_MODULE_INCLUDED_H
#define LED_MODULE_INCLUDED_H

#include <stdbool.h>

void init_led_module();
void led_write(bool red_on, bool green_on, bool blue_on);
void led_on();
void led_off();

#endif
