#include<stdio.h>

int main()
{
    int a,b;
    printf("\n Enter a,b:(Enter the bigger number first):");
    scanf("%d%d",&a,&b);
    int x=a,y=b;
    int r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    printf("\n LCM :%d",(x*y)/b);
    return 0;
}