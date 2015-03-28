#include <stdbool.h>
#include <stdint.h>
#include "fsl_device_registers.h"
#include "gpio.h"
#include "dac.h"
#include "adc.h"
#include "util.h"
#include "detector.h"

int main(void) {
	int calibration = 0;
	int threshold = 0;
	adc_init();
	dac_init();
	dac_write(0);

	calibration = detector_calibrate();
	threshold = calibration + 10;

	printf("Average light value = %i, threshold = %i\n", calibration, threshold);

	while(true) {
		if(detector_read(threshold)) {
			dac_write(0);
		}
		else {
			dac_write(0x7ff);
		}
	}

	/*while(1) {
		light = adc_read();

		if(light > 145) {
			printf("Detected light! %i\n", light);
		}
		else {
			dac_write(0x4ff);
		}
	}*/
}
