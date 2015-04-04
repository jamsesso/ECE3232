#include "idle.h"

#include "gpio.h"

void init_idle_module() {
	gpio_c_init();
}

bool is_idling() {
	return gpio_c_read();
}
