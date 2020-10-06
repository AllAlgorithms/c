/*
  E.g - x = 7 and y = 3
  After swapping: x = 3 and y = 7
*/

#include <stdio.h> 
int main() 
{ 
	int x = 7, y = 3; 

	// Logic to swap Numbers 
	x = x + y; // x becomes 10
	y = x - y; // y becomes 7 
	x = x - y; // x becomes 3 

	printf("After Swapping: x = %d, y = %d", x, y); 

	return 0; 
} 
