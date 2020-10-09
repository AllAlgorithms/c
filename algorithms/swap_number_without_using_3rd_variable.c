#include <stdio.h> 
int main() 
{ 
	int x,y;
	
        printf("Enter numbers to swap");
	
	scanf("%d %d",&x,&y); /*Takes input*/
	
	printf("Numbers before swapping are x = %d and y = %d",x,y); /* let x=3 and y=4*/
	x = x + y; /*x=3+4=7*/
	y = x - y; /*y=7-4=3*/
	x = x - y; /*x=7-3=4*/

	printf("Numbers after swapping are x = %d, y = %d", x, y); /*x=4 and y=3*/

	return 0; 
} 
