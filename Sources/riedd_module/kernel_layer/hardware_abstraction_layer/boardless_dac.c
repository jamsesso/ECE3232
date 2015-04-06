#include "dac.h"

#include <stdio.h>

// Empty
void dac_init() {}

/**
 * Maximum value: 0xFFF
 * Minimum value: 0
 */
void dac_write(uint16_t value) {
    printf("writing %d to dac\n", value);
}

