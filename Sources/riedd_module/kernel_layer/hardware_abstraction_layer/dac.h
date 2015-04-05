#ifndef DAC_MODULE_INCLUDED
#define DAC_MODULE_INCLUDED

#include <stdint.h>

void dac_init();
void dac_write(uint16_t value);

#endif
