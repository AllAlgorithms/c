#include <stdio.h>

// return the nth number of the fibonacci sequence
int fib_n(int n){
    int sequence[n];
    sequence[0] = 0;
    sequence[1] = 1;
    
    n--;

    for(int i = 2; i <= n; i++){
        sequence[i] = sequence[i-2] + sequence[i-1];
    }

    return sequence[n];
}

// fill the fibonacci sequence, into the vector which the pointer sequence points, until the nth number
void fib_sequence(int n, int* sequence){
    sequence[0] = 0; // or *(sequence + 0) or just *sequence
    sequence[1] = 1; // *(sequence + 1)
    
    n--;

    for(int i = 2; i <= n; i++){
        sequence[i] = sequence[i-2] + sequence[i-1];
    }
}

void main(){
    int n = 11;
    //printing the nth number
    printf("%d\n", fib_n(n));

    //printing the fibonacci sequence until the nth number
    int fib[n];
    fib_sequence(n, fib); // since a array is a pointer there's no need to put the & before the variable name
    for(int i = 0; i < 11; i++){
        printf("%d ", fib[i]);
    }
}