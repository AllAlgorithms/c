#include<stdio.h>
int mergeSort(int[],int,int);
int merge(int[],int,int,int);
int main()
{
   // int a[] = {2,4,3,5,1};
   int a[] = {8,4,2,1};
    int noI,n ;
    n = sizeof(a)/sizeof(int);
    noI = mergeSort(a,0,n-1);
    printf("Number of inversions are : %d",noI);
    return 0;
}
int mergeSort(int a[],int lb,int ub)
{   int count = 0;
    int mid;
   if(lb<ub)
   {
       mid = (lb +ub)/2;

       count = mergeSort(a,lb,mid);
       count = count + mergeSort(a,mid+1,ub);
       count  = count + merge(a,lb,mid,ub);
   }
   return count ;
}

int merge(int a[],int lb,int mid,int ub)
{   int count = 0;
    int b[lb+ub+1],k=lb,i = lb,j = mid+1;
    while(i<=mid &&j<=ub)
    {
           if(a[i]<a[j])
        {
            b[k] = a[i];i++;k++;
        }
        else
        {  b[k] = a[j];j++;k++;
           count = count + (mid-i+1);
        }

    }

     if(i>mid)
    {

        while(j<=ub)
        {
            b[k] = a[j];
            j++;k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k] = a[i];i++;k++;
        }

    }
for(k=lb;k<=ub;k++)
a[k]=b[k];
return count;
}


