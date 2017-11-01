#include "decript.h"

long int search_inverse_mod (long int e, long int module) {

    if (module == 1) {

        return (long int)(e / module);
    }
    else {
        return search_inverse_mod(module, e % module);
    }
}

long int extract_root_mod (long int M, long int d) {

    return pow(M, d);
}

void decript () {

    // code here
}
