
#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {

  int pivot = array[high];

  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);

  return (i + 1);
}

void quick_sort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quick_sort(array, low, pi - 1);
    quick_sort(array, pi + 1, high);
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

    quick_sort(array,0,l);
    printf("The Sorted Array is: ");
    for(i=0;i<l;i++){
        printf("%d ",array[i]);
    }
}