#include<stdio.h>  
int temp;  
  
void heapify(int arr[], int size, int i)  
{  
int largest = i;    
int left = 2*i + 1;    
int right = 2*i + 2;    
  
if (left < size && arr[left] >arr[largest])  
largest = left;  
  
if (right < size && arr[right] > arr[largest])  
largest = right;  
  
if (largest != i)  
{  
temp = arr[i];  
    arr[i]= arr[largest];   
    arr[largest] = temp;  
heapify(arr, size, largest);  
}  
}  
  
void heapSort(int arr[], int size)  
{  
int i;  
for (i = size / 2 - 1; i >= 0; i--)  
heapify(arr, size, i);  
for (i=size-1; i>=0; i--)  
{  
temp = arr[0];  
    arr[0]= arr[i];   
    arr[i] = temp;  
heapify(arr, i, 0);  
}  
}  
  
void main()  
{  
int arr[] = {1, 10, 2, 3, 4, 1, 2, 100,23, 2};  
int i;  
int size = sizeof(arr)/sizeof(arr[0]);  
  
heapSort(arr, size);  
  
printf("printing sorted elements\n");  
for (i=0; i<size; ++i)  
printf("%d\n",arr[i]);  
}  
