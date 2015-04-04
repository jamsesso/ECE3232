#include "riedd.h"

#include <stdlib.h>

/**
 * Initializes all of the sub-modules of RIEDD
 */
void module_init() {
	init_detector_module();
	init_driver_module();
	init_idle_module();
	init_led_module();
}

/**
 * Creates and returns a riedd_module singleton with a fully calibrated detector
 */
riedd_module_t* get_riedd() {
	static riedd_module_t* self = 0;

	if(self == 0) {
		module_init();

		self = (riedd_module_t*) malloc(sizeof(riedd_module_t*));
		self->detector = new_detector();
		self->detector->calibrate(self->detector);
	}

	return self;
}

void do_work(riedd_module_t* self) {
	switch(self->state) {
	case alert:
		if(is_idling()) {
			stop_driving();
			led_off();
			self->state = idle;
		}
		else if(!self->detector->is_over_threshold(self->detector)) {
			start_driving();
			led_off();
			self->state = drive;
		}
		break;

	case drive:
		if(is_idling()) {
			stop_driving();
			led_off();
			self->state = idle;
		}
		else if(self->detector->is_over_threshold(self->detector)) {
			stop_driving();
			led_on();
			self->state = alert;
		}
		break;

	case idle:
		if(!is_idling()) {
			self->detector->calibrate(self->detector);
			self->state = drive;
		}
		break;
	}
}
