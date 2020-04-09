//singly linked list C program and concept

#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

struct node

{

    int info;

    struct node *link;

} * start;

void create(int);

struct node *create_node(int);

void display(struct node *);

void insert_end(int);

void insert_beg(int);

void insert_pos(int, int);

void delete_beg();

void delete_pos(int);

void delete_end();

void search(int);

void reverse();

int main()

{

    int choice, data, choice1, pos, no_of_node;

    start = NULL;

    while (1)

    {

        system("cls"); // equivalent to system("cls"); // equivalent to clrscr();

        printf("1.Create Linked list\n");

        printf("2.Display Linked list\n");

        printf("3.Insert into Linked list\n");

        printf("4.Delete Node in Linked list\n");

        printf("5.Search in Linked list\n");

        printf("6.Reverse the Linked list\n");

        printf("7.Exit");

        printf("\nEnter Your choice : ");

        scanf("%d", &choice);

        switch (choice)

        {

        case 1:
            printf("Enter no of node to be created :");

            scanf("%d", &no_of_node);

            create(no_of_node);

            break;

        case 2:
            display(start);

            break;

        case 3:
            system("cls"); // equivalent to system("cls"); // equivalent to clrscr();

            printf("1.Insert node at begining of list\n");

            printf("2.Insert node at specific position in list\n");

            printf("3.Insert node at End of list\n");

            printf("4.previous menu\n");

            printf("Enter Choice : ");

            scanf("%d", &choice1);

            switch (choice1)

            {

            case 1:
                printf("Enter data for node :");

                scanf("%d", &data);

                insert_beg(data);

                break;

            case 2:
                printf("Enter data for node :");

                scanf("%d", &data);

                printf("\n4Enter postition for node:");

                scanf("%d", &pos);

                insert_pos(data, pos);

                break;

            case 3:
                printf("Enter data for node :");

                scanf("%d", &data);

                insert_end(data);

                break;

            case 4:
                break;
            }
            break;

        case 4:
            system("cls"); // equivalent to system("cls"); // equivalent to clrscr();

            printf("1.Delete node at begining of list\n");

            printf("2.Delete node at specific position in list\n");

            printf("3.Delete node at End of list\n");

            printf("4.previous menu\n");

            printf("Enter Choice : ");

            scanf("%d", &choice1);

            switch (choice1)

            {

            case 1:
                delete_beg();

                break;

            case 2:
                printf("Enter postition for node:");

                scanf("%d", &pos);

                delete_pos(pos);

                break;

            case 3:
                delete_end(data);

                break;

            case 4:
                break;
            }
            break;

        case 5:
            system("cls"); // equivalent to system("cls"); // equivalent to clrscr();

            printf("Enter Data to be searched :");

            scanf("%d", &data);

            search(data);

            getch();

            break;

        case 6:
            system("cls"); // equivalent to system("cls"); // equivalent to clrscr();

            reverse();

            break;

        case 7:
            exit(1);

        default:
            printf("Invalid Entry");
        }
    }

    return 0;
}

void create(int no)

{

    int i, data;

    system("cls"); // equivalent to system("cls"); // equivalent to clrscr();

    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    for (i = 0; i < no; i++)

    {

        if (start == NULL)

        {

            printf("Enter Data for node %d :", i);

            scanf("%d", &data);

            temp->info = data;

            temp->link = NULL;

            start = temp;
        }

        else

        {

            printf("Enter Data for node %d :", i);

            scanf("%d", &data);

            insert_end(data);
        }
    }

    if (no > 0)

        printf("List created");

    else

        printf("List not created");

    getch();

    system("cls"); // equivalent to system("cls"); // equivalent to clrscr();
}

void display(struct node *start)

{

    struct node *t;

    t = start;

    system("cls"); // equivalent to clrscr();

    if (start == NULL)

    {

        printf("List is empty");

        getch();

        return;
    }

    printf("Linked List \n");

    while (t != NULL)

    {

        printf("%d->", t->info);

        t = t->link;
    }

    printf("End_of_list");

    getch();

    system("cls"); // equivalent to clrscr();
}

struct node *create_node(int data)

{

    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    temp->info = data;

    temp->link = NULL;

    return temp;
}

void insert_end(int data)

{

    struct node *temp;

    temp = start;

    while (1)

    {

        if (temp->link != NULL)

            temp = temp->link;

        else

            break;
    }

    temp->link = create_node(data);
}

void insert_beg(int data)

{

    struct node *newnode;

    newnode = create_node(data);

    newnode->link = start;

    start = newnode;
}

void insert_pos(int data, int pos)

{

    int i;

    struct node *newnode, *ptr;

    ptr = start;

    for (i = 0; i < pos; i++)

    {

        if (ptr == NULL)

        {

            printf("Invalid Position Entered");

            getch();

            return;
        }

        ptr = ptr->link;
    }

    if (ptr->link == NULL)

    {

        insert_end(data);
    }

    else

    {

        newnode = create_node(data);

        newnode->link = ptr->link;

        ptr->link = newnode;
    }
}

void search(int data)

{

    int count = 0;

    struct node *ptr;

    ptr = start;

    do
    {

        if (ptr->info == data)

        {

            printf("Data Found at position : %d", count);

            printf("\nAddress of node with Data : %u", ptr);

            return;
        }

        else

            ptr = ptr->link;

        count++;

    } while (ptr->link != NULL);

    printf("Data Not found");
}

void delete_beg()

{

    struct node *ptr;

    if (start == NULL)

    {

        printf("List is empty");

        return;
    }

    ptr = start;

    start = ptr->link;

    free(ptr);

    printf("First Node Deleted");

    getch();
}

void delete_pos(int pos)

{

    struct node *ptr, *preptr;

    int i;

    ptr = start->link;

    preptr = start;

    if (ptr == NULL)

    {

        delete_beg();

        return;
    }

    for (i = 0; i < pos - 1; i++)

    {

        if (ptr == NULL)

        {

            printf("Invalid position");

            getch();

            return;
        }

        preptr = preptr->link;

        ptr = ptr->link;
    }

    preptr->link = ptr->link;

    free(ptr);
}

void delete_end()

{

    struct node *ptr, *preptr;

    if (start == NULL)

    {

        printf("List is empty");

        return;
    }

    ptr = start->link;

    preptr = start;

    while (ptr->link != NULL)

    {

        ptr = ptr->link;

        preptr = preptr->link;
    }

    preptr->link = NULL;

    free(ptr);

    printf("Last Node Deleted");

    getch();
}

void reverse()

{

    if (start == NULL)

    {

        printf("List is empty");

        getch();

        return;
    }

    else if (start->link == NULL)

    {

        printf("List reversed");

        getch();

        return;
    }

    struct node *p1, *p2, *p3;

    p1 = start;

    p2 = p1->link;

    p3 = p2->link;

    p1->link = NULL;

    p2->link = p1;

    while (p3 != NULL)

    {

        p1 = p2;

        p2 = p3;

        p3 = p3->link;

        p2->link = p1;
    }

    start = p2;

    printf("List Reversed");

    getch();
}
