#include <stdio.h>
void main()
{
   char str[100], ch;
   int i, frequency = 0;
   printf("Enter your string\n");
   gets(str);
   printf("Enter a character to find the frequency\n");
   scanf("%c",&ch);
   for(i = 0; str[i] != '\0'; ++i)
   {
       if(ch == str[i])
           ++frequency;
   }
   printf("Frequency of %c = %d", ch, frequency);
}
