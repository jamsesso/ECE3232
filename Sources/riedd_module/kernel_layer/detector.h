#ifndef DETECTOR_MODULE_INCLUDED_H
#define DETECTOR_MODULE_INCLUDED_H

#include <stdbool.h>

typedef struct detector_struct {
    unsigned int threshold;

    /**
     * Takes a sample of the environment using the onboard sensors in order
     * to create a baseline threshold which it will later use to determine
     * if the module has detected an abnormal reading
     */
    void (*calibrate) (struct detector_struct*);

    /**
     * Checks the current reading from the sensors against the calibrated threshold
     */
    bool (*is_over_threshold) (struct detector_struct*);
} detector_t;

/**
 * Creates and returns a detector module singleton
 */
detector_t* get_detector();

#endif
