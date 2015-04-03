#include "gpio.h"
#include "fsl_device_registers.h"
#include <stdbool.h>

bool is_idling() {
	return gpio_c_read();
}
