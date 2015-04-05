#include "driver.h"

#include <stdlib.h>
#include "dac.h"

void init_driver() {
    dac_init();
}

/**
 * Starts driving the wheels at full power
 */
void start_driving(driver_t* driver) {
    dac_write(0xFFF);
}

/**
 * Stops driving the wheels
 */
void stop_driving(driver_t* driver) {
    dac_write(0);
}

/**
 * Creates and returns a driver module singleton
 */
driver_t* get_driver() {
    static driver_t* driver = 0;

    if(driver == 0) {
        init_driver();
        driver = (driver_t*) malloc(sizeof(driver_t*));
        driver->start_driving = start_driving;
        driver->stop_driving = stop_driving;
    }

    return driver;
}
