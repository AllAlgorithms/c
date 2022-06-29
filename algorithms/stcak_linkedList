#include <stdio.h>
#include <stdlib.h>

struct Node
{
int val;
struct Node *next;
};
typedef struct Node node;
node *head;

void push ()
{
    int val;
    node *ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL)
    {
        printf("not able to push the element\n");
    }
    else
    {
        printf("Enter the value\t");
        scanf("%d",&val);
        if(head==NULL)
        {
            ptr->val = val;
            ptr -> next = NULL;
            head=ptr;
        }
        else
        {
            ptr->val = val;
            ptr->next = head;
            head=ptr;

        }
        printf("Item pushed\n");

    }
}

void pop()
{
    int item;
    node *ptr;
    if (head == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Item popped\n");

    }
}

void display()
{
    int i;
    node *ptr;
    ptr=head;
    if(ptr == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements\n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->val);
            ptr = ptr->next;
        }
    }
}

void main ()
{
    int choice=0;
    printf("\n*********Stack operations using linked list*********\n");
    while(choice != 4)
    {
        printf("Enter:\n1.Push\n2.Pop\n3.Show\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("Exiting....");
                break;
            }
            default:
            {
                printf("Please Enter valid choice\n");
            }
        }
    }
}
