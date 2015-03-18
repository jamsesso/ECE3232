#include "fsl_device_registers.h"
#include <stdio.h>

/*void ADC0_Init() {
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

int mainlab4() {
	ADC0_Init();

	// Now we would read data from RA
	for(unsigned int i = 0; i < 5; ++i) {
		printf("%u: %08x\n", i + 1, ADC0_Convert());
	}

    return 0;
}
*/
