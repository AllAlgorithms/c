// C implementation of bubble sort
//
// Author: Carlos Abraham Hernandez


#include <stdio.h>

// Swap elements
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
  *y = temp;
}

// Implement bubble sort
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)
	// last i elements are already in place
		for (j = 0; j < n-i-1; j++)
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
}

// Function to print elements
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
    printf("%d ", arr[i]);
	printf("\n");
}

// test
int main()
{
  int arr[] = {46, 24, 33, 10, 2, 81, 50};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Unsorted array: \n");
	printArray(arr, n);
  bubbleSort(arr, n);
  printf("Sorted array: \n");
  printArray(arr, n);
  return 0;
}
