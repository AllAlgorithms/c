/* 
*   Author: Phyllipe Bezerra (https://github.com/pmba)
*/

#include <stdio.h>
#include <stdlib.h>

#define INT_MIN -2147483647-1
#define max(a, b) a >= b ? a : b

void countSort(int arr[], int size);

int main() {

    int arr[] = {0, 10, 17, 4, 1, 97 , 113, 240};

    countSort(arr, 8);

    return 0;
}

void countSort(int arr[], int size) {
    int max_value = INT_MIN;
    int i;

    for (i = 0; i < size; ++i) {
        max_value = max(max_value, arr[i]);
    }

    int aux[max_value+1];

    for (i = 0; i < max_value+1; ++i) aux[i] = 0;

    for (i = 0; i < size; ++i) {
        aux[arr[i]] = 1;
    }

    for (i = 0; i < max_value+1; ++i) {
        if (aux[i] != 0) {
            printf("%d ", i);
        }
    }

    printf("\n");
}