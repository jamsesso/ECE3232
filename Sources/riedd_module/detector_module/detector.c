#include "detector.h"

#include <stdlib.h>
#include "adc.h"

#define CALIBRATION_SAMPLE_SIZE 1000
#define THRESHOLD_BUFFER 20

void init_detector_module() {
    adc_init();
}

/**
 * Takes a sample of the environment using the onboard sensors in order
 * to create a baseline threshold which it will later use to determine
 * if the module has detected an abnormal reading
 */
void calibrate(detector_t* detector) {
    int i = 0;
    int calibration = 0;

    for(i = 0; i < CALIBRATION_SAMPLE_SIZE; i++) {
        calibration += adc_read();
    }

    detector->threshold = (calibration / CALIBRATION_SAMPLE_SIZE) + THRESHOLD_BUFFER;
}

/**
 * Checks the current reading from the sensors against the calibrated threshold
 */
bool is_over_threshold(detector_t* detector) {
    return adc_read() > detector->threshold;
}

/**
 * Creates and returns a detector module singleton
 */
detector_t* get_detector() {
    static detector_t* detector = 0;

    if(detector == 0) {
        init_detector_module();

        detector = (detector_t*) malloc(sizeof(detector_t));
        detector->calibrate = calibrate;
        detector->is_over_threshold = is_over_threshold;
    }

    return detector;
}
