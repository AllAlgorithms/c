// C implementation of quicksort
//
// Author: Murilo Ferreira


#include <stdio.h>

// Swap elements
void swap(int arr[], int a, int b) {
    int aux = arr[a];
    arr[a] = arr[b];
    arr[b] = aux;
}	


//Implement parition algorithm

int partition(int arr[], int a, int b, int pivot) {
    int m = a - 1;
    for(int i = a; i <= b; i++) {
        if (arr[i] <= pivot) {
            m++;
            swap(arr,m,i);
        }
    }
    return m;
}

// Implement quick sort
int *quickSort(int arr[], int a, int b) {
	if (a >= b) return arr;
    int m = partition(arr, a, b, arr[b]);
    quickSort(arr, a, m-1);
    quickSort(arr, m+1, b);
    return arr;
}

// Function to print elements
void printArray(int arr[], int size) {
	int i;
	for (i=0; i < size; i++)
    printf("%d ", arr[i]);
	printf("\n");
}

// test
int main() {
    int arr[] = {46, 24, 33, 10, 2, 81, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array: \n");
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
