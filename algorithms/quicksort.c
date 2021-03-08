#include<stdio.h>
void quickSort(int array[],int first,int last)
{
    int i, j, pivot, temp;
    if(first<last)
    {
        i=pivot=first;
        j=last;
        while(i<j)
        {
            while(array[i]<=array[pivot]&&i!=last)
                i++;
            while(array[j]>array[pivot]&&j!=first)
                j--;
            temp=array[j];
            if(i<j)
            {
                array[j]=array[i];
                array[i]=temp;
            }
        }
        array[j]=array[pivot];
        array[pivot]=temp;
        quickSort(array,first,j-1);
        quickSort(array,j+1,last);
    }
}

int main(){
   int i, count, number[25];

   printf("How many elements are u going to enter?: ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);

   quicksort(number,0,count-1);

   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);

   return 0;
}
