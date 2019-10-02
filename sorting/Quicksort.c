#include<stdio.h>
int main()
{
    int i,n;
    printf("Enter the size of array=");
    scanf("%d",&n);
    int a[n],low=0,high=n-1;
    for(i=0;i<n;i++)
    {
        printf("A[%d]=",i);
        scanf("%d",&a[i]);
    }
    Quick_sort(a,low,high);  //Considering first element as pivot
    printf("\nArray in ascending order is=\n");
    for(i=0;i<n;i++)
    {
        printf(" %d\n",a[i]);
    }
    return 0;
}
void Quick_sort(int *a,int low,int high)
{
    int Loc_pivot;
    if(low<high)
    {
        Loc_pivot=Partition(a,low,high);
        Quick_sort(a,low,Loc_pivot-1);
        Quick_sort(a,Loc_pivot+1,high);
    }
}
int Partition(int *a,int low,int high)
 {
     int pivot,right,left,b,c;
     pivot=a[low];
     left=low+1;
     right=high;
     while(left<=right)
     {
         while(left<=high && a[left]<=pivot)
         {
             left=left+1;
         }
         while(a[right]>pivot)
         {
             right=right-1;
         }
         if(left<right)
         {
             b=a[left];
             a[left]=a[right];
             a[right]=b;
         }
     }
     c=a[right];
     a[right]=a[low];
     a[low]=c;
     return right;
 }
