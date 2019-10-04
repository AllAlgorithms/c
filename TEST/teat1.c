#include <stdio.h>

int main(void) 
{	
	int n=12;

	while(1)
	{
	  scanf("%d",&n);
	   if(n==42)
	   break;
	  else  
	    printf("%d\n",n);
	}
	return 0;
}
