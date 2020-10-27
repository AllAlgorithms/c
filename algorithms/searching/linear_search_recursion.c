// C Program to implement recursive Linear Search 

#include<stdio.h>
#include<stdlib.h>
/* Recursive function to search an element in arr[l..r] */
int linearSearch(int arr[], int l, int r, int x)
{
     if (r < l)
        return -1;
     if (arr[l] == x)
        return l;
     if (arr[r] == x)
        return r;
     return linearSearch(arr, l+1, r-1, x);
}

int main()
{
    int i,n,a=0;
	printf("Enter the length of an array: ");
	scanf("%d",&n);
	int *arr;
	arr = (int*)malloc(n*sizeof(int));
	printf("\nEnter the elements: ");
	for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
	printf("\nEnter the number to be searched: ");
	scanf("%d",&a);
	int index = linearSearch(arr,0,n,a);
    if (index != -1)
       printf("Element %d is present at index %d", a, index);
    else
        printf("Element %d is not present", a);
    return 0;
}
