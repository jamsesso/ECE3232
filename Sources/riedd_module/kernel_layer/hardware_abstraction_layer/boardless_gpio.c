#include "gpio.h"
#include "boardless_simulation.h"

void gpio_c_init() {}

int gpio_c_read() {
    int retVal;
    switch(sim_state) {
    case sim_idle_state:
    case sim_idle_state_a:
    case sim_idle_state_b:
        retVal = 255;
        break;

    default:
        retVal = 0;
    };

    return retVal;
}

void gpio_xxx_init(){}

int gpio_xxx_read(){
    return slow_drive ? 0 : 255;
}
