/*strcpy function is used to copy one string to another*/
#include<stdio.h>
#include<strings.h>
int main(){
	char S1[]="Coding";
	char S2[10];
	char S3[10];
	strcpy(S2,S1);
	/*Copy in string 2, the string 1*/
	strcpy(S3,"In C");
	/*Randomly copying any string to S3*/
	puts(S2);
	puts(S3);
return 0;
}
