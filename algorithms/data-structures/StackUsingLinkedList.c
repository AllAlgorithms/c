#include <stdio.h>
#include <stdlib.h>
#include <limits.h>     // For INT_MIN

#define CAPACITY 1000

// Define stack node structure
struct stack 
{
    int item;
    struct stack *next;
}   *top;

int size = 0;
void push(int ele);
int  pop();


int main()
{
    int choice, item;

    while(1)
    {
        printf("    STACK IMPLEMENTATION    \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Size\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) 
        {
            case 1: 
                printf("Enter data to push into stack: ");
                scanf("%d", &item);
                
                // Push element to stack
                push(item);
                break;

            case 2: 
                item = pop();

                if (item != INT_MIN)
                    printf("Data => %d\n", item);
                break;

            case 3: 
                printf("Stack size: %d\n", size);
                break;

            case 4: 
                printf("Exiting from app.\n");
                exit(0);
                break;

            default: 
                printf("Invalid choice, please try again.\n");
        }

        printf("\n\n");
    }


    return 0;
}


void push(int element)
{
    // Check stack overflow
    if (size >= CAPACITY)
    {
        printf("Stack Overflow, can't add more element to stack.\n");
        return;
    }

    
    struct stack * newNode = (struct stack *) malloc(sizeof(struct stack));

    newNode->item = element;

    newNode->next = top;        

    top = newNode;

    size++;

    printf("Data pushed to stack.\n");
}


int pop()
{
    int item = 0;
    struct stack * topNode;
    
    if (size <= 0 || !top)
    {
        printf("Stack is empty.\n");

        return INT_MIN;
    }

    topNode = top;
    
    item = top->item;

    top = top->next;

    free(topNode);

    size--;

    return item;
}
