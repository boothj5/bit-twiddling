#include <stdio.h>

#define BYTE unsigned

int is_power_of_two(BYTE byte)
{
    // x & (x-1)
    BYTE hack = byte & (byte - 0x01);

    return (hack == 0x00);
}

int all_bits_same(BYTE byte)
{
    // x & (x+1)
    BYTE hack = byte & (byte + 0x01);

    return (hack == 0x00);
}

int main(void)
{
    int cont = 1;
    
    while(cont) {
        printf("Choose a test:\n");
        printf("    1: Power of 2.\n");
        printf("    2: 2^n -1 (all bits same).\n");
        printf("\n");
        printf("> ");

        int choice;
        scanf("%d", &choice);

        printf("\n");
        printf("Enter a number to test:\n");
        printf("\n");
        printf("> ");
        
        int num;
        scanf("%d", &num);
 
        if (choice == 1) {
            if (is_power_of_two(num)) {
                printf("PASSED.\n");
            } else {
                printf("FAILED.\n");
            }
        } else if (choice == 2) {
            if (all_bits_same(num)) {
                printf("PASSED.\n");
            } else {
                printf("FAILED.\n");
            }
        } else {
            cont = 0;
        }

        printf("\n");
    }
}
