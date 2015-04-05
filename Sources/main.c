#include "riedd_module/riedd.h"

#define TRUE 1
#define FALSE 0

int main() {
    // Gets a RIEDD module singleton interface and initializes the board
    riedd_module_t* riedd = get_riedd();

    while(TRUE) {
        riedd->do_work(riedd);
    }
}
