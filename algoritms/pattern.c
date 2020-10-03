// ABCD Pattern
//ABCDEEDCBA
//ABCDDCBA
//ABCCBA
//ABBA
//AA
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char ch='A';
        for(int j=1;j<=n-i;j++)
        {
            printf("%c",ch);
            ch=ch+1;
        }
        ch=ch-1;
        for(int j=1;j<=n-i;j++)
        {
            printf("%c",ch);
            ch=ch-1;
        }
        printf("\n");
    }
    return 0;
}
