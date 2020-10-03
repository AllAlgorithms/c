
// C++ implementation of the approach 
#include <cmath.h> 
#include <stdio.h>  

#define ull unsigned long long int 

// Function to return the binary 
// equivalent of decimal value N 
int decimalToBinary(int N) 
{ 

	// To store the binary number 
	ull B_Number = 0; 
	int cnt = 0; 
	while (N != 0) { 
		int rem = N % 2; 
		ull c = pow(10, cnt); 
		B_Number += rem * c; 
		N /= 2; 

		// Count used to store exponent value 
		cnt++; 
	} 

	return B_Number; 
} 

// Driver code 
int main() 
{ 
  printf("ENTER THE DECIMLA NUMBER");
  
  int N;
    scanf("%d",&N);
  

	printf("EQUIVALENT BINARY IS %d",decimalToBinary(N)); 

	return 0; 
} 
