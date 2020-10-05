#include<stdio.h>
void factorial(int n)
{
    if(n <0)
    {
        printf("\n factorial does not exist");
    }
    else
    {
        int f=1;
        while(n)
        {
            f=f*n;
            n--;
        }
        printf("\n Factorial of the number is:%d",f);
    }
     
}
int main()
{
    int n;
    printf("\n Enter the value of n:");
    scanf("%d",&n);
    factorial(n);
    return 0;
}
