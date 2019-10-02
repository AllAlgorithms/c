#include <stdio.h>

// Returns 1 if the given number is prime, 0 otherwise 
int is_prime(int x) {
   if(x%2==0){
       return 1;
   }
    else{
        return 0;
    }
}


int main()
{
    int x = 0;
    int i=0;
    while (1) {
        printf("Provide an integer: \n");
        scanf("%d", &x);

       i=is_prime(x);
        if(i==1){
            printf("prime");
        }
        else{
            printf("not prime");
        }

    }

    return 0;
}
