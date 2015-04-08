#include "driver_controller.h"

#include <stdbool.h>
#include <stdlib.h>
#include "hardware_abstraction_layer/gpio.h"

void init_driver_controller() {
    gpio_c_init();
}

uint16_t get_drive_speed(driver_controller_t* self) {
    uint16_t drive_speed;

	// Read 7th least significant bit to check the speed switch
    bool speed_switch_state = gpio_c_read() & (1 << 7);
    if(speed_switch_state) {
        drive_speed = 0xFFF;
    }
    else {
        drive_speed = 0x7FF;
    }

    return drive_speed;
}

/**
 * Creates and returns a driver module singleton
 */
driver_controller_t* get_driver_controller() {
    static driver_controller_t* self = 0;

    if(self == 0) {
        init_driver_controller();

        self = (driver_controller_t*) malloc(sizeof(driver_controller_t));
        self->get_drive_speed = &get_drive_speed;
    }

    return self;
}
