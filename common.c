#include <stdlib.h>

#include "common.h"

char *byte_to_str(BYTE byte)
{
    char *str = malloc(9 * sizeof(char));

    str[0] = (( byte & 0x80 ) != 0) ? '1' : '0';
    str[1] = (( byte & 0x40 ) != 0) ? '1' : '0';
    str[2] = (( byte & 0x20 ) != 0) ? '1' : '0';
    str[3] = (( byte & 0x10 ) != 0) ? '1' : '0';
    str[4] = (( byte & 0x08 ) != 0) ? '1' : '0';
    str[5] = (( byte & 0x04 ) != 0) ? '1' : '0';
    str[6] = (( byte & 0x02 ) != 0) ? '1' : '0';
    str[7] = (( byte & 0x01 ) != 0) ? '1' : '0';
    str[8] = '\0';

    return str;
}

