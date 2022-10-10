#include <stdio.h>

#define check_power_of_2(x) (!( x & (x - 1)) && (x > 1))

int main()
{
    for(int i = 1; i < 100; i++)
    {
        if(check_power_of_2(i))
            printf("True! %d is a power of 2\n", i);
        else
            printf("False! %d is not a power of 2\n", i);
    }
    printf("Hello World\n");
}