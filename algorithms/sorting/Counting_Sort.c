// Counting sort in C programming

#include <stdio.h>

void counting_sort(int array[], int size) {
  int output[10];

  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  int count[10];

  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
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

    counting_sort(array,l);
    printf("The Sorted Array is: ");
    for(i=0;i<l;i++){
        printf("%d ",array[i]);
    }
}