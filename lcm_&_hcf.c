#include<stdio.h>
//return gcd of two numbers
int gcd(int a, int b) 
{ 
    if (a == 0)
        return b; 
    return gcd(b % a, a); 
} 

// Function to return LCM of two numbers 
int lcm(int a, int b) 
{ 
    return (a / gcd(a, b)) * b;
} 


int main() 
{ 
    printf("Enter the numbers");
    int a,b;
    scanf("%d %d",&a,&b);
    printf("LCM of %d and %d is %d ", a, b, lcm(a, b));
    printf("GCD of %d and %d is %d ", a, b, gcd(a, b));
    return 0; 
} 