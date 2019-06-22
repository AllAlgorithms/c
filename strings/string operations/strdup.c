/*strdup function in C used to duplicate a string, while defining a pointer to a string we do not define its size i.e. we define it as char *S   */
#include<stdio.h>
#include<strings.h>
int main(){
	char *S1="desktop";
	char *S2;
	S2=strdup(S1);
	printf("%s",S1);
	return 0;
}