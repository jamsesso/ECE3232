#include <stdbool.h>
#include "adc.h"

#ifndef DETECTOR_MODULE_INCLUDED
#define DETECTOR_MODULE_INCLUDED 1
#define CALIBRATION_SAMPLE_SIZE 1000

int detector_calibrate() {
	int i = 0;
	int calibration = 0;

	printf("Running calibration...\n");

	for(i = 0; i <= CALIBRATION_SAMPLE_SIZE; i++) {
		calibration += adc_read();
	}

	return calibration / CALIBRATION_SAMPLE_SIZE;
}

bool detector_read(int threshold) {
	return adc_read() > threshold;
}

#endif
