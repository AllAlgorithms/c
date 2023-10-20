#include<stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *next;
    struct Node *prev;
}*head;

void create(int info)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->info = info;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
}
// traversing the linked list
void traverse()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
}
// searching for an element 
void search(int info)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->info == info)
        {
            printf("found in the doubly linked list \n");
            return;
        }
        temp = temp->next;
    }
    printf("Key not found\n");
}
// insertion at begin
void insert_begin(int info)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->info = info;
    temp->next = head;
    temp->prev = NULL;
    if (head != NULL)
        head->prev = temp;
    head = temp;
}
// insertion at the end
void insert_end(int info)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->info = info;
    temp->next = NULL;
    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
    }
    else
    {
        struct Node *temp2 = head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->prev = temp2;
    }
}
// insert at any position
void insert_pos(int pos, int info)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp2 = head;
    int i;

    for (i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\nThere are less than %d elements", pos);
            return;
        }
    }
    temp->info = info;
    if (pos == 1)
    {
        insert_begin(info);
        return;
    }

    else
    {
        struct Node *temp2 = temp->next;
        temp->next = temp;
        temp2->prev = temp;
        temp->prev = temp;
        temp->next = temp2;
    }
}

void delete_begin()
{
    if (head == NULL)
        printf("\n no memory");
    else
    {
        struct Node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

void delete_end()
{
    if (head == NULL)
        printf("\n UNDERFLOW");
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->prev->next = NULL;
        free(temp);
    }
}

void delete_pos(int pos)
{
    struct Node *temp = head;

    int i;

    for (i = 1; i < pos; i++)
    {
        temp = temp->next;

        if (temp == NULL)
        {
            printf("\nThere are less than %d elements", pos);
            return;
        }
    }

    if (pos == 1)
    {
        delete_begin();
        return;
    }

    else
    {
        struct Node *temp2 = temp->prev;

        temp2->next = temp->next;

        free(temp);

        return;
    }
}

int main()
{

    int choice, data, pos, key;

    do
    {

        printf("\n\n*MAIN MENU*\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Insert at beginning\n");
        printf("5. Insert at end\n");
        printf("6. Insert at any position\n");
        printf("7. Delete from beginning\n");
        printf("8. Delete from end\n");
        printf("9. Delete from any position\n");
        printf("10. EXIT\n");

        printf("\nEnter your option : ");
        scanf("%d", &choice);
int n;
        switch (choice)
        {

        case 1:
        
        printf("Enter the number of nodes to be insert in the list : ");
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            printf("Enter the item to be inserted at node no %d: ",i);
            scanf("%d", &data);
            create(data);
        }
            break;

        case 2:
            
            traverse();
            break;

        case 3:
       
            printf("Enter the key to search: ");
            scanf("%d", &key);
            search(key);
            break;

        case 4:
       
            printf("Enter the item to be inserted: ");
            scanf("%d", &data);
            insert_begin(data);
            break;

        case 5:
        
            printf("Enter the item to be inserted: ");
            scanf("%d", &data);
            insert_end(data);
            break;

        case 6:
        
            printf("Enter the position at which to insert: ");
            scanf("%d", &pos);
            printf("Enter the item to be inserted: ");
            scanf("%d", &data);
            insert_pos(pos, data);
            break;

        case 7:
            delete_begin();
            break;

        case 8:
            delete_end();
            break;

        case 9:
            printf("Enter the position from which to delete: ");
            scanf("%d", &pos);
            delete_pos(pos);
            break;

        case 10:
            exit(0);
        }

    } while (choice != 10);

    return 0;
}
