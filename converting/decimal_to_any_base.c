/*Conversion from decimal to any base*/
#include<stdio.h>
int main()
{
	int  num,m,p,base,r=0;
	char a[100];
	printf("Enter the number which you want to convert:");
	scanf("%d",&num);
	printf("\nEnter the base in which you want to convert:");
	scanf("%d",&base);
	while(num>0)
	{
		m=num%base;
		p='0'+m;
		if(p>'9')
			p=p+7;
		a[r]=p;
		r++;
		num=num/base;	
	}
	for(int k=r-1;k>=0;k--)
		printf("%c",a[k]);
	return 0;
}
