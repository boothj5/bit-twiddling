#include <stdio.h>

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

BYTE isolate_rightmost(BYTE byte)
{
    // x & (-x)
    BYTE hack = byte & ( -byte);

    return hack;
}

int main(void)
{
    int cont = 1;
    
    while(cont) {
        printf("Choose a test:\n");
        printf("    1: Power of 2.\n");
        printf("    2: 2^n -1 (all bits same).\n");
        printf("    3: Isolate rightmost bit.\n");
        printf("\n");
        printf("> ");

        int choice;
        scanf("%d", &choice);

        printf("\n");
        printf("Enter a byte to test:\n");
        printf("\n");
        printf("> ");
        
        int inp;
        scanf("%d", &inp);

        if (choice == 1) {
            if (is_power_of_two((BYTE)inp)) {
                printf("PASSED.\n");
            } else {
                printf("FAILED.\n");
            }
        } else if (choice == 2) {
            if (all_bits_same((BYTE)inp)) {
                printf("PASSED.\n");
            } else {
                printf("FAILED.\n");
            }
        } else if (choice == 3) {
            printf("%d", (signed int)isolate_rightmost((BYTE)inp));
        } else {
            cont = 0;
        }

        printf("\n");
    }
    
    return 0;
}
