#include <assert.h>
#include <mylib_private.h>

static void test_add_impl(void) {
    assert(add_impl(2, 3) == 5);
    assert(add_impl(-1, 1) == 0); // This test is not valid as add_impl does not check for negative numbers
}

static void test_subtract_impl(void) {
    assert(subtract_impl(5, 3) == 2);
    assert(subtract_impl(-1, 1) == -2); // This test is not valid as subtract_impl does not check for negative numbers
}

static void test_validate_input(void) {
    assert(validate_input(2, 3) == 1);
    assert(validate_input(-1, 1) == 0);
}

int main(void) {
    test_add_impl();
    test_subtract_impl();
    test_validate_input();
    return 0;
}
