#include <stdio.h>

int main() 
{	
	int n=12;

	while(1)
	{
	  printf("Enter the vaue of n=");
    scanf("%d",&n);
	  if(n==42)
      break;
    else  
	    printf("%d\n",n);
	}
	return 0;
}
