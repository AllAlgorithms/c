// C implementation of binary search
//
// Author: Murilo Ferreira


#include <stdio.h>
#include <math.h>

// Implement binary search
int binarySearch(int arr[], int a, int b, int x) {
    if (a > b) return -1; // Couldn't find the searched number
    int m = floor((a+b)/2);
    if (x == arr[m]) return m;
    if (x < arr[m]) return binarySearch(arr, a, m-1, x);
    return binarySearch(arr, m+1, b, x);
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
    int arr[] = {-37, -12, 3, 5, 9, 18, 38, 76, 102};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Tested array\n");
    printArray(arr, n);
    int i;
    printf("Which number would you like to search? \n");
    scanf("%d" ,&i);
    int index = binarySearch(arr, 0, n-1, i);
    printf("Number index: %d \n" ,index);
    return 0;
}
