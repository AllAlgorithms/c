// Pascal’s Triangle

#include <stdio.h>
void Pascal(int n) 
{ 
    int arr[n][n];  
      
    for (int i=0;i<n;i++) 
    {   
        //Adding spaces to make it look like a triangle..
        for(int spaces = 0; spaces < (n-i); spaces++)
            printf(" ");
        
        for(int j=0;j<=i;j++) 
        { 
            if (i == j || j == 0) 
                arr[i][j] = 1; 
            else 
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j]; 
            printf("%d ", arr[i][j]); 
        } 
        printf("\n"); 
    } 
} 
int main() 
{ 
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    Pascal(n); 
    return 0; 
}
