/*Author:Alok Khulbay
Date:-17/08/2020
Purpose:-To self learn.
*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void Linked_List_Traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
//case 1: Insert at the first
struct Node *Insert_at_First(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
//Csae:2 Insert at given index
struct Node *Insert_at_Index(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
// Csae :3 Insert at last
struct Node *Insert_at_last(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;

    ptr->next = NULL;
    return head;
}
// Case:4 Insert after a Node
struct Node *Insert_after_a_Node(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next=ptr;
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    //Allocate Memory for nodes in the Linked List in a Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 7;
    head->next = second;
    second->data = 11;
    second->next = third;
    third->data = 41;
    third->next = fourth;
    fourth->data = 66;
    fourth->next = NULL;
    printf("Linked List before insertion\n");
    Linked_List_Traversal(head);
    // head = Insert_at_First(head, 56);
    // head = Insert_at_Index(head, 56, 1);
    // head=Insert_at_last(head,56);
    head = Insert_after_a_Node(head, third, 56);
    printf("Linked List after insertion\n");
    Linked_List_Traversal(head);
    return 0;
}