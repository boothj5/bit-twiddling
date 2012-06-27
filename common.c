#include <stdlib.h>

#include "common.h"

char *byte_to_str(BYTE byte)
{
    char *str = malloc(9 * sizeof(char));

    str[0] = (byte & 0x80) ? '1' : '0';
    str[1] = (byte & 0x40) ? '1' : '0';
    str[2] = (byte & 0x20) ? '1' : '0';
    str[3] = (byte & 0x10) ? '1' : '0';
    str[4] = (byte & 0x08) ? '1' : '0';
    str[5] = (byte & 0x04) ? '1' : '0';
    str[6] = (byte & 0x02) ? '1' : '0';
    str[7] = (byte & 0x01) ? '1' : '0';
    str[8] = '\0';

    return str;
}

BYTE str_to_byte(char *str)
{
    BYTE result = 0;

    if (str[0] == '1') { result = result | 0x80; }
    if (str[1] == '1') { result = result | 0x40; }
    if (str[2] == '1') { result = result | 0x20; }
    if (str[3] == '1') { result = result | 0x10; }
    if (str[4] == '1') { result = result | 0x08; }
    if (str[5] == '1') { result = result | 0x04; }
    if (str[6] == '1') { result = result | 0x02; }
    if (str[7] == '1') { result = result | 0x01; }

    return result;
}
