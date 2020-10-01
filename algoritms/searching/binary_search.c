// C program to implement recursive Binary Search 
#include <stdio.h> 
  
// A recursive binary search function. It returns  
// location of x in given array arr[l..r] is present,  
// otherwise -1 
int binarySearch(int arr[], int l, int r, int x) 
{ 
   if (r >= l) 
   { 
        int mid = l + (r - l)/2; 
  
        // If the element is present at the middle  
        // itself 
        if (arr[mid] == x)   
            return mid; 
  
        // If element is smaller than mid, then  
        // it can only be present in left subarray 
        if (arr[mid] > x)  
            return binarySearch(arr, l, mid-1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid+1, r, x); 
   } 
  
   // We reach here when element is not  
   // present in array 
   return -1; 
} 
  
int main(void) //take nothing return something
{ 
   int n;
    printf("Enter the number of elements in array\n"); //Enter the number of array elements
    scanf("%d", &n);   
    int arr[n];
    printf("Enter %d integer(s)\n", n);
    for (int c = 0; c < n; c++)
        scanf("%d", &arr[c]); //Enter each of the elements in the array 
   int x = 10; 
   int result = binarySearch(arr, 0, n-1, x); 
   (result == -1)? printf("Element is not present in array") 
                 : printf("Element is present at index %d", 
                                                   result); 
   return 0; 
} 
