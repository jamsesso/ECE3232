#include "gpio.h"

#include <stdbool.h>
#include "fsl_device_registers.h"


void gpio_c_init() {
	static bool is_initialized = false;
	if(!is_initialized) {
		is_initialized = true;

		// Enable the clock to the GPIO module on port C.
		SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;

		// Set the GPIO pins to alternative 1.
		PORTC_PCR0 = PORT_PCR_MUX(1);
		PORTC_PCR7 = PORT_PCR_MUX(1);

		// Set pins to input mode.
		GPIOC_PDDR = 0x00;
	}
}

int gpio_c_read() {
    // Set the bits on the GPIO port to match value.
    return GPIOC_PDIR;
}
