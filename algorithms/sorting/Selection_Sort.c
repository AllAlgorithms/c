#include <stdio.h>
 
 
void selection_sort(int array[], int n)
{
    int i, j, min, t;

    for (i = 0; i < n-1; i++)
    { 
        min = i;
        for (j = i+1; j < n; j++)
          if (array[j] < array[min]){
            min = j;}
           if(min != i){
                t=array[min];
                array[min]=array[i];
                array[i]=t;
           }
    }
}
 

void main(){
    int l;
    printf("Enter Number of Element in Array: ");
    scanf("%d",&l);
    int array[l],i;
    for(i=0;i<l;i++){
        printf("Enter %d Element: ",i+1);
        scanf("%d",&array[i]);
    }

    selection_sort(array,l);
    printf("The Sorted Array is: ");
    for(i=0;i<l;i++){
        printf("%d ",array[i]);
    }
}