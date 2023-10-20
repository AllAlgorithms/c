#include <stdio.h>
#include <stdlib.h>

// Define a circular linked list structure
struct circularLinkedList {
    int data;
    struct circularLinkedList *next;
};

// Function prototypes
void createList(struct circularLinkedList **head, int n);
void traverseList(struct circularLinkedList *head);
void insertAtBeginning(struct circularLinkedList **head, int data);
void insertAtEnd(struct circularLinkedList **head, int data);
void insertAtN(struct circularLinkedList **head, int data, int position);
void deleteFromBeginning(struct circularLinkedList **head);
void deleteFromEnd(struct circularLinkedList **head);
void deleteFromN(struct circularLinkedList **head, int position);
void sortList(struct circularLinkedList **head);
int searchList(struct circularLinkedList *head, int key);
void reverseList(struct circularLinkedList **head);
int countList(struct circularLinkedList *head);
void appendList(struct circularLinkedList **headA, struct circularLinkedList **headB);

int main(){
    struct circularLinkedList *head = NULL; // Initialize the main circular list

    // Create and display List 1
    printf("Create List 1:\n");
    createList(&head, 5);
    printf("List 1:\n");
    traverseList(head);

    int choice, data, position, key;
    do {
        // Display the main menu
        printf("\n\nMain Menu\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at N\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from N\n");
        printf("7. Sort the list\n");
        printf("8. Search an element\n");
        printf("9. Reverse the list\n");
        printf("10. Count the number of elements\n");
        printf("11. Append List 2 to List 1\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert at beginning
                printf("Enter the data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                printf("List 1:\n");
                traverseList(head);
                break;
            case 2:
                // Insert at end
                printf("Enter the data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("List 1:\n");
                traverseList(head);
                break;
            case 3:
                // Insert at N
                printf("Enter the data to insert at N: ");
                scanf("%d", &data);
                printf("Enter the position to insert at N: ");
                scanf("%d", &position);
                insertAtN(&head, data, position);
                printf("List 1:\n");
                traverseList(head);
                break;
            case 4:
                // Delete from beginning
                deleteFromBeginning(&head);
                printf("List 1:\n");
                traverseList(head);
                break;
            case 5:
                // Delete from end
                deleteFromEnd(&head);
                printf("List 1:\n");
                traverseList(head);
                break;
            case 6:
                // Delete from N
                printf("Enter the position to delete from N: ");
                scanf("%d", &position);
                deleteFromN(&head, position);
                printf("List 1:\n");
                traverseList(head);
                break;
            case 7:
                // Sort the list
                sortList(&head);
                printf("List 1:\n");
                traverseList(head);
                break;
            case 8:
                // Search an element
                printf("Enter the element to search: ");
                scanf("%d", &key);
                position = searchList(head, key);
                if (position == -1) {
                    printf("Element not found\n");
                } else {
                    printf("Element found at position %d\n", position);
                }
                break;
            case 9:
                // Reverse the list
                reverseList(&head);
                printf("List 1:\n");
                traverseList(head);
                break;
            case 10:
                // Count the number of elements
                printf("Number of elements in the list: %d\n", countList(head));
                break;
                struct circularLinkedList *head2;
            case 11:
                // Append List 2 to List 1
                head2 = NULL; // Initialize the second circular list
                printf("Create List 2:\n");
                createList(&head2, 5);
                printf("List 2:\n");
                traverseList(head2);
                appendList(&head, &head2);
                printf("List 1:\n");
                traverseList(head);
                break;
            case 0:
                // Exit
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to create a circular linked list of n nodes
void createList(struct circularLinkedList **head, int n) {
    int i, data;
    struct circularLinkedList *prevNode, *newNode;

    prevNode = NULL;
    for (i = 1; i <= n; i++) {
        // Create a new node
        newNode = (struct circularLinkedList *)malloc(sizeof(struct circularLinkedList));

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        // Link the new node with the previous node
        if (prevNode != NULL) {
            prevNode->next = newNode;
        }

        // Move the previous node ahead
        prevNode = newNode;

        // Link the last node with the first node
        if (i == n) {
            newNode->next = *head;
        }

        // Update the head pointer if the list is empty
        if (*head == NULL) {
            *head = newNode;
        }
    }
}

// Function to traverse the circular linked list
void traverseList(struct circularLinkedList *head) {
    struct circularLinkedList *currentNode;

    // Return if the list is empty
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    currentNode = head;
    do {
        // Print the data of current node
        printf("%d -> ", currentNode->data);

        // Move to the next node
        currentNode = currentNode->next;
    } while (currentNode != head);
    printf("%d -> ", currentNode->data);
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct circularLinkedList **head, int data) {
    struct circularLinkedList *newNode, *currentNode;

    // Create a new node
    newNode = (struct circularLinkedList *)malloc(sizeof(struct circularLinkedList));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        // Else, insert the new node at the beginning
        currentNode = *head;
        while (currentNode->next != *head) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct circularLinkedList **head, int data) {
    struct circularLinkedList *newNode, *currentNode;

    // Create a new node
    newNode = (struct circularLinkedList *)malloc(sizeof(struct circularLinkedList));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        // Else, insert the new node at the end
        currentNode = *head;
        while (currentNode->next != *head) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
        newNode->next = *head;
    }
}

// Function to insert a node at N of the circular linked list
void insertAtN(struct circularLinkedList **head, int data, int position) {
    struct circularLinkedList *newNode, *currentNode;
    int i;

    // Create a new node
    newNode = (struct circularLinkedList *)malloc(sizeof(struct circularLinkedList));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        // Else, insert the new node at N
        currentNode = *head;
        for (i = 1; i < position - 1; i++) {
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
}

// Function to delete a node from the beginning of the circular linked list
void deleteFromBeginning(struct circularLinkedList **head) {
    struct circularLinkedList *currentNode, *tempNode;

    // If the list is empty
    if (*head == NULL) {
        printf("List is empty.\n");
    } else {
        // Else, delete the node from the beginning
        currentNode = *head;
        while (currentNode->next != *head) {
            currentNode = currentNode->next;
        }
        tempNode = *head;
        currentNode->next = (*head)->next;
        *head = (*head)->next;
        free(tempNode);
    }
}

// Function to delete a node from the end of the circular linked list
void deleteFromEnd(struct circularLinkedList **head) {
    struct circularLinkedList *currentNode, *prevNode;

    // If the list is empty
    if (*head == NULL) {
        printf("List is empty.\n");
    } else {
        // Else, delete the node from the end
        currentNode = *head;
        while (currentNode->next != *head) {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        prevNode->next = currentNode->next;
        free(currentNode);
    }
}

// Function to delete a node from N of the circular linked list
void deleteFromN(struct circularLinkedList **head, int position) {
    struct circularLinkedList *currentNode, *prevNode;
    int i;

    // If the list is empty
    if (*head == NULL) {
        printf("List is empty.\n");
    } else {
        // Else, delete the node from N
        currentNode = *head;
        for (i = 1; i < position; i++) {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        prevNode->next = currentNode->next;
        free(currentNode);
    }
}

// Function to sort the circular linked list in ascending order
void sortList(struct circularLinkedList **head) {
    struct circularLinkedList *currentNode, *index;
    int temp;

    // If the list is empty
    if (*head == NULL) {
        printf("List is empty.\n");
    } else {
        // Else, sort the list in ascending order
        currentNode = *head;
        do {
            index = currentNode->next;
            while (index != *head) {
                if (currentNode->data > index->data) {
                    temp = currentNode->data;
                    currentNode->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            currentNode = currentNode->next;
        } while (currentNode->next != *head);
    }
}

// Function to search an element in the circular linked list
int searchList(struct circularLinkedList *head, int key) {
    struct circularLinkedList *currentNode;
    int position = 1;

    // If the list is empty
    if (head == NULL) {
        printf("List is empty.\n");
        return -1;
    }

    currentNode = head;
    do {
        // If the key is found
        if (currentNode->data == key) {
            return position;
        }
        position++;
        currentNode = currentNode->next;
    } while (currentNode != head);
    return -1;
}

// Function to reverse the circular linked list
void reverseList(struct circularLinkedList **head) {
    struct circularLinkedList *prevNode, *currentNode, *nextNode;

    // If the list is empty
    if (*head == NULL) {
        printf("List is empty.\n");
    } else {
        // Else, reverse the list
        prevNode = *head;
        currentNode = (*head)->next;
        nextNode = (*head)->next->next;
        while (currentNode != *head) {
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
            nextNode = nextNode->next;
        }
        currentNode->next = prevNode;
        *head = prevNode;
    }
}

// Function to count the number of elements in the circular linked list
int countList(struct circularLinkedList *head) {
    struct circularLinkedList *currentNode;
    int count = 0;

    // If the list is empty
    if (head == NULL) {
        printf("List is empty.\n");
        return 0;
    }

    currentNode = head;
    do {
        count++;
        currentNode = currentNode->next;
    } while (currentNode != head);
    return count;
}

// Function to append List 2 to List 1
void appendList(struct circularLinkedList **headA, struct circularLinkedList **headB) {
    struct circularLinkedList *currentNode;

    // If List 1 is empty
    if (*headA == NULL) {
        *headA = *headB;
    } else {
        // Else, append List 2 to List 1
        currentNode = *headA;
        while (currentNode->next != *headA) {
            currentNode = currentNode->next;
        }
        currentNode->next = *headB;
        currentNode = *headB;
        while (currentNode->next != *headB) {
            currentNode = currentNode->next;
        }
        currentNode->next = *headA;
    }
}

// Path: circularLinkedList.c
