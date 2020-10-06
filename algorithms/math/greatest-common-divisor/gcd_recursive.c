#include <stdio.h>

int compGcd(int m, int n){
    if(n==0){return m;}
    compGcd(n, m%n);
}

int main(){
    
    int m, n;
    printf("Enter the two numbers: ");
    scanf("%d %d", &m, &n);

    if(n>m){
        int temp=m;
        m=n;
        n=temp;
    }

    int gcd=compGcd(m, n);
    printf("GCD of %d and %d is: %d\n", m, n, gcd);
    
    return 0;

}