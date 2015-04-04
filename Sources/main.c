#include "detector.h"
#include "driver.h"
#include "idle.h"
#include "led.h"
#include "util.h"

#define TRUE 1
#define FALSE 0

void board_init() {
	init_detector_module();
	init_driver_module();
	init_idle_module();
	init_led_module();
}

int main(void) {
	board_init();

	detector_t* detector = new_detector();

	while(TRUE) {
		if(is_idling()) {
			stop_driving();
			led_off();
		}
		else {
			if(detector->is_over_threshold(detector)) {
				led_on();
				stop_driving();
			}
			else {
				led_off();
				start_driving();
			}
		}
	}
}
