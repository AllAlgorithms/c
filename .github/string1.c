/* PROGRAM TO CHECK IS THE STRING IS PALIDROMAL OR NOT
AUTHOR SOORAJ JHA*/
#include<stdio.h>
#include<string.h>
main()
{
char s1[30],s2[35];
int i,l;
clrscr();
printf("\n ENTER ANY CHARACTER: ");
gets(s1);
l=strlen(s1);
strcpy(s2,s1);
strrev(s2);
i=0;
while(i<=l)
{
	if(s1[i]==s2[i])
	{
	i=i+1;
		if(i==l)
		{
		printf("\n IT IS A PALINDROME ");
		}
	}
	else
	{
	printf("\n IT IS NOT A PALINDROME ");
	break;
	}
}
getch();
return 0;
}
