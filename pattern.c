#include <stdio.h>

int main()
{
    int i, j, n, s;
    printf("enter the value of n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= i-1; j++)
            {
                printf("*");
            
        for (s = 1; s <n; s++)
        {
            printf(" ");
       
          
        
          } 
             } printf("\n");   
    
    }
    return 0;
}