//**************************************
// C implementation of recursive selection sort
//
// Author: Rafael Rodrigues Silva
//**************************************

#include<stdio.h>

// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

///selection
int search_smallest(int V[],int i,int j,int smallest){
    if(i<=j)
        return smallest;

    if(V[smallest]>V[j])
        smallest=j;
    search_smallest(V,i,j+1,smallest);
}

void recursive_selection_sort(int V[],int vt,int index){
    if(index>=vt)
        return;

    int smallest=search_smallest(V,vt,index,index);

    if(V[index]!=V[smallest])
        swap(&V[index],&V[smallest]);
    recursive_selection_sort(V,vt,index+1);
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    recursive_selection_sort(arr,n,0);
    printArray(arr, n); 
  
    return 0; 
} 