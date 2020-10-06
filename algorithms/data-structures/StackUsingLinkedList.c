#include <stdio.h>

#include <stdlib.h>

struct node

{

    int info;

    struct node *ptr;

}*top,*top1,*temp;

int topelement();

void push(int data);

void pop();

void isEmpty();

void display();

void element_count();

void create();

int count = 0;

void main()

{

    int no, ch, e;

    printf("\n1.Push");

    printf("\n2.Pop");

    printf("\n3.Top");

    printf("\n4.Empty");

    printf("\n5.Exit");

    printf("\n6.Dipslay");

    printf("\n7.Stack Count\n");

    create();

    while (1)

    {

printf("\nEnter choice:");

scanf("%d",&ch);

switch (ch)

{

case 1:

    printf("Enter data:");

    scanf("%d", &no);

    push(no);

    break;

case 2:

    pop();

    break;

case 3:

    if (top == NULL)

printf("No elements in stack");

    else

    {

e = topelement();

printf("\nTop element:%d", e);

    }

    break;

case 4:

    isEmpty();

    break;

case 5:

    exit(0);

case 6:

    display();

    break;

case 7:

    element_count();

    break;

default :

    printf("Enter correct choice!");

    break;

}

    }

}

/* Create empty stack */

void create()

{

    top = NULL;

}

/* Count stack elements */

void element_count()

{

    printf("\nNo. of elements in stack: %d", count);

}

/* Push data into stack */

void push(int data)

{

    if (top == NULL)

    {

top =(struct node *)malloc(1*sizeof(struct node));

top->ptr = NULL;

top->info = data;

    }

    else

    {

temp =(struct node *)malloc(1*sizeof(struct node));

temp->ptr = top;

temp->info = data;

top = temp;

    }

    count++;

}

/* Display stack elements */

void display()

{

    top1 = top;

    if (top1 == NULL)

    {

printf("Stack is empty");

return;

    }

    while (top1 != NULL)

    {

printf("%d ", top1->info);

top1 = top1->ptr;

    }

 }

/* Pop Operation on stack */

void pop()

{

    top1 = top;

    if (top1 == NULL)

    {

printf("\n Error: Trying to pop from empty stack");

return;

    }

    else

top1 = top1->ptr;

    printf("\nPopped value: %d", top->info);

    free(top);

    top = top1;

    count--;

}

/* Return top element */

int topelement()

{

    return(top->info);

}

/* Check if stack is empty or not */

void isEmpty()

{

    if (top == NULL)

printf("\nStack is empty");

    else

printf("\nStack is not empty & contains %d elements", count);

}
