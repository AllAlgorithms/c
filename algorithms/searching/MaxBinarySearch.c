#include <stdio.h>
void max_heapify(int *a, int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
            j = j + 1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j/2] = temp;
    return;
}
int binarysearchmax(int *a,int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a,i,n);
    }
    return a[1];
}
int main()
{
    int n, i, x, max;
    int a[20];
    printf("Enter no of elements of array\n");
    scanf("%d", &n);
    printf("\nEnter %d elements: ", n);
    for (i = 1; i <= n; i++)
    {
       scanf("%d", &a[i]);
    }
    max = binarysearchmax(a, n);
    printf("\nMaximum element is : %d", max);
    return 0;
}
