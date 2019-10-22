#include <stdio.h>

// Returns 1 if the given number is prime, 0 otherwise 
int is_prime(unsigned long x) {
    int i;
    if(x==0 || x==1)return 0;
    else{
        //"div" counts the number of divisors of x
        char div=49;
        for(i=2; i<=x; i++){
            if(x%i==0) div++;
            if(div>50) return 0;
        }
    }
    return 1;
}

int main()
{
    unsigned long x = 0;

    while (1) {
        printf("Provide an integer: \n");
        scanf("%lu", &x);
        printf("%lu is%s prime\n\n", x, is_prime(x)?"":" not");
    }

    return 0;
}
