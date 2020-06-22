#include<stdio.h>
void factorial(int n)
{
    if(n <= 0)
    {
        printf("\n Does not have factorial");
    }
    else
    {
        int f=1;
        while(n)
        {
            f+=f*n;
            n--;
        }
        printf("\n Factorial of the number:%d",f);
    }
}
int main()
{
    int n;
    printf("\n Enter the value of n:");
    scanf("%d",&f)
}