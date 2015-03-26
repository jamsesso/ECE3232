#include "fsl_device_registers.h"

void gpio_init() {
  // Enable the clock to the GPIO module on port C.
  SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;

  // Set the GPIO pins to alternative 1.
  PORTC_PCR0 = PORT_PCR_MUX(1);
  PORTC_PCR1 = PORT_PCR_MUX(1);
  PORTC_PCR2 = PORT_PCR_MUX(1);
  PORTC_PCR3 = PORT_PCR_MUX(1);
  PORTC_PCR4 = PORT_PCR_MUX(1);
  PORTC_PCR5 = PORT_PCR_MUX(1);
  PORTC_PCR6 = PORT_PCR_MUX(1);
  PORTC_PCR7 = PORT_PCR_MUX(1);

  // Set pins to output mode.
  GPIOC_PDDR |= 0xFF;
}

void gpioc_write(unsigned char value) {
  // Set the bits on the GPIO port to match value.
  GPIOC_PSOR = value;
  GPIOC_PCOR = ~value;
}
