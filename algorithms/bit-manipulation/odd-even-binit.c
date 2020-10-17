/* we are finding odd-even 
   for two numbers using bit manipulation
*/

#include<stdio.h>

void main()
{
    int arr[]={5,6};
    int c;
    for(int i=0;i<=(sizeof(arr)/sizeof(int));i++)
    {
        c=arr[i]>>1; //RIght shift the left-most bit
        c=c<<1;      //left shift the left-most bit
        if(arr[i]==c)
        {
            printf("\nThe number %d is even",arr[i]);

        }
        else
        {
            printf("\nThe number %d is odd",arr[i]);
        }
        
    }
}