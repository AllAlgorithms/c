//Program to convert decimal number to binary (Using Reccursion)
//Note : This program only supports integers decimals.
//Created by Aromal Anil
//Date : 27-10-2019 02:16 IST

#include <stdio.h>
int decimal_to_binary(int decimal)
{
  if(decimal==1)
  {
    return 1;
  }
  else if(decimal==0)
  {
    return 0;
  }
  else
  {
    if((decimal%2)==0)
    {
        return ( (decimal_to_binary(decimal/2)*10) + 0);
    }
    else
    {
        return ( (decimal_to_binary(decimal/2)*10) + 1);
    }
  }
}
void main()
{
  int binaryNumber,decimalNumber;
  
  printf("\nEnter your decimal number : ");
  
  scanf("%d",&decimalNumber);
  
  binaryNumber = decimal_to_binary(decimalNumber);
  
  printf("\nThe binary of %d is : %d" ,decimalNumber,binaryNumber);
}
