#include "adc.h"

#include <stdbool.h>
#include "fsl_device_registers.h"

void adc_init() {
	static bool is_initialized = false;
	if(!is_initialized) {
		is_initialized = true;

		// Enable the clock the ADC0 module.
		SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;

		HW_ADC_SC2_SET(ADC0, 0x0);
		HW_ADC_SC3_SET(ADC0, 0xF);
	}
}

uint8_t adc_read() {
    ADC0_SC1A = 0x0;
    while(!ADC0_SC1A);

    return ADC0_RA;
}
