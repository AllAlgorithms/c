#include <stdio.h>
#include <stdlib.h>
void SelectionSort(int A[], int size) //function definition
{
    int i,j;
	for(i=0; i<size-1; i++)             //Loop for checking the lowest number in the array
	{
		int Imin = i;
		for(j=i+1; j<size; j++)         //suppose i<j & when jth element in the array is less than ith element then jth element will become lowest number in the array
		{
			if( A[j] < A[Imin] )
			{
				Imin = j;
			}
		}
		int temp = A[Imin];             //swap the Imin i.e jth element and ith element
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
    SelectionSort(num, 10);         //Function call - Selection sort
    printf("\nAfter Sorting:\n");
    for(i=0; i<10; i++)             //printing the numbers in the sorted manner 
        printf("%d\t",num[i]);
    printf("\n");
    return 0;
}
