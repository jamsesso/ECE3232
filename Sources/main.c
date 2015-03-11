#include "fsl_device_registers.h"

#include "fsl_device_registers.h"
#include <stdlib.h>
#include <stdio.h>

// This is ADC things
void adcInit(unsigned short adcNum, int* error) {
	ADC_Type* adcTarget;

	*error = 0;

	switch(adcNum) {
	case 0:
		adcTarget = ADC0;
		// Enable the clock the ADC0 module.
		SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
		break;
	case 1:
		// Enable the clock the ADC1 module.
		SIM_SCGC6 |= SIM_SCGC6_ADC1_MASK;
		adcTarget = ADC1;
		break;
	default:
		// Invalid ADC number.
		*error = -1;
		return;
	}

	HW_ADC_SC2_SET(adcTarget, 0x0);
	HW_ADC_SC3_SET(adcTarget, 0xF);
}

short adcConvert(unsigned short adcNum, int* error) {
	ADC_Type* adcTarget;
	ADC_Type* adcReturn;

	*error = 0;

	switch(adcNum) {
	case 0:
		adcTarget = ADC0_SC1A;
		adcReturn = ADC0_RA;
		break;
	case 1:
		adcTarget = ADC1_SC1A;
		adcReturn = ADC1_RA;
		break;
	default:
		// Invalid ADC number.
		*error = -1;
		return;
	}

	adcTarget = 0x0;

	while(!adcTarget){}

	return adcReturn;
}

int main() {

	return 0;
}
