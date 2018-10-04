#include <stdio.h>

#include "conversions.h"

typedef enum {
    BINARY_TO_DECIMAL_MODE,
    DECIMAL_TO_BINARY_MODE,
    EXIT_MODE
} CONVERSION_MODE;

int main(int argc, char** argv) {
    int done = 0;

    while (!done) {
        CONVERSION_MODE selected_mode = EXIT_MODE;

        printf("\n");
        printf("Binary to decimal: [%d]\n", BINARY_TO_DECIMAL_MODE);
        printf("Decimal to binary: [%d]\n", DECIMAL_TO_BINARY_MODE);
        printf("EXIT: [%d]\n", EXIT_MODE);
        printf("Select your mode: ");
    
        scanf("%d", &selected_mode);

        switch (selected_mode) {
            case BINARY_TO_DECIMAL_MODE: {
                int binary = 0;

                printf("Please enter a binary number: ");
                scanf("%d", &binary);

                printf("Converted to decimal: %d\n", binaryToDecimal(binary));
                break;
            }
                
            case DECIMAL_TO_BINARY_MODE: {
                int decimal = 0;

                printf("Please enter a decimal number: ");
                scanf("%d", &decimal);

                printf("Converted to binary: %d\n", decimalToBinary(decimal));
                break;
            }

            case EXIT_MODE:
                done = 1;
                break;

            default:
                printf("Invalid mode!\n");
                break;
        }
    }

    return 0;
}
