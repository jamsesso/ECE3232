#include "dac.h"

#include "fsl_device_registers.h"

void dac_init() {
	// Enable the clock to the DAC.
	SIM_SCGC6 |= SIM_SCGC6_DAC0_MASK;

	DAC0_C0 = DAC_C0_DACRFS_MASK | DAC_C0_DACTRGSEL_MASK;
	DAC0_C1 = 0;

	// Make sure the DAC doesn't start high.
	DAC0_DAT0L = 0;
	DAC0_DAT0H = 0;

	// Enable the DAC module.
	DAC0_C0 |= DAC_C0_DACEN_MASK;
}

/**
 * Maximum value: 0xFFF
 * Minimum value: 0
 */
void dac_write(uint16_t value) {
	// Split the value into 2 so that it can be written into 2 registers.
	char data_lsb = value & 0xFF;
	char data_msb = (value >> 8) & 0xF;

	// Put the data into the DAC registers.
	DAC0_DAT0L = data_lsb;
	DAC0_DAT0H = data_msb;

	// Enable the software trigger on the DAC.
	DAC0_C0 |= DAC_C0_DACSWTRG_MASK;
}
