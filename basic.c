#include "common.h"

BOOLEAN is_power_of_two(BYTE byte)
{
    // x & (x-1)
    BYTE result = byte & (byte - 0x01);
    return (result == 0x00);
}

BOOLEAN all_bits_same(BYTE byte)
{
    // x & (x+1)
    BYTE result = byte & (byte + 0x01);
    return (result == 0x00);
}

BYTE isolate_rightmost_set(BYTE byte)
{
    // x & (-x)
    BYTE result = byte & (-byte);
    return result;
}

BYTE isolate_rightmost_unset(BYTE byte)
{
    // ¬x & (x+1)
    BYTE result = ~byte & (byte + 0x01);
    return result;
}

BYTE identify_trailing_zeroes(BYTE byte)
{
    // ¬x & (x-1)
    BYTE result = ~byte & (byte - 0x01);
    return result;
}

BYTE identify_rightmost_set_and_trailing_unset(BYTE byte)
{
    // x ^ (x-1)
    BYTE result = byte ^ (byte - 0x01);
    return result;
}

