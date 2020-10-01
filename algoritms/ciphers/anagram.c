#include <stdio.h>
 
int check_anagram(char [], char []);
 
int main()
{
  char a[100], b[100];
 
  printf("Enter a string:");
  gets(a);
 
  printf("\nEnter a string:");
  gets(b);
 
  if (check_anagram(a, b) == 1)
    printf("The strings are anagrams\n");
  else
    printf("The strings aren't anagrams\n");
 
  return 0;
}
 
int check_anagram(char a[], char b[])
{
  int first[26] = {0}, second[26] = {0}, c=0;
 
  // Calculating frequency of characters of first string
 
  while (a[c] != '\0')
  {
    first[a[c]-'a']++;
    c++;
  }
 
  c = 0;
 
  while (b[c] != '\0')
  {
    second[b[c]-'a']++;
    c++;
  }
 
  // Comparing frequency of characters
 
  for (c = 0; c < 26; c++)
  {
    if (first[c] != second[c])
      return 0;
  }
 
  return 1;
}
