#include <stdbool.h>
#include <stdint.h>
#include "fsl_device_registers.h"

#include "adc.h"
#include "dac.h"
#include "detector.h"
#include "gpio.h"
#include "idle.h"
#include "led.h"
#include "util.h"

int main(void) {
	int calibration = 0;
	int threshold = 0;

	adc_init();
	dac_init();
	gpio_c_init();
	led_init();

	dac_write(0);

	calibration = detector_calibrate();
	threshold = calibration + 20;

	while(true) {
		if(is_idling()) {
			dac_write(0);
			led_write(false, false, false);
		}
		else {
			if(detector_read(threshold)) {
				led_write(true, true, true);
				dac_write(0);
			}
			else {
				led_write(false, false, false);
				dac_write(0xFFF);
			}
		}
	}
}
