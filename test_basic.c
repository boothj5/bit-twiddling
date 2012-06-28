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
    assert_false(is_power_of_two(str_to_byte("00000011")));
    assert_false(is_power_of_two(str_to_byte("00000111")));
    assert_false(is_power_of_two(str_to_byte("00001010")));
    assert_false(is_power_of_two(str_to_byte("00011001")));
    assert_false(is_power_of_two(str_to_byte("11000000")));
    assert_false(is_power_of_two(str_to_byte("10000001")));
    assert_false(is_power_of_two(str_to_byte("11111111")));
    assert_false(is_power_of_two(str_to_byte("10101010")));
    assert_false(is_power_of_two(str_to_byte("01111111")));
}

void test_all_bits_same(void)
{
    assert_true(all_bits_same(str_to_byte("00000000")));
    assert_true(all_bits_same(str_to_byte("11111111")));
    assert_true(all_bits_same(str_to_byte("00000001")));
    assert_true(all_bits_same(str_to_byte("00000011")));
    assert_true(all_bits_same(str_to_byte("00000111")));
    assert_true(all_bits_same(str_to_byte("00001111")));
    assert_true(all_bits_same(str_to_byte("00011111")));
    assert_true(all_bits_same(str_to_byte("00111111")));
    assert_true(all_bits_same(str_to_byte("01111111")));
}

void test_not_all_bits_same(void) // leading zeros are ignored
{
    assert_false(all_bits_same(str_to_byte("00000101")));
    assert_false(all_bits_same(str_to_byte("00010101")));
    assert_false(all_bits_same(str_to_byte("10000000")));
    assert_false(all_bits_same(str_to_byte("11111101")));
    assert_false(all_bits_same(str_to_byte("00100100")));
    assert_false(all_bits_same(str_to_byte("11111110")));
    assert_false(all_bits_same(str_to_byte("10101010")));
}

void test_isolate_rightmost_set(void)
{
    assert_string_equals(
        "00000000", byte_to_str(isolate_rightmost_set(str_to_byte(
        "00000000"))));
    assert_string_equals(
        "00000001", byte_to_str(isolate_rightmost_set(str_to_byte(
        "00000001"))));
    assert_string_equals(
        "00000001", byte_to_str(isolate_rightmost_set(str_to_byte(
        "10000001"))));
    assert_string_equals(
        "00000001", byte_to_str(isolate_rightmost_set(str_to_byte(
        "11111111"))));
    assert_string_equals(
        "00001000", byte_to_str(isolate_rightmost_set(str_to_byte(
        "11011000"))));
    assert_string_equals(
        "00010000", byte_to_str(isolate_rightmost_set(str_to_byte(
        "00010000"))));
    assert_string_equals(
        "01000000", byte_to_str(isolate_rightmost_set(str_to_byte(
        "11000000"))));
    assert_string_equals(
        "10000000", byte_to_str(isolate_rightmost_set(str_to_byte(
        "10000000"))));
    assert_string_equals(
        "00100000", byte_to_str(isolate_rightmost_set(str_to_byte(
        "10100000"))));
}

void test_isolate_rightmost_unset(void)
{
    assert_string_equals(
        "00000001", byte_to_str(isolate_rightmost_unset(str_to_byte(
        "00000000"))));
    assert_string_equals(
        "00000010", byte_to_str(isolate_rightmost_unset(str_to_byte(
        "00000001"))));
    assert_string_equals(
        "00000010", byte_to_str(isolate_rightmost_unset(str_to_byte(
        "10000001"))));
    assert_string_equals(
        "00000001", byte_to_str(isolate_rightmost_unset(str_to_byte(
        "00000100"))));
    assert_string_equals(
        "00000001", byte_to_str(isolate_rightmost_unset(str_to_byte(
        "11011000"))));
    assert_string_equals(
        "00000100", byte_to_str(isolate_rightmost_unset(str_to_byte(
        "00010011"))));
    assert_string_equals(
        "00001000", byte_to_str(isolate_rightmost_unset(str_to_byte(
        "11000111"))));
    assert_string_equals(
        "01000000", byte_to_str(isolate_rightmost_unset(str_to_byte(
        "10111111"))));
    assert_string_equals(
        "00010000", byte_to_str(isolate_rightmost_unset(str_to_byte(
        "10101111"))));
}

void test_identify_trailing_zeroes(void)
{
    assert_string_equals(
        "00000000", byte_to_str(identify_trailing_zeroes(str_to_byte(
        "11111111"))));
    assert_string_equals(
        "00000001", byte_to_str(identify_trailing_zeroes(str_to_byte(
        "11111110"))));
    assert_string_equals(
        "00000011", byte_to_str(identify_trailing_zeroes(str_to_byte(
        "11111100"))));
    assert_string_equals(
        "00000011", byte_to_str(identify_trailing_zeroes(str_to_byte(
        "00000100"))));
    assert_string_equals(
        "00000111", byte_to_str(identify_trailing_zeroes(str_to_byte(
        "00101000"))));
    assert_string_equals(
        "01111111", byte_to_str(identify_trailing_zeroes(str_to_byte(
        "10000000"))));
}

void test_identify_rightmost_set_and_trailing_zeroes(void)
{
    assert_string_equals(
        "11111111", byte_to_str(identify_rightmost_set_and_trailing_unset(str_to_byte(
        "00000000"))));
    assert_string_equals(
        "00000001", byte_to_str(identify_rightmost_set_and_trailing_unset(str_to_byte(
        "11111111"))));
    assert_string_equals(
        "00011111", byte_to_str(identify_rightmost_set_and_trailing_unset(str_to_byte(
        "11110000"))));
    assert_string_equals(
        "00011111", byte_to_str(identify_rightmost_set_and_trailing_unset(str_to_byte(
        "10010000"))));
    assert_string_equals(
        "00111111", byte_to_str(identify_rightmost_set_and_trailing_unset(str_to_byte(
        "10100000"))));
}

void register_basic_tests(void)
{
    TEST_MODULE("basic tests");
    TEST(test_is_power_of_two);
    TEST(test_is_not_power_of_two);
    TEST(test_all_bits_same);
    TEST(test_not_all_bits_same);
    TEST(test_isolate_rightmost_set);
    TEST(test_isolate_rightmost_unset);
    TEST(test_identify_trailing_zeroes);
    TEST(test_identify_rightmost_set_and_trailing_zeroes);
}
