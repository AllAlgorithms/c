#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Standard functions of a stack when implemented using an array

// Function checks if stack is empty
int isempty(int *arr,int top)
{
    if(top==-1)
    {
        return 1;
    }
    else
        return 0;
}

//Function checks if stack is full
 int isfull(int *arr, int top)
 {
     if(top==MAX-1)
     {
         return 1;
     }
     else
        return 0;
 }

 // Function pushes elements in the stack
int push(int * arr, int top)
{
    if(isfull(arr,top))                       //Checks if array is full
    {
        printf("Stack overflow.\n");
    }
    else
    {
        top++;                                // If array is not full, increments the top and adss the data to it
        printf("Enter data: ");
        scanf("%d",&arr[top]);
    }
    return top;
}

int pop(int *arr, int top)
{
    if(isempty(arr,top))
    {
        printf("Stack underflow.\n");           // Checks if array is empty
    }
    else
    {
        printf("%d is popped\n", arr[top]);     // Otherwise pops off the top element from it and reduces value of stack pointer
        top--;
    }
    return top;
}

// Function gives the data at the top of the stack
// But unlike the previous function doesn't delete the data
void peek(int*arr, int top)
{
    if(isempty(arr,top))
    {
        printf("Stack underflow.\n");             // Checks if array is empty or not
    }
    else
    {
        printf("%d\n", arr[top]);
    }
}

// Function prints the array
void print(int*arr,int top)
{
    int i;
    for(i=0; i<=top; i++)
        printf("%d  ",arr[i]);
    printf("\n");
}
int main()
{
    int arr[MAX], top=-1, option,is_empty,is_full;  // arr is the array that is being used as a stack
    do
    {
        printf("Enter option: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: top=push(arr,top);
                    break;
            case 2: top=pop(arr,top);
                    break;
            case 3: peek(arr,top);
                    break;
            case 4: is_empty=isempty(arr,top);
                    break;
            case 5: is_full=isfull(arr,top);
                    break;
            case 6: print(arr,top);
                    break;
        }
        printf("Press 1 to continue, 0 to exit: ");
        scanf("%d",&option);
    }while(option);
}
