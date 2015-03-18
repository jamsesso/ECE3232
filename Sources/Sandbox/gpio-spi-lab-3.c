// LED test program
// ME. Kaye
// Jan. 28, 2015

#include "fsl_device_registers.h"
#include <stdlib.h>
#include <stdio.h>
static int i = 0;

/*void delay(void) {
	int c = 1, d = 1;

	for (c = 1; c <= 32767; c++)
		for (d = 1; d <= 512; d++) {}
}

void rgb_init(void) {
	//Turn on clock to PortB and PortdD module
	// *0x40047000u |=  0x200u | 0x1000u
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTD_MASK;

	//Set the PTA1, PTA2 pin multiplexer to GPIO mode ie alternative 1

	PORTA_PCR1 = PORT_PCR_MUX(1);
	PORTA_PCR2 = PORT_PCR_MUX(1);

	// Set the initial output state of bit 1 high all others to low
	GPIOA_PSOR |= 0x01;
	// Set the pin direction to output for PORTA1, PORTA2
	GPIOA_PDDR |= 6;

}

int mainlab3() {
	printf("starting main\n");

	// Enable clock to SPI1
	SIM_SCGC6 |= SIM_SCGC6_SPI1_MASK;

	// Enable clock to PortD
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;

	// Set the pin multiplexer for Port to SPI1 module mapping on alt 7
	PORTD_PCR4 = PORT_PCR_MUX(7);
	PORTD_PCR5 = PORT_PCR_MUX(7);
	PORTD_PCR6 = PORT_PCR_MUX(7);
	PORTD_PCR7 = PORT_PCR_MUX(7);

	// Set baud to 12
	SPI1_CTAR0 |= SPI_CTAR_BR(12);

	// SPI1 Module Control Register set:
	//    to master mode
	//    MDIS cleared
	//    disable transmit and receive FIFO
	//    HALT cleared
	SPI1_MCR = SPI_MCR_MSTR_MASK;
	SPI1_MCR |= SPI_MCR_DIS_RXF_MASK | SPI_MCR_DIS_TXF_MASK;

	while(1) {
		SPI1_PUSHR = 0x00007777;
		delay();
	}

	return 0;
}

/* Old main
int main(void) {
	rgb_init();

	while(1) {

		GPIOA_PCOR |= 0x01 << 1;
		delay();
		//RED_OFF;

		GPIOA_PSOR |= 0x01 << 1;
		delay();
		GPIOA_PCOR |= 0x01 << 1;
		delay();
		// green only

		GPIOA_PCOR |= 0x01 << 2;
		delay();
		//GREEN_OFF
		GPIOA_PSOR |= 0x01 << 2;
		delay();
		GPIOA_PCOR |= 0x01 << 2;
		delay();

		GPIOA_PCOR |= 0x01 << 3;
		delay();
		//GREEN_OFF
		GPIOA_PSOR |= 0x01 << 3;
		delay();
		GPIOA_PCOR |= 0x01 << 3;
		delay();
	}  // Never leave main

	return 0;
}
*/
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
