/*Used to set all characters in a string to a given character*/
#include<stdio.h>
#include<string.h>
int main()
{
   char str[20] = "Test String";
  
   printf("%s",strset(str,'k'));
   
   return 0;
}
