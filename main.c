#include <stdio.h>

#include "common.h"
#include "twiddles.h"

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
        printf("    6: Identify rigthmost 1 and trailing 0's.\n");
        printf("\n");
        printf("> ");

        int choice;
        scanf("%d", &choice);

        if (choice < 1 || choice > 6) break;

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
        } else if (choice == 6) {
            signed int result = (signed int)identify_rightmost_set_and_trailing_unset((BYTE)inp);
            printf("%s -> %s", byte_to_str((BYTE)inp), byte_to_str((BYTE)result));
        } else {
            break;
        }

        printf("\n");
    }
    
    return 0;
}
