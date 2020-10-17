#include<stdio.h>
void main()
{
    int number, rev, i,rem,n;
    rev=0;
    //Taking the inputs
    printf("Enter the number to be reversed");
    scanf(" %d",&number);
    n=number;
    //using while loop
    while((number)!=0)
    {
        rem=number%10;
        number=number/10;
        rev=rev*10+rem;

    }
    printf("The reverse digits of %d is %d",n,rev);
}
