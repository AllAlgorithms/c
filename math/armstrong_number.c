/*Armstrong number*/
#include<stdio.h>
#include<math.h>
int main()
{
	int num,i,sum=0,count,s,m;
	printf("Enter the number:");
	scanf("%d",&num);
	count=0;
	s=num;
	sum=0;
	while(s>0)
	{
		s/=10;
		count++;
	}
	s=num;
	while(s>0)
	{
		m=s%10;
		sum=sum+pow(m,count);
		s/=10;
	}
	if(sum==num)
		printf("%d is an Armstrong Number!\n",num);
	else
		printf("%d is not an Armstrong Number!\n",num);
	
	return 0;
}
