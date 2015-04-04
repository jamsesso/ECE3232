#include "riedd.h"

#include <stdlib.h>
#include <stdio.h>


void transition_to_alert_mode(riedd_module_t* self) {
    // Stop driving
    self->driver->stop_driving(self->driver);

    // Turn on LED
    self->led->led_on(self->led);

    // Make state transition
    self->state = alert;
}

void transition_to_drive_mode(riedd_module_t* self) {
    // Start driving
    self->driver->start_driving(self->driver);

    // Turn off LED
    self->led->led_off(self->led);

    // Make state transition
    self->state = drive;
}

void transition_to_idle_mode(riedd_module_t* self) {
    // Stop driving
    self->driver->stop_driving(self->driver);

    // Turn off LED
    self->led->led_off(self->led);

    // Make state transition
    self->state = idle;
}

/**
 * Controls the module based on the current state, and the readings from the sensors
 */
void do_work(riedd_module_t* self) {
    switch(self->state) {

    // We have detected an abnormal reading and are alerting the operator
    case alert:
        // Should we be idling?
        if(self->idle->is_idling(self->idle)) {
            transition_to_idle_mode(self);
        }
        // Are we still detecting an abnormal signal?
        else if(!self->detector->is_over_threshold(self->detector)) {
            transition_to_drive_mode(self);
        }
        break;

    case drive:
        // Should we be idling?
        if(self->idle->is_idling(self->idle)) {
            transition_to_idle_mode(self);
        }
        // Have we detected an abnormal signal?
        else if(self->detector->is_over_threshold(self->detector)) {
            transition_to_alert_mode(self);
        }
        break;

    case idle:
        // Should we still be idling?
        if(!self->idle->is_idling(self->idle)) {
            // Re-calibrate the detector
            self->detector->calibrate(self->detector);
            transition_to_drive_mode(self);
        }
        break;
    default:
        transition_to_idle_mode(self);
    }
}

/**
 * Creates and returns a riedd_module singleton
 */
riedd_module_t* get_riedd() {
    static riedd_module_t* self = 0;

    if(self == 0) {
        self = (riedd_module_t*) malloc(sizeof(riedd_module_t*));

        self->detector = get_detector();
        self->detector->calibrate(self->detector);

        self->driver = get_driver();
        self->idle = get_idle();
        self->led = get_led();

        self->do_work = do_work;
    }

    return self;
}
