#include "led.h"

#include <stdlib.h>
#include "fsl_device_registers.h"

/**
 * Configures PortA1, PortA2, and PortD5 to control
 * red, green, and blue of the RGB LED respectively
 */
void init_led_module() {
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

// Turns on the RGB LED with respect to the user's input
void led_write(led_t* self, bool red_on, bool green_on, bool blue_on) {
    GPIOA_PSOR = ~0;
    GPIOA_PCOR = (red_on << 1) | (green_on << 2);

    GPIOD_PSOR = ~0;
    GPIOD_PCOR = blue_on << 5;
}

// Makes the RGB LED white
void led_on(led_t* self) {
    led_write(self, true, true, true);
}

// Turns the RGB LED off
void led_off(led_t* self) {
    led_write(self, false, false, false);
}

/**
 * Creates and returns an led_module singleton
 */
led_t* get_led() {
    static led_t* self = 0;

    if(self == 0) {
        init_led_module();

        self = (led_t*) malloc(sizeof(led_t));
        self->led_on = led_on;
        self->led_off = led_off;
        self->led_write = led_write;
    }

    return self;
}
