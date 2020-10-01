// Author: Murilo Ferreira

#include <stdio.h>

int binaryToDecimal(int binary) {
    int decimal = 0;
    int multiplier = 1;
    while (binary != 0) {
        decimal += (binary % 10)* multiplier;
        binary /= 10;
        multiplier *= 2;
    }
    return decimal;
}

int main() {
    int bin;
    printf("Enter your binary number: ");
    scanf("%d" ,&bin);
    int dec = binaryToDecimal(bin);
    printf("The number is: %d \n" ,dec);
    return 0;
}