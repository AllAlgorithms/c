// C implementation of shellsort
//
// Author: Avigyan Das



#include <stdio.h>


// Implement bubble sort
void shellsort(int arr[], int num)
{
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2)
    {
        for (j = i; j < num; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i] >= arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;
                }
            }
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





//main function
int main()
{
   int arr[] = {46, 24, 33, 10, 2, 81, 50};
	int num = sizeof(arr)/sizeof(arr[0]);
	int k;
	printf("Unsorted array: \n");
	printArray(arr, num);
	printf("\n");
    shellsort(arr, num);
    printf("Sorted array is: \n");
    for (k = 0; k < num; k++)
        printf("%d ", arr[k]);
    return 0;
}