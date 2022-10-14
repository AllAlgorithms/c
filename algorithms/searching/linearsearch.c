#include<stdio.h>   
void main ()  
{  
    int a[10] = {10, 23, 40, 1, 2, 0, 14, 13, 50, 9};  
    int item, i,flag;  
    printf("\nEnter the Item which is to be searched: \n");  
    scanf("%d",&item);  
    for (i = 0; i< 10; i++)  
    {  
        if(a[i] == item)   
        {  
            flag = i+1;  
            break;  
        }   
        else   
        flag = 0;  
    }   
    if(flag != 0)  
    {  
        printf("\nItem is found at location %d\n",flag);  
    }  
    else  
    {  
        printf("\nItem is not found\n");   
    }  
}   
