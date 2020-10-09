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
// added another method
#include <math.h>
#include <stdio.h>
int convert(long long n);
int main() {
    long long n;
    printf("Enter a binary number: ");
    scanf("%lld", &n);
    printf("%lld in binary = %d in decimal", n, convert(n));
    return 0;
}

int convert(long long n) {
    int dec = 0, i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}
