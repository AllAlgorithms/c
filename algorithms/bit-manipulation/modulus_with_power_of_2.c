/*
    1. Here is an example of the modulus operation
    using bit manipulation
    2. It is supposed to be much faster and more efficient
    The only condition is that n should be a power of 2
*/

#include <stdio.h>

#define modulo(x,n) ((x) & (n - 1))

int main()
{
    printf("Hello World\n");
    
    for(int i = 0; i < 100; i++)
        printf("value of %d modulo 8 is: %d\n", i, modulo(i,10));

    return 0;
}
