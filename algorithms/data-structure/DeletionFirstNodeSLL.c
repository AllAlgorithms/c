#include <stdio.h>
#include <stdlib.h>
 
struct node{
    int val;
    struct node *next;
};
 
/*Delete the first node of a linked list.*/
void delete_first_node(struct node **head) {
  struct node *tmp;
 
  /*Linked list does not exist or the list is empty*/
  if(head == NULL || *head == NULL) return;
  
  /*Storing the head to a temporary variable*/
  tmp = *head;
  
  /*Moving head to the next node*/
  *head = (*head)->next;
  
  /*Deleting the first node*/
  free(tmp);
}
 
/*Print the linked list*/
void print_list(struct node *head) {
    
    printf("H->");
 
    while(head)
    {
        printf("%d->", head->val);
        head = head->next;
    }
 
    printf("|||\n");
}
 
/*Insert an element at the front of the list*/
void insert_front(struct node **head, int value) {
    
    struct node * new_node = NULL;
 
    /*Allocating memory for the new node*/
    new_node = (struct node *)malloc(sizeof(struct node));
 
    if (new_node == NULL)
    {
        printf("Failed to insert element. Out of memory");
    }
 
    new_node->val = value;
 
    /*Pointing the new node to where head is currently pointing to*/
    new_node->next = *head;
 
    /*Pointing head to new node.*/
    *head = new_node;
}
 
void main()
{
    int count = 0, i, val;
    struct node * head = NULL;
 
    printf("Enter number of elements: ");
    scanf("%d", &count);
 
    for (i = 0; i < count; i++)
    {
        printf("Enter %dth element: ", i);
        scanf("%d", &val);
        insert_front(&head, val);
    }
 
    printf("Initial Linked List: ");
    print_list(head);
    
    delete_first_node(&head);
    
    printf("Linked List after first node deleted: ");
    print_list(head);
}
