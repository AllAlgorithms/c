#include <stdio.h>

int fast_power(int n, int m)
{
    if (0 == m) return 1;
    if (m & 1) // if m is odd
        return n*fast_power(n, m-1);
    else
        return fast_power(n*n, m/2);
}

int main(int argc, char* argv[])
{
    int n, m;
    printf("Enter a number and an exponent: ");
    scanf("%d%d", &n, &m);
    printf("The answer is %d\n", fast_power(n, m));
    return 0;
}
