#include "util.h"

void sleep(unsigned long ms) {
	unsigned long long counter = 0;
	unsigned long clock = 120000;

	for(counter = 0; counter < ms * clock; counter++) {}
}
