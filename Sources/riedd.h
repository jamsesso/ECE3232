#ifndef RIEDD_H_
#define RIEDD_H_

#include "detector_module/detector.h"
#include "driver_module/driver.h"
#include "idle_module/idle.h"
#include "led_module/led.h"

typedef enum {
	alert,
	drive,
	idle
} riedd_states;

typedef struct riedd_module_struct {
	riedd_states state;
	detector_t* detector;

	void (*do_work) (struct riedd_module_struct*);
} riedd_module_t;

riedd_module_t* get_riedd();

#endif /* RIEDD_H_ */
