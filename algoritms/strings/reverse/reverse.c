#include <stdio.h>
#include <string.h>

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
            for (i = 3; (i * i) <= x; i += 2) {
                if(0 == (x % i)) {
                    return 0;
                }
            }

            return 1;
        }
    }
}

int main(int argc, char** argv) {
    size_t len = 0;
    size_t i = 0;
    char *to_reverse = NULL;

    if (argc == 1) {
        return 0;
    }

    to_reverse = argv[1];

    len = strlen(to_reverse);

    for (i = len; i > 0; i--) {
        printf("%c", to_reverse[i - 1]);
    }

    printf("\n");

    return 0;
}
