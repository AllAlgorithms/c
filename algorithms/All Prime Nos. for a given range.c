// C program to find the prime numbers 
// between a given interval 

#include <stdio.h> 

int main() 
{ 
	// Declare the variables 
	int a, b, i, j, flag; 

	// Ask user to enter lower value of interval 
	printf("Enter lower bound of the interval: "); 
	scanf("%d", &a); // Take input 

	// Ask user to enter upper value of interval 
	printf("\nEnter upper bound of the interval: "); 
	scanf("%d", &b); // Take input 

	// Print display message 
	printf("\nPrime numbers between %d and %d are: ", a, b); 

	// Traverse each number in the interval 
	// with the help of for loop 
	for (i = a; i <= b; i++) { 
		// Skip 0 and 1 as they are 
		// niether prime nor composite 
		if (i == 1 || i == 0) 
			continue; 

		// flag variable to tell 
		// if i is prime or not 
		flag = 1; 

		for (j = 2; j <= i / 2; ++j) { 
			if (i % j == 0) { 
				flag = 0; 
				break; 
			} 
		} 

		// flag = 1 means i is prime 
		// and flag = 0 means i is not prime 
		if (flag == 1) 
			printf("%d ", i); 
	} 

	return 0; 
} 
