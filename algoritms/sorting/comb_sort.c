//
// Comb sort works to sort an array.
// More documentation about the algorithm
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/
// https://github.com/allalgorithms/cpp
//
// Contributed by: Ujwal Kandi
// Github: @UjwalKandi
//

#include <cstdio>
#include <stdlib.h>
 
/*Function to find the new gap between the elements*/
int newgap(int gap)
{
    gap = (gap * 10) / 13;
    if (gap == 9 || gap == 10)
        gap = 11;
    if (gap < 1)
        gap = 1;
    return gap;
}
 
/*Function to implement the combsort*/
void combsort(int a[], int aSize)
{
    int gap = aSize;
    int temp, i;
    for (;;)
    {
        gap = newgap(gap);
        int swapped = 0;
        for (i = 0; i < aSize - gap; i++) 
        {
            int j = i + gap;
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                swapped  =  1;
            }
        }
        if (gap  ==  1 && !swapped)
            break;
    }
}
int main ()
{
    int n, i;
    int *a;
    printf("Enter total no. of elements : ");
    scanf("%d", &n);       // The total number of elements
    a  =  (int *)calloc(n, sizeof(int));
    for (i = 0;i< n;i++)
    {
        printf("Input element %d :", i);
        scanf("%d", &a[i]); // Adding the elements to the array
    }
    printf("\nUnsorted list: ");       // Displaying the unsorted array
    for(i = 0;i < n;i++)
    {
         printf("%d ", a[i]);
    }
    combsort(a, n);
    printf("\nSorted list: ");        // Display the sorted array
    for(i = 0;i < n;i++)
    {
        printf("%d ", (a[i]));
    }
    return 0;
}
