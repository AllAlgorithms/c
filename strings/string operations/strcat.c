/*strcat function in c which appends one string to another i.e. it writes string 2 at the end of string 1*/
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[] = "Henry"; 
	char str2[] = "Nicholas";
	strcat(str1,str2);

    /*String will get appended after string 1*/
    

    printf("%d",str1);    
     /*whole string will now be string 1*/

    return 0;
}