#include<stdio.h>
#include<math.h>

int main()
{
    int x,i,flag = 1;
    printf("Enter the number: ");
    scanf("%d",&x);
    for(i = 2; i <= sqrt(x); i++)
    {
        if(!(x % i))
        {   
            flag = 0;
            break;
        }
    }
    if(flag == 1 && x > 1)
    {
        printf("%d is a prime number\n", x);
    }
    else
    {
        printf("%d is not a prime number\n", x);
    }
    return 0;
}