#include <stdio.h>
 
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
 
  for (c = 0; c < n; c++)
  {
    if (array[c] == search)    /* If required element is found */
    {
      printf("%d is present at location %d.\n", search, c+1);
      break;
    }
  }
  if (c == n)
    printf("%d isn't present in the array.\n", search);
 
  return 0;
}