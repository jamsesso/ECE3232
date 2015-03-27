#include <stdbool.h>
#include <stdint.h>
#include "fsl_device_registers.h"
#include "gpio.h"
#include "dac.h"
#include "adc.h"

void delay(void) {
	int c = 1, d = 1;

	for (c = 1; c <= 32767; c++)
		for (d = 1; d <= 128; d++) {}
}

int main(void) {
	adc_init();

	while(1) {
		printf("Read %i\n", adc_read());
		delay();
		delay();
		delay();
	}
}
