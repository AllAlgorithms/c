

#include <stdio.h>

void insertion_sort(int array[],int l){
    int i,j,key;
    for(i=1;i<l;i++){
        key=array[i];
        j=i-1;
        while(j>=0 && array[j]>key){
            array[j+1]=array[j];
            j=j-1;
        }
        array[j+1]=key;

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

    insertion_sort(array,l);
    printf("The Sorted Array is: ");
    for(i=0;i<l;i++){
        printf("%d ",array[i]);
    }
}