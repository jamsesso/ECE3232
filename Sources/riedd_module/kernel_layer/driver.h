#ifndef DRIVE_H
#define DRIVE_H

#include "driver_controller.h"

typedef struct driver_struct {
    /**
     * Determines how much power should be sent to
     * the wheels
     */
    driver_controller_t* driver_controller;

    /**
     * Starts driving the wheels at full power
     */
    void (*start_driving) (struct driver_struct*);

    /**
     * Stops driving the wheels
     */
    void (*stop_driving) (struct driver_struct*);
} driver_t;

/**
 * Creates and returns a driver module singleton
 */
driver_t* get_driver(driver_controller_t* driver_controller);

#endif /* DRIVE_H_ */
