# include <stdio.h> 
# include <math.h> 
  
//find prime factors
void primeFactors(int n) 
{ 

    int flag = 0;
    if (n%2==0)
        printf("%d ", 2);
    while (n%2 == 0)
    { 
        n = n/2; 
    } 
    
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        flag = 0;
        while (n%i == 0) 
        { 
            flag = 1;
            n = n/i; 
        } 
        if(flag)
            printf("%d ", i); 
    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2) 
        printf ("%d ", n);
} 
  
int main() 
{ 
    int n = 315; 
    printf("Enter a number whose prime factor needs to be find out\n");
    scanf("%d",&n);
    primeFactors(n); 
    return 0; 
} 
