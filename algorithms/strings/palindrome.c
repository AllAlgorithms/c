/* A String is Palindromic if it reads the same forward and backwards
   e.g. racecar
*/

#include <stdio.h>
#include <string.h>
 
int main()
{
  char text[100];
  int begin, middle, end, length = 0;
 
  gets(text);
 
  end = strlen(text) - 1;
 
  for (begin = 0; begin < end/2; begin++)
  {
    if (text[begin] != text[end])
    {
      printf("Not a palindrome.\n");
      break;
    }
    end--;
  }
  if (begin == end/2)
    printf("Palindrome.\n");
 
  return 0;
}
