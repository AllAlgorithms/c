#include <stdio.h>

int largest(int arr[], int n) //writing largest function 
{ 
    int max = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
    return max; 
} 

int LIS(int array[], int n)  // Adding LIS function
{
        int lis[n];
        lis[0] = 0;
        for(int i = 1; i < n; i++){
                lis[i] = 1;
                for (int j = 0; j < i; j++){
                        if (array[j] < array[i] && lis[i] < lis[j] + 1){
                                lis[i] = lis[j] + 1;
                        }
                }
        } 
        return largest(lis, n);
}

int main()
{
        int a[] = {3, 4, -1, 0, 6, 2, 3};
        printf("Size of the longest increasing subsequence is : %d", LIS(a, 7));
        return 0;
}
