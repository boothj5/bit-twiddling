#ifndef __H_BINARY
#define __H_BINARY

#define BYTE byte_t

typedef int byte_t[8];

BYTE *new_byte(char str[8]);
void byte_to_str(BYTE byte, char *str);

#endif
