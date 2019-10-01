#include <stdio.h>

// Returns -1 on error, > 0 on success
int get_least_common_multiple(int a, int b) {
    int maximum = 0;

    if (a <= 0 || b <= 0) {
        return -1;
    }
    
    maximum = (a > b)? a : b;
    
    while (1) {
        if ((maximum % a == 0) && (maximum % b == 0)) {
    		break;
		}
		maximum++;
	}

    return maximum;
}

int main()
{
    int a = 0;
    int b = 0;
    int least_common_multiple = 0;

    while (1) {
        printf("give two integers: \n");
        scanf("%d %d", &a, &b);

        if (-1 == (least_common_multiple = get_least_common_multiple(a, b))) {
            fprintf(stderr, "Failed to get least common multiple for %d and %d!\n", a, b);
            continue;
        }

        printf(" least common multiple of %d and %d is %d\n", a, b, least_common_multiple);
    }

    return 0;
}
