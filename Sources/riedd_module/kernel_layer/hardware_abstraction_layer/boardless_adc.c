#include "adc.h"
#include "boardless_simulation.h"

// Empty because boardless does not need to initialize anything
void adc_init() {}

uint8_t adc_read() {
    uint8_t retVal;
    switch(sim_state) {
    case anomaly_detected:
    case anomaly_detected_a:
    case anomaly_detected_b:
        retVal = 255;
        break;

    default:
        retVal = 0;
    };

    return retVal;
}

