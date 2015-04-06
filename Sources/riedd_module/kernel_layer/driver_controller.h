#ifndef DRIVER_CONTROLLER_H
#define DRIVER_CONTROLLER_H

#include <stdint.h>

typedef struct driver_controller_struct {
    uint16_t (*get_drive_speed) (struct driver_controller_struct*);
} driver_controller_t;

driver_controller_t* get_driver_controller();

#endif
