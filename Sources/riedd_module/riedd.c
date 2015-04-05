#include "riedd.h"

#include <stdlib.h>
#include <stdio.h>

#ifdef BOARDLESS
#include "boardless_simulation.h"
#endif


void transition_to_alert_mode(riedd_module_t* riedd) {
    // Stop driving
    riedd->driver->stop_driving(riedd->driver);

    // Turn on LED
    riedd->led->led_on(riedd->led);

    // Make state transition
    riedd->state = alert;
}

void transition_to_drive_mode(riedd_module_t* riedd) {
    // Start driving
    riedd->driver->start_driving(riedd->driver);

    // Turn off LED
    riedd->led->led_off(riedd->led);

    // Make state transition
    riedd->state = drive;
}

void transition_to_idle_mode(riedd_module_t* riedd) {
    // Stop driving
    riedd->driver->stop_driving(riedd->driver);

    // Turn off LED
    riedd->led->led_off(riedd->led);

    // Make state transition
    riedd->state = idle;
}

/**
 * Controls the module based on the current state, and the readings from the sensors
 */
void do_work(riedd_module_t* riedd) {
#ifdef BOARDLESS
    handle_simulation_state();
#endif

    switch(riedd->state) {

    // We have detected an abnormal reading and are alerting the operator
    case alert:
        // Should we be idling?
        if(riedd->idle->is_idling(riedd->idle)) {
            transition_to_idle_mode(riedd);
        }
        // Are we still detecting an abnormal signal?
        else if(!riedd->detector->is_over_threshold(riedd->detector)) {
            transition_to_drive_mode(riedd);
        }
        break;

    case drive:
        // Should we be idling?
        if(riedd->idle->is_idling(riedd->idle)) {
            transition_to_idle_mode(riedd);
        }
        // Have we detected an abnormal signal?
        else if(riedd->detector->is_over_threshold(riedd->detector)) {
            transition_to_alert_mode(riedd);
        }
        break;

    case idle:
        // Should we still be idling?
        if(!riedd->idle->is_idling(riedd->idle)) {
            // Re-calibrate the detector
            riedd->detector->calibrate(riedd->detector);
            transition_to_drive_mode(riedd);
        }
        break;
    default:
        transition_to_idle_mode(riedd);
    }
}

/**
 * Creates and returns a riedd_module singleton
 */
riedd_module_t* get_riedd() {
    static riedd_module_t* riedd = 0;

    if(riedd == 0) {
        riedd = (riedd_module_t*) malloc(sizeof(riedd_module_t*));

        riedd->detector = get_detector();
        riedd->detector->calibrate(riedd->detector);

        riedd->driver = get_driver();
        riedd->idle = get_idle();
        riedd->led = get_led();

        riedd->do_work = do_work;
    }

    return riedd;
}
