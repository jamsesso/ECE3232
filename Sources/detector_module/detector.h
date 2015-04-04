#ifndef DETECTOR_MODULE_INCLUDED_H
#define DETECTOR_MODULE_INCLUDED_H

#include <stdbool.h>

typedef struct detector_struct {
	unsigned int threshold;

	void (*calibrate) (struct detector_struct*);
	bool (*is_over_threshold) (struct detector_struct*);
} detector_t;

void init_detector_module();
detector_t* new_detector();

#endif
