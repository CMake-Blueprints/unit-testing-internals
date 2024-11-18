#include <assert.h>
#include <mylib.h>

static void test_mylib_add(void) {
    assert(mylib_add(2, 3) == 5);
    assert(mylib_add(-1, 1) == 0); // Should print an error and return 0
}

static void test_mylib_subtract(void) {
    assert(mylib_subtract(5, 3) == 2);
    assert(mylib_subtract(-1, 1) == 0); // Should print an error and return 0
}

int main(void) {
    test_mylib_add();
    test_mylib_subtract();
    return 0;
}
