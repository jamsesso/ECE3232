#include "fsl_device_registers.h"
#include "gpio.h"

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
		for (d = 1; d <= 16; d++) {}
}

void dac_write(unsigned char value) {
	static short i = 0;

	if(i == 0) {
		gpio_init();
		i = 1;
	}

	gpioc_write(value);
}

int main(void) {
	/*int value = 0;

	ADC0_Init();

	while(1) {
		value = ADC0_Convert();
		printf("%d\n", value);
		delay();
	}*/

	dac_write(16);
}
