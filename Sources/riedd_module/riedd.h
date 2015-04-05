#ifndef RIEDD_H_
#define RIEDD_H_

#include "kernel_layer/detector.h"
#include "kernel_layer/driver.h"
#include "kernel_layer/idle.h"
#include "kernel_layer/hardware_abstraction_layer/led.h"

typedef enum {
    alert,
    drive,
    idle
} riedd_states;

typedef struct riedd_module_struct {
    riedd_states state;

    detector_t* detector;
    driver_t* driver;
    idle_t* idle;
    led_t* led;

    void (*do_work) (struct riedd_module_struct*);
} riedd_module_t;

/**
 * Creates and returns a riedd_module singleton
 */
riedd_module_t* get_riedd();

#endif /* RIEDD_H_ */
