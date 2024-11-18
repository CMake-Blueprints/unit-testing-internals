#pragma once

#include <mylib.h>

#ifdef __cplusplus
extern "C" {
#endif

    int add_impl(int a, int b);

    int subtract_impl(int a, int b);

    int validate_input(int a, int b);

#ifdef __cplusplus
}
#endif
