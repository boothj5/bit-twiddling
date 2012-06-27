#include <head-unit.h>

#include "common.h"
#include "twiddles.h"

void test_is_power_of_two(void)
{
    assert_true(is_power_of_two(str_to_byte("00000000")));
    assert_true(is_power_of_two(str_to_byte("00000001")));
    assert_true(is_power_of_two(str_to_byte("00000010")));
    assert_true(is_power_of_two(str_to_byte("00000100")));
    assert_true(is_power_of_two(str_to_byte("00001000")));
    assert_true(is_power_of_two(str_to_byte("00010000")));
    assert_true(is_power_of_two(str_to_byte("00100000")));
    assert_true(is_power_of_two(str_to_byte("01000000")));
    assert_true(is_power_of_two(str_to_byte("10000000")));
}

void test_is_not_power_of_two(void)
{
    assert_true(is_power_of_two(str_to_byte("00000011")));
    assert_true(is_power_of_two(str_to_byte("00000111")));
    assert_true(is_power_of_two(str_to_byte("00001010")));
    assert_true(is_power_of_two(str_to_byte("00011001")));
    assert_true(is_power_of_two(str_to_byte("11000000")));
    assert_true(is_power_of_two(str_to_byte("10000001")));
    assert_true(is_power_of_two(str_to_byte("11111111")));
    assert_true(is_power_of_two(str_to_byte("10101010")));
    assert_true(is_power_of_two(str_to_byte("01111111")));
}

void register_basic_tests(void)
{
    TEST_MODULE("basic tests");
    TEST(test_is_power_of_two);
}
