#ifndef IDLE_MODULE_INCLUDED_H
#define IDLE_MODULE_INCLUDED_H

#include <stdbool.h>

typedef struct idle_struct {
    /**
     * Checks the appropriate port to see if the module should be idling
     */
    bool (*is_idling) (struct idle_struct*);
} idle_t;

/**
 * Creates and returns an idle_module singleton
 */
idle_t* get_idle();

#endif
