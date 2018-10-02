// C implementation of linear search
//
// Author: Shriharsha KL

#include <stdio.h>

// Implement linear search
int linearSearch(int arr[], int size, int key) {
	for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i;
        }
    }

    return -1;
}

// Function to print elements
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
	printf("\n");
}

// Function to print the result of linear search
void printResult(key, result) {
    if (result == -1) {
        printf("Search Key %d was not found\n\n", key);
    } else {
        printf("Search Key %d was found at position %d\n\n", key, result);
    }
}

// test
int main() {
    int arr[] = { 46, 24, 33, 10, 2, 81, 50 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key1 = 81, result1;
    int key2 = 100, result2;

	printf("Target array: \n\n");
	printArray(arr, n);

    // Key is present in the array
    result1 = linearSearch(arr, n, key1);
    printResult(key1, result1);

    // Key is not present in the array
    result2 = linearSearch(arr, n, key2);
    printResult(key2, result2);

    return 0;
}
