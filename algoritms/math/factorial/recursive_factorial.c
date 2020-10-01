/* 
 * @Author: Abderrezzaq Sendjasni
 * @Email: sendjasni.abderrezzaq@gmail.com
 *
 * Recursive Factorial Code 
 */
#include <stdio.h>

// Recursive function to calculate factorial of a number
unsigned long factorial(int n)
{
	return (n < 1) ? 1 : n * factorial(n - 1);
}

// Program to calculate factorial of a number
int main()
{
	int n = 6;
	printf("The Factorial of %d is %lu", n, factorial(n));

	return 0;
}
