#include <stdio.h>

// Returns -1 on error, > 0 on success
// Implementation of Stein's Binary GCD algorithm (https://en.wikipedia.org/wiki/Binary_GCD_algorithm)
int get_greatest_common_divisor(int a, int b) {
    if (a <= 0 || b <= 0) {
        return -1;
    }

    if (a == b) {
        return a;
    }

    // If a is even
    if (0 == (a & 0x01)) {
        // ... and b is odd
        if (1 == (b & 0x01)) {
            return get_greatest_common_divisor(a >> 1, b);
        } else { // both a and b are even
            return get_greatest_common_divisor(a >> 1, b >> 1) << 1;
        }
    }

    // If a is odd and b is even
    if (0 == (b & 0x01)) {
        return get_greatest_common_divisor(a, b >> 1);
    }

    // If both a and b are odd, reduce larger argument
    if (a > b) {
        return get_greatest_common_divisor((a - b) >> 1, b);
    }

    return get_greatest_common_divisor((b - a) >> 1, a);
}

int main()
{
    int a = 0;
    int b = 0;
    int greatest_common_divisor = 0;

    while (1) {
        printf("Provide two integers: \n");
        scanf("%d %d", &a, &b);

        if (-1 == (greatest_common_divisor = get_greatest_common_divisor(a, b))) {
            fprintf(stderr, "Failed to get greatest common divisor for %d and %d!\n", a, b);
            continue;
        }

        printf("The greatest common divisor of %d and %d is %d\n", a, b, greatest_common_divisor);
    }

    return 0;
}
