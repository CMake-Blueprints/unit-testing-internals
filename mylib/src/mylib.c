#include <stdio.h>

#include "mylib_private.h"
#include <mylib.h>

/* Public API */

int mylib_add(int a, int b) {
    if (!validate_input(a, b)) {
        return 0;
    }
    return add_impl(a, b);
}

int mylib_subtract(int a, int b) {
    if (!validate_input(a, b)) {
        return 0;
    }
    return subtract_impl(a, b);
}

/* Private functions */

int add_impl(int a, int b) {
    return a + b;
}

int subtract_impl(int a, int b) {
    return a - b;
}

int validate_input(int a, int b) {
    if (a < 0 || b < 0) {
        printf("Invalid input: negative numbers are not allowed.\n");
        return 0;
    }
    return 1;
}
