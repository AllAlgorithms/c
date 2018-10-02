// C implementation of insertion sort
//
// Author: Shriharsha KL


#include <stdio.h>

// Swap elements
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
  *y = temp;
}

// Implement insertion sort
void insertionSort(int arr[], int n)
{
  int i, key, j;

  for (i = 1; i < n; ++i) {
    // To the right of the key is unsorted portion of the array
    key = arr[i];
    j = i - 1;
    
    // Start with the first element and move each element in the
    // unsorted portion of the array to the sorted portion in it's
    // correct place
    while(j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
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
  int arr[] = { 46, 24, 33, 10, 2, 81, 50 };
  int n = sizeof(arr) / sizeof(arr[0]);

	printf("Unsorted array: \n");
	printArray(arr, n);
  insertionSort(arr, n);
  printf("Sorted array: \n");
  printArray(arr, n);
  return 0;
}
