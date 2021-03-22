// C++ program to rotate an array by
// d elements
#include <bits/stdc++.h>

/*Fuction to get gcd of a and b*/
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    else
    {
        return gcd(b, a % b);
    }
}

/*Function to left rotate arr[] of siz n by d*/
void leftRotate(int arr[], int d, int n)
{
    int i,temp,k,j,g_c_d;
    /* To handle if d >= n */
    d = d % n;
    g_c_d = gcd(d, n);
    for (i = 0; i < g_c_d; i++)
    {
        /* move i-th values of blocks */
        temp = arr[i];
        j = i;

        while (1)
        {
            int k = j + d;
            if (k >= n)
            {
                k = k - n;
            }

            if (k == i)
            {
                break;
            }

            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Before rotating" << std::endl;
    printArray(arr, n);
    // Function calling
    leftRotate(arr, 2, n);
    std::cout << "after rotating by 2" << std::endl;
    printArray(arr, n);

    return 0;
}