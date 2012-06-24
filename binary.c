#include <stdlib.h>

#include "binary.h"

BYTE *new_byte(char str[8])
{
    BYTE *result = malloc(sizeof(byte_t));
    int i;
    for(i = 0; i < 8; i++) {
        if (str[i] == '0') {
            *result[i] = 0;
        } else {
            *result[i] = 1;
        }
    }

    return result;
}

void byte_to_str(BYTE byte, char *str)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (byte[i]) {
            str[i] = '1';
        } else {
            str[i] = '0';
        }
    }
}

