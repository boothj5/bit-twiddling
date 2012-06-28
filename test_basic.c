#include <head-unit.h>

#include "common.h"
#include "twiddles.h"

static void assert_twiddle(BYTE (*twiddle)(BYTE), char *input, char* output)
{
    assert_string_equals(output, byte_to_str(twiddle(str_to_byte(input))));
}

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
    assert_twiddle(isolate_rightmost_set, 
        "00000000", 
        "00000000");

    assert_twiddle(isolate_rightmost_set, 
        "00000001", 
        "00000001");

    assert_twiddle(isolate_rightmost_set, 
        "10000001", 
        "00000001");

    assert_twiddle(isolate_rightmost_set, 
        "11111111",
        "00000001");

    assert_twiddle(isolate_rightmost_set,
        "11011000", 
        "00001000");

    assert_twiddle(isolate_rightmost_set,
        "00010000", 
        "00010000");

    assert_twiddle(isolate_rightmost_set,
        "11000000", 
        "01000000"); 

    assert_twiddle(isolate_rightmost_set,
        "10000000",
        "10000000");

    assert_twiddle(isolate_rightmost_set,
        "10100000", 
        "00100000");
}

void test_isolate_rightmost_unset(void)
{
    assert_twiddle(isolate_rightmost_unset,
        "00000000", 
        "00000001");

    assert_twiddle(isolate_rightmost_unset,
        "00000001",
        "00000010");

    assert_twiddle(isolate_rightmost_unset,
        "10000001",
        "00000010");

    assert_twiddle(isolate_rightmost_unset,
        "00000100",
        "00000001");

    assert_twiddle(isolate_rightmost_unset,
        "11011000", 
        "00000001");

    assert_twiddle(isolate_rightmost_unset, 
        "00010011", 
        "00000100");

    assert_twiddle(isolate_rightmost_unset,
        "11000111",
        "00001000");

    assert_twiddle(isolate_rightmost_unset,
        "10111111", 
        "01000000");

    assert_twiddle(isolate_rightmost_unset,
        "10101111", 
        "00010000");
}

void test_identify_trailing_zeroes(void)
{
    assert_twiddle(identify_trailing_zeroes,
        "11111111", 
        "00000000");

    assert_twiddle(identify_trailing_zeroes,
        "11111110", 
        "00000001");

    assert_twiddle(identify_trailing_zeroes,
        "11111100",
        "00000011");

    assert_twiddle(identify_trailing_zeroes,
        "00000100",
        "00000011");

    assert_twiddle(identify_trailing_zeroes,
        "00101000",
        "00000111");

    assert_twiddle(identify_trailing_zeroes,
        "10000000",
        "01111111");
}

void test_identify_rightmost_set_and_trailing_zeroes(void)
{
    assert_twiddle(identify_rightmost_set_and_trailing_unset,
        "00000000", 
        "11111111");

    assert_twiddle(identify_rightmost_set_and_trailing_unset,
        "11111111", 
        "00000001");

    assert_twiddle(identify_rightmost_set_and_trailing_unset,
        "11110000",
        "00011111");

    assert_twiddle(identify_rightmost_set_and_trailing_unset,
        "10010000", 
        "00011111");

    assert_twiddle(identify_rightmost_set_and_trailing_unset,
        "10100000", 
        "00111111");
}

void test_propogate_rightmost_set(void)
{
    assert_twiddle(propogate_rightmost_set,
        "00000000", 
        "11111111");

    assert_twiddle(propogate_rightmost_set,
        "11111111",
        "11111111");

    assert_twiddle(propogate_rightmost_set,
        "00000001", 
        "00000001");   

    assert_twiddle(propogate_rightmost_set,
        "00000011", 
        "00000011");

    assert_twiddle(propogate_rightmost_set,
        "00000010", 
        "00000011");

    assert_twiddle(propogate_rightmost_set,
        "00101000", 
        "00101111");

    assert_twiddle(propogate_rightmost_set,
        "01100000",
        "01111111");   

    assert_twiddle(propogate_rightmost_set,
        "10000000",
        "11111111");
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
    TEST(test_propogate_rightmost_set);
}
