#include <head-unit.h>
#include "testsuite.h"

int main(void)
{
    register_common_tests();
    register_basic_tests();
    run_suite();
    return 0;
}
