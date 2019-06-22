/*Here we perform the operaion S-S1,if the first different or unmatched characters in strings are such that they have greater ASCII value in S than S1 then S-S1 is positive=1 and vice-
versa,difference is zero if the strings are identical*/
#include<stdio.h>
#include<strings.h>
int main(){
	char S[]="Name";
	char S1[]="NamE";
	int result=strcmp(S,S1);
	printf("%d",result);
	return 0;
}