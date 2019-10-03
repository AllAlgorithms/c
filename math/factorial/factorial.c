#include<stdio.h>
int main()
{
	int i,n,factorial=1;
	printf("Enter the number to find factorial : ");
	scanf("%d",&n);
for(i=1; i<=n; i++)
{
   factorial=factorial*i;
 }
                printf("Factorial : %d\n" ,factorial);
}
