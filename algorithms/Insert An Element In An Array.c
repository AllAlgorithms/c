#include<stdio.h> 
//Function to insert an element in an array.
//arr[] = array, elements = number of elements present in the array
//keyToBeInserted = element to be inserted in the array
// size of the array
int insertElement(int arr[], int elements, int keyToBeInserted, int size) 
{ 
// Check if the capacity of the array is already full 
if (elements >= size) 
return elements; 
//If not then the element is inserted at the last index 
//and the new array size is returned
arr[elements] = keyToBeInserted;   
return (elements + 1); 
}  
// Main Function 
int main() 
{ 
int array[20] = { 31, 27, 3, 54, 67, 31 };
int size = sizeof(array) / sizeof(array[0]); 
int elements = 6; 
int i, keyToBeInserted = 32; 
printf("n Before Insertion: "); 
for (i = 0; i < elements; i++) 
printf("%d  ", array[i]); 
// Calling the function to insert the element in the array
elements = insertElement(array, elements, keyToBeInserted, size); 
printf("n After Insertion: "); 
for (i = 0; i < elements; i++) 
printf("%d  ",array[i]); 
return 0; 
}
