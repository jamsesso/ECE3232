#include "driver.h"

#include <stdlib.h>
#include "hardware_abstraction_layer/dac.h"

void init_driver() {
    dac_init();
}

/**
 * Starts driving the wheels at full power
 */
void start_driving(driver_t* self) {
    dac_write(self->driver_controller->get_drive_speed(self->driver_controller));
}

/**
 * Stops driving the wheels
 */
void stop_driving(driver_t* self) {
    dac_write(0);
}

/**
 * Creates and returns a driver module singleton
 */
driver_t* get_driver(driver_controller_t* driver_controller) {
    static driver_t* self = 0;

    if(self == 0) {
        init_driver();

        self = (driver_t*) malloc(sizeof(driver_t));
        self->driver_controller = driver_controller;
        self->start_driving = &start_driving;
        self->stop_driving = &stop_driving;
    }

    return self;
}
