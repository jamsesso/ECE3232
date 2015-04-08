#include "detector.h"

#include <stdlib.h>
#include "hardware_abstraction_layer/adc.h"

#define CALIBRATION_SAMPLE_SIZE 1000
#define THRESHOLD_BUFFER 25

void init_detector_module() {
    adc_init();
}

/**
 * Takes a sample of the environment using the onboard sensors in order
 * to create a baseline threshold which it will later use to determine
 * if the module has detected an abnormal reading
 */
void calibrate(detector_t* self) {
    int i = 0;
    int calibration = 0;

    for(i = 0; i < CALIBRATION_SAMPLE_SIZE; i++) {
        calibration += adc_read();
    }

    self->_threshold = (calibration / CALIBRATION_SAMPLE_SIZE) + THRESHOLD_BUFFER;
}

/**
 * Checks the current reading from the sensors against the calibrated threshold
 */
bool is_over_threshold(detector_t* self) {
    return adc_read() > self->_threshold;
}

/**
 * Creates and returns a detector module singleton
 */
detector_t* get_detector() {
    static detector_t* self = 0;

    if(self == 0) {
        init_detector_module();

        self = (detector_t*) malloc(sizeof(detector_t));

        self->_threshold = 0;

        self->calibrate = &calibrate;
        self->is_over_threshold = &is_over_threshold;
    }

    return self;
}
