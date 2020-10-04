#include <stdio.h>

char chcase(char c){
  // This function changes a case of a character using ASCII table pattern
  return c + 32;
}

int main(void){
	char c;
	scanf("%c", &c);
	printf("The opposite case of %c is %c\n", c,  chcase(c));
	return 0;
}
