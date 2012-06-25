#include <stdio.h>
#include <stdlib.h>

#define BYTE signed char
#define BOOLEAN int
#define TRUE 1
#define FALSE 0

BOOLEAN is_power_of_two(BYTE byte)
{
    // x & (x-1)
    BYTE hack = byte & (byte - 0x01);
    return (hack == 0x00);
}

BOOLEAN all_bits_same(BYTE byte)
{
    // x & (x+1)
    BYTE hack = byte & (byte + 0x01);
    return (hack == 0x00);
}

BYTE isolate_rightmost_set(BYTE byte)
{
    // x & (-x)
    BYTE hack = byte & (-byte);
    return hack;
}

BYTE isolate_rightmost_unset(BYTE byte)
{
    // ¬x & (x+1)
    BYTE hack = ~byte & (byte + 0x01);
    return hack;
}

BYTE identify_trailing_zeroes(BYTE byte)
{
    // ¬x & (x-1)
    BYTE hack = ~byte & (byte - 0x01);
    return hack;
}

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

int main(void)
{
    BOOLEAN cont = TRUE;
    
    while(cont) {
        printf("Choose a test:\n");
        printf("    1: Power of 2.\n");
        printf("    2: 2^n -1.\n");
        printf("    3: Isolate rightmost 1.\n");
        printf("    4: Isolate rightmost 0.\n");
        printf("    5: Identify trailing 0's.\n");
        printf("\n");
        printf("> ");

        int choice;
        scanf("%d", &choice);

        if (choice > 5) break;

        printf("\n");
        printf("Enter a byte to test (as an int -127 to 128):\n");
        printf("\n");
        printf("> ");
        
        int inp;
        scanf("%d", &inp);

        if (choice == 1) {
            if (is_power_of_two((BYTE)inp)) {
                printf("%s -> PASSED", byte_to_str((BYTE)inp));
            } else {
                printf("%s -> FAILED", byte_to_str((BYTE)inp));
            }
        } else if (choice == 2) {
            if (all_bits_same((BYTE)inp)) {
                printf("%s -> PASSED", byte_to_str((BYTE)inp));
            } else {
                printf("%s -> FAILED", byte_to_str((BYTE)inp));
            }
        } else if (choice == 3) {
            signed int result = (signed int)isolate_rightmost_set((BYTE)inp);
            printf("%s -> %s", byte_to_str((BYTE)inp), byte_to_str((BYTE)result));
        } else if (choice == 4) {
            signed int result = (signed int)isolate_rightmost_unset((BYTE)inp);
            printf("%s -> %s", byte_to_str((BYTE)inp), byte_to_str((BYTE)result));
        } else if (choice == 5) {
            signed int result = (signed int)identify_trailing_zeroes((BYTE)inp);
            printf("%s -> %s", byte_to_str((BYTE)inp), byte_to_str((BYTE)result));
        } else {
            break;
        }

        printf("\n");
    }
    
    return 0;
}
