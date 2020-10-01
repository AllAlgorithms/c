#include <stdio.h>
int main()
{
   char str[100], ch;
   int i, frequency = 0;
   printf("Enter your string\n");
   gets(str);
   printf("Enter a character to find the frequency\n");
   scanf("%c",&ch);
   for(i = 0; str[i] != '\0'; ++i)
   {
       if(ch == str[i] || ch-32 == str[i] || ch+32 ==str[i])
           ++frequency;
   }
   printf("Frequency of %c = %d", ch, frequency);
}
