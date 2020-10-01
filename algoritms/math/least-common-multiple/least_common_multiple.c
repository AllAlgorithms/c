#include <stdio.h>
int main()
{
    int n1, n2, lcm;
    printf("Enter two positive integers: ");
    scanf("%d %d", &n1, &n2);
    // maximum number between n1 and n2 is stored in lcm
    lcm = (n1>n2) ? n1 : n2;
    // Always true
    while(1)
    {
        if( lcm%n1==0 && lcm%n2==0 )
        {
            printf("The LCM of %d and %d is %d.", n1, n2,lcm);
            break;
        }
        ++lcm;
    }
    return 0;
}