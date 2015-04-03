#include <stdbool.h>
#include "fsl_device_registers.h"

void led_init() {
	// Turn on clock to PortA and PortD module
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTD_MASK;

	//Set the PTA1, PTA2, PTD5 pin multiplexer to GPIO mode ie alternative 1
	PORTA_PCR1 = PORT_PCR_MUX(1);
	PORTA_PCR2 = PORT_PCR_MUX(1);
	PORTD_PCR5 = PORT_PCR_MUX(1);

	// Set the pin direction to output for PORTA1, PORTA2
	GPIOA_PDDR = ~0;
	GPIOD_PDDR = ~0;

	// Set the initial output state of all bits to 1 to turn the LED off
	GPIOA_PSOR = ~0;
	GPIOD_PSOR = ~0;
}

void led_write(bool red_on, bool green_on, bool blue_on) {
	GPIOA_PSOR = ~0;
	GPIOA_PCOR = (red_on << 1) | (green_on << 2);

	GPIOD_PSOR = ~0;
	GPIOD_PCOR = blue_on << 5;
}
