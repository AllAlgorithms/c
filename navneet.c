#include<stdio.h>
void main()
{
    int num,binary,base,remainder,decimal;
    base=1;
    binary=0;
    printf("Enter the decimal number");
    scanf(" %d",&num);
    decimal=num;
    //using logic
    while((num)!=0)
    {
        remainder=num%2;
        num=num/2;
        binary=binary+remainder*base;
        base=base*10;

    }
    printf("the decimal no. is  %d\n",decimal);
    printf("the binary no is %d",binary);

}
