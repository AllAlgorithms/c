#include <stdio.h>
long long int fibo (long long int n){
        if(n==0) 
            return 0;
        else if(n==1)
            return 1;
        else
            return fibo(n-1) + fibo(n-2);
    }

int main () {
    long long int n, total;
    scanf ("%lld", &n);
    total = fibo(n);
    printf ("%d\n", total);
    return 0;
}
