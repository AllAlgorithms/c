/*strchr function finds the first occurence of any character in a string and prints the part of the string after that character beginning with that character*/
#include<stdio.h>
#include<strings.h>
int main(){
	char string[]="Indian Institute of Technology";
	char *p;
	p=strchr(string,'o');
	printf("%s",p);
	printf("\nThe numbered location is %d",p-string+1);
	return 0;
}