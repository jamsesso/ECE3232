#include "idle.h"

#include <stdlib.h>
#include "gpio.h"

void init_idle_module() {
    gpio_c_init();
}

/**
 * Checks the appropriate port to see if the module should be idling
 */
bool is_idling(idle_t* self) {
    return gpio_c_read();
}

/**
 * Creates and returns an idle_module singleton
 */
idle_t* get_idle() {
    static idle_t* self = 0;

    if(self == 0) {
        init_idle_module();
        self = (idle_t*) malloc(sizeof(idle_t));
        self->is_idling = is_idling;
    }

    return self;
}
