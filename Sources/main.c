#include "fsl_device_registers.h"
#include "gpio.h"
#include <stdbool.h>

void ADC0_Init() {
	// Enable the clock the ADC0 module.
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;

	HW_ADC_SC2_SET(ADC0, 0x0);
	HW_ADC_SC3_SET(ADC0, 0xF);
}

short ADC0_Convert() {
	ADC0_SC1A = 0x0;

	while(!ADC0_SC1A){}

	return ADC0_RA;
}

void delay(void) {
	int c = 1, d = 1;

	for (c = 1; c <= 32767; c++)
		for (d = 1; d <= 1024; d++) {}
}

void dac_write(unsigned char value) {
	static bool initialized = false;

	if(!initialized) {
		gpio_init();
		initialized = true;
	}

	gpioc_write(value);
}

int main(void) {
	/*while(1) {
		for(int i = 0; i <= 8; i++) {
			dac_write(i);
			delay();
		}
	}*/
	while(1) {
		dac_write(0xff);
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
		dac_write(0);
		delay();
		delay();
		delay();
		delay();
		delay();
		delay();
	}
}
