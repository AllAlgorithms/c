#include <stdio.h>
#include <string.h>

int string_length(char s[]) {
   int i = 0;

   while(s[i]!='\0')
      i++;

   return i;	
}

void string_reverse(char st[]) {
   int i,j,len;
   char ch;

   j = len = string_length(st) - 1;
   i = 0;

   while(i < j) {
      ch = st[j];
      st[j] = st[i];
      st[i] = ch;
      i++;
      j--;
   }
}

int main (void) {
   char line[] = "Taj Mahal is one of the seven wonders of the world";
   char reverse[100]="",temp[50];
   int i,j,n;

   n = string_length(line);

   for(i = 0; i < n; i++) {

      for(j = 0; i < n && line[i]!=' '; ++i,++j) {
         temp[j] = line[i];
      }
      
      temp[j] = '\0';

      string_reverse(temp);

      strcat(reverse, temp);
      strcat(reverse, " ");
   }
   
   printf("Original - %s\n", line);
   printf("Reversed - %s\n",reverse);
   
   return 0;
}
