//**************************************
// C implementation of quick sort
//**************************************

#include<stdio.h>
void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}


// test
int main()
{
    int arr[] = {46, 24, 33, 10, 2, 81, 50};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Unsorted array: \n");
	printArray(arr, n);
    quicksort(arr,0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}