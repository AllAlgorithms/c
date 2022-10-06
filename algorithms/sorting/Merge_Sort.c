#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}	
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(int array[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
        merge_sort(array, l, m);
		merge_sort(array, m + 1, r);
		merge(array, l, m, r);
	}
}


void main(){
    int l;
    printf("Enter Number of Element in Array: ");
    scanf("%d",&l);
    int array[l],i;
    for(i=0;i<l;i++){
        printf("Enter %d Element: ",i+1);
        scanf("%d",&array[i]);
    }

    merge_sort(array,0,l);
    printf("The Sorted Array is: ");
    for(i=0;i<l;i++){
        printf("%d ",array[i]);
    }
}