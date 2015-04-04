#include "detector.h"

#include <stdlib.h>
#include "adc.h"

#define CALIBRATION_SAMPLE_SIZE 1000
#define THRESHOLD_BUFFER 20

void init_detector_module() {
	adc_init();
}

detector_t* new_detector() {
	return (detector_t*) malloc(sizeof(detector_t));
}

void calibrate(detector_t* self) {
	int i = 0;
	int calibration = 0;

	for(i = 0; i < CALIBRATION_SAMPLE_SIZE; i++) {
		calibration += adc_read();
	}

	self->threshold = (calibration / CALIBRATION_SAMPLE_SIZE) + THRESHOLD_BUFFER;
}

bool is_over_threshold(detector_t* self) {
	return adc_read() > self->threshold;
}
