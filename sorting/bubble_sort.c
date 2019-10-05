// C implementation of bubble sort
//
// Author: Carlos Abraham Hernandez


#include <stdio.h>
#include <stdbool.h>  //for bool

// Swap elements
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
  *y = temp;
}

// Implement bubble sort
void bubbleSort(int a[], int n)
{
  int i,j;
  bool swapped;
  for(i = 0; i < n - 1; i++) {
    swapped = false;
    for(j = 0; j < n - i - 1; j++) {
      if(a[j] > a[j + 1]) {
        swap(&a[j], &a[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
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
  int arr[] = {46, 24, 33, 10, 2, 81, 50};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Unsorted array: \n");
	printArray(arr, n);
  bubbleSort(arr, n);
  printf("Sorted array: \n");
  printArray(arr, n);
  return 0;
}
