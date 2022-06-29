#include <stdio.h>
#include <stdlib.h>

// Demo on YouTube: https://www.youtube.com/watch?v=xWBP4lzkoyM

/** Idea behind selection sort: 
  * Find minimum in array
  * Swap with the first
 **/

void SelectionSort(int A[], int size)
{
    int i,j;
	for(i=0; i<size-1; i++)
	{
		int Imin = i;                     // first element selected
		for(j=i+1; j<size; j++)
		{
			if( A[j] < A[Imin] )
			{
				Imin = j;           // minimum found
			}
		}
		int temp = A[Imin];                 // swapped with first element
		A[Imin] = A[i];
		A[i] = temp;
	}
}
int main()
{
    int size=10;
    int i;
    int num[10];
    printf("Enter an array of size 10:\n");
    for(i=0; i<10; i++)
        scanf("%d", &num[i]);
    SelectionSort(num, 10);
    printf("\nAfter Sorting:\n");
    for(i=0; i<10; i++)
        printf("%d\t",num[i]);
    printf("\n");
    return 0;
}
