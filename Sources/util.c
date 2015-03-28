#ifndef UTIL_MODULE_INCLUDED
#define UTIL_MODULE_INCLUDED 1

void delay(void) {
	int c = 1, d = 1;

	for (c = 1; c <= 32767; c++)
		for (d = 1; d <= 4096; d++) {}
}

#endif
