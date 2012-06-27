#include <head-unit.h>

#include "common.h"

void test_byte_to_str(void)
{
    assert_string_equals("00000000", byte_to_str((BYTE)0x00));    
    assert_string_equals("00000001", byte_to_str((BYTE)0x01));    
    assert_string_equals("00000010", byte_to_str((BYTE)0x02));    
    assert_string_equals("00000011", byte_to_str((BYTE)0x03));    
    assert_string_equals("00000100", byte_to_str((BYTE)0x04));    
    assert_string_equals("00000101", byte_to_str((BYTE)0x05));    
    assert_string_equals("00010101", byte_to_str((BYTE)0x15));    
    assert_string_equals("00011101", byte_to_str((BYTE)0x1D));    
    assert_string_equals("01111111", byte_to_str((BYTE)0x7F));    
    assert_string_equals("10000000", byte_to_str((BYTE)0x80));    
    assert_string_equals("10000001", byte_to_str((BYTE)0x81));    
    assert_string_equals("10101111", byte_to_str((BYTE)0xAF));    
    assert_string_equals("11111111", byte_to_str((BYTE)0xFF));    
}

void test_str_to_byte(void)
{
    assert_signed_char_equals(0x00, str_to_byte("00000000"));
    assert_signed_char_equals(0x01, str_to_byte("00000001"));
    assert_signed_char_equals(0x02, str_to_byte("00000010"));
    assert_signed_char_equals(0x03, str_to_byte("00000011"));
    assert_signed_char_equals(0x04, str_to_byte("00000100"));
    assert_signed_char_equals(0x05, str_to_byte("00000101"));
    assert_signed_char_equals(0x15, str_to_byte("00010101"));
    assert_signed_char_equals(0x1D, str_to_byte("00011101"));
    assert_signed_char_equals(0x7F, str_to_byte("01111111"));
    assert_signed_char_equals(0x80, str_to_byte("10000000"));
    assert_signed_char_equals(0x81, str_to_byte("10000001"));
    assert_signed_char_equals(0xAF, str_to_byte("10101111"));
    assert_signed_char_equals(0xFF, str_to_byte("11111111"));
}

void register_common_tests(void)
{
    TEST_MODULE("common tests");
    TEST(test_byte_to_str);
    TEST(test_str_to_byte);
}
