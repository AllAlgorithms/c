// C implementation of fibonacci series

#include<stdio.h> 
int fibonacci(int n) 
{ 
if (n <= 1) 
	return n; 
	else { printf("+%d",n);
return fibonacci(n-1) + fibonacci(n-2);} 
} 

int main () 
{ 
  int n;
  printf("Enter your No.");// input will be better
  Scanf("%d",&n);
  print("Calculation=");
  printf("Fibonacci number of %d : %d", n, fibonacci(n)); 
  return 0; 
}
