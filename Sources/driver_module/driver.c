#include "driver.h"

#include "dac.h"

void init_driver_module() {
	dac_init();
}

void start_driving() {
	dac_write(0xFFF);
}

void stop_driving() {
	dac_write(0);
}
