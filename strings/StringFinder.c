#include<stdio.h>

void main()
{   int i=0,j,k,flag=0;
   char first[100];
   char sec[50];
   printf("Enter initial string: ");
   //scanf("%s",first);
   gets(first);
   printf("Enter string to be searched: ");
   //scanf("%s",sec);
   gets(sec);
   printf("%s\n%s",first,sec);
   
   while(first[i]!='\0')
   {  k=0;
      j=i;
      flag=0;
      while(sec[k]!='\0')
      {
        if(first[j]!=sec[k])
        {
          flag=1;
        }
        k++;j++;
        if(flag==1){break;}
      }
      i++;
      if(flag==0)
      {break;}
     
   }
   
   if(flag==0){printf("\nFound at %d\n",i);}
   else
   {printf("\nNot Found\n");}

}
