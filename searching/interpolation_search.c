// C program to implement interpolation search 
#include<stdio.h> 

// If x is present in arr[0..n-1], then returns 
// index of it, else returns -1. 
int interpolationSearch(int arr[], int n, int x) 
{ 
	// Find indexes of two corners 
	int lo = 0, hi = (n - 1); 

	// Since array is sorted, an element present 
	// in array must be in range defined by corner 
	while (lo <= hi && x >= arr[lo] && x <= arr[hi]) 
	{ 
		if (lo == hi){ 
			if (arr[lo] == x) return lo; 
			return -1; 
		} 
		// Probing the position with keeping 
		// uniform distribution in mind. 
		int pos = lo + (((double)(hi-lo) / 
			(arr[hi]-arr[lo]))*(x - arr[lo])); 

		// Condition of target found 
		if (arr[pos] == x) 
			return pos; 

		// If x is larger, x is in upper part 
		if (arr[pos] < x) 
			lo = pos + 1; 

		// If x is smaller, x is in the lower part 
		else
			hi = pos - 1; 
	} 
	return -1; 
} 

// Driver Code 
int main() 
{ 
	// Array of items on which search will 
	// be conducted. 
	int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 
				24, 33, 35, 42, 47}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	int x = 18; // Element to be searched 
	int index = interpolationSearch(arr, n, x); 

	// If element was found 
	if (index != -1) 
		printf("Element found at index %d", index); 
	else
		printf("Element not found."); 
	return 0; 
} 
