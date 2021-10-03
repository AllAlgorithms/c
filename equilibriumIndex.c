#include <stdio.h>

int findEquilibriumIndex(int a[], int n){
    int right_sum = 0;
    int left_sum = 0;
    for(int i = 0; i < n; i++)
        right_sum += a[i];
    for(int i = 0; i < n; i++) {
        right_sum -= a[i];
        if(right_sum == left_sum) return i;
        left_sum += a[i];
    }
    return -1;
}

int main(){
    // int a[] = {-4, 2, 0, 3, 2, -4}; // ans = 3
    // int a[] = {-2, 0,-2}; // ans = 1
    // int a[] = {3, 0, 2, 0, 4}; // ans = -1
    int a[] = {-3, 2, 4, -5, 1, 3}; // ans = 2
    int n = sizeof(a) / sizeof(int);
    int index = findEquilibriumIndex(a, n);
    printf("Equilibrium Index is: %d\n", index);
    return 0;
}
