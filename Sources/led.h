#ifndef LED_MODULE_INCLUDED_H
#define LED_MODULE_INCLUDED_H

#include <stdbool.h>

void led_init();
void led_write(bool red_on, bool green_on, bool blue_on);

#endif
