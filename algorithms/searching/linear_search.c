#include <stdio.h>
 
/**
* @brief Method to search an element linearly
* @params array the array of integers
* @params size the size of the array
* @params search the item to search in the array
* @returns size if not found else the index of the element
*/
int linear_search(int *array, int size, int search) {
  int c = 0;
  for (c = 0; c < size; c++)
   {
     if (array[c] == search)    /* If required element is found */
     {
       return c;
     }
   }
   return size;
}

/**
* Main Function 
*/
int main()
{
  int array[100], search, c, n;
 
  printf("Enter the number of elements in array\n"); //Enter the number of array elements
  scanf("%d", &n);
 
  printf("Enter %d integer(s)\n", n);
 
  for (c = 0; c < n; c++)
    scanf("%d", &array[c]); //Enter each of the elements in the array
 
  printf("Enter a number to search\n");
  scanf("%d", &search); //Enter the element to be searched
  
  //Calling the linear search method 
  c = linear_search(array, n, search);
 
  if (c == n)
    printf("%d isn't present in the array.\n", search);
  else 
    printf("%d is present at location %d.\n", search, c+1);
 
  return 0;
}
