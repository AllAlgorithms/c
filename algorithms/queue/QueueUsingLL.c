#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front;
struct node *rear;
void ins();
void del();
void display();
void main ()
{
    int choice;
    while(choice != 4)
    {
printf("\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
printf("Enter your choice:");
scanf("%d",& choice);
switch(choice)
{
    case 1:
    ins();
    break;

    case 2:
    del();
    break;

    case 3:
    display();
    break;

    case 4:
    exit(0);
    break;

    default:
    printf("\nEnter valid choice!!");
}
}
}

void ins()
{
    struct node *ptr;
    int item;
    ptr = (struct node *) malloc (sizeof(struct node));
    if(ptr == NULL)
    {
printf("\nOVERFLOW\n");
return;
    }
    else
    {
printf("Enter value:");
scanf("%d",&item);
ptr -> data = item;
if(front == NULL)
{
    front = ptr;
    rear = ptr;
    front -> next = NULL;
    rear -> next = NULL;
}

else
{
    rear -> next = ptr;
    rear = ptr;
    rear->next = NULL;
}
}
}
void del ()

{
    struct node *ptr;
    if(front == NULL)
    {
 printf("\nUNDERFLOW\n");
return;
    }
    else
    {
ptr = front;
front = front -> next;
free(ptr);
    }
}
void display()
{
    struct node *ptr;
    ptr = front;
    if(front == NULL)
    {
printf("\nEmpty queue");
    }
    else
    {   printf("Elements of Queue:");
while(ptr != NULL)
{

   printf(" %d",ptr -> data);
    ptr = ptr -> next;
}
   printf("\n");
    }
}
