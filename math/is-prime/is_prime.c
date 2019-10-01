#include <stdio.h>

// Returns 1 if the given number is prime, 0 otherwise 
int is_prime(unsigned long x) {
    switch (x) {
        case 0:
        case 1:
            return 0;

        case 2:
            return 1;

        default: {
            unsigned int i = 0;
            // Multiples of 2 are not prime
            if (0 == (x % 2)) {
                return 0;
            }

            // Test odd numbers from 3 up to the square root of x
            for (i = 3; (i * i) <= x; i =i+2) {
                if(0 == (x % i)) {
                    return 0;
                }
            }

            return 1;
        }
    }
}

int main()
{
    unsigned long x = 0;

    while (1) {
        printf("Provide an integer: \n");
        scanf("%lu", &x);

        printf("%lu is%s prime\n", x, is_prime(x) ? "" : " not");

    }

    return 0;
}
