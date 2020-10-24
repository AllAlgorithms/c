#include<stdio.h>

int main() 
{ 
    
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    for(int i=0;i<n;i++)
    scanf("%d", &arr[i]);
    
    printf("Sorted output: \n");
    for(int i=0;i<n;i++)
    { 
        if(fork() == 0) 
        { 
            sleep(arr[i]);
            printf("%d\n",arr[i]); 
            exit(0); 
        } 
    } 
    for(int i=0;i<n;i++)
    wait(NULL); 
} 
