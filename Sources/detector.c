#include <stdbool.h>
#include "adc.h"

#define CALIBRATION_SAMPLE_SIZE 1000

int detector_calibrate() {
	int i = 0;
	int calibration = 0;

	for(i = 0; i < CALIBRATION_SAMPLE_SIZE; i++) {
		calibration += adc_read();
	}

	return calibration / CALIBRATION_SAMPLE_SIZE;
}

bool detector_read(int threshold) {
	return adc_read() > threshold;
}
