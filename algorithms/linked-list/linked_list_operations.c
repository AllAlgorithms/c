#include <stdio.h>
#include <stdlib.h>

// Define a singly linked list structure
struct sll {
    int data;
    struct sll *next;
};

// Function prototypes
void createList(struct sll **);
void traversal(struct sll *);
void insert(struct sll *);
int search(struct sll *, int);
void sort(struct sll **);
void reverse(struct sll **);
int count(struct sll *);
void deleteAfter(struct sll *);
void deleteBefore(struct sll **, int);
void deleteAtPosition(struct sll **, int);
void deleteAfterNode(struct sll **, int);
void insertAfter(struct sll *, int, int);
void insertBefore(struct sll **, int, int);
void appendList(struct sll **, struct sll *);

int main() {
    struct sll *node = NULL;    // Initialize the main linked list

    // Create and display List 1
    printf("Create List 1:\n");
    createList(&node);
    printf("List 1:\n");
    traversal(node);

    int choice;
    do {
        // Display the main menu
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Sort\n");
        printf("4. Reverse\n");
        printf("5. Delete After\n");
        printf("6. Delete Before\n");
        printf("7. Delete at Position\n");
        printf("8. Delete After Node\n");
        printf("9. Insert After\n");
        printf("10. Insert Before\n");
        printf("11. Append List\n");
        printf("12. Count\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(node);
                break;
            case 2:
                // Search for an element
            {
                int target;
                printf("Enter the element to search: ");
                scanf("%d", &target);
                int result = search(node, target);
                if (result != -1) {
                    printf("%d found at position %d\n", target, result);
                } else {
                    printf("%d not found in the list\n", target);
                }
            }
                break;
            case 3:
                // Sort the list
                sort(&node);
                printf("List sorted in ascending order:\n");
                traversal(node);
                break;
            case 4:
                // Reverse the list
                reverse(&node);
                printf("List reversed:\n");
                traversal(node);
                break;
            case 5:
                // Delete after a node
                deleteAfter(node);
                break;
            case 6:
                // Delete before a node
            {
                int target;
                printf("Enter the element before which to delete: ");
                scanf("%d", &target);
                deleteBefore(&node, target);
            }
                break;
            case 7:
                // Delete at a position
            {
                int position;
                printf("Enter the position at which to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&node, position);
            }
                break;
            case 8:
                // Delete after a specific node value
            {
                int data;
                printf("Enter the data of the node after which to delete: ");
                scanf("%d", &data);
                deleteAfterNode(&node, data);
            }
                break;
            case 9:
                // Insert after a specific node value
            {
                int data, newData;
                printf("Enter the data of the node after which to insert: ");
                scanf("%d", &data);
                printf("Enter the data to insert: ");
                scanf("%d", &newData);
                insertAfter(node, data, newData);
            }
                break;
            case 10:
                // Insert before a specific node value
            {
                int data, newData;
                printf("Enter the data of the node before which to insert: ");
                scanf("%d", &data);
                printf("Enter the data to insert: ");
                scanf("%d", &newData);
                insertBefore(&node, data, newData);
            }
                break;
            case 11:
                // Create and append another list
            {
                printf("Create List to Append:\n");
                struct sll *node2 = NULL;
                createList(&node2);
                printf("List to Append:\n");
                traversal(node2);

                printf("Appending List to List 1...\n");
                appendList(&node, node2);
                printf("Combined List:\n");
                traversal(node);
            }
                break;
            case 12:
                // Count the number of elements in the list
                printf("Number of elements in the list: %d\n", count(node));
                break;
            case 13:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 13);

    return 0;
}

// Function to create a linked list
void createList(struct sll **node) {
    char ch;
    int i = 1;

    *node = (struct sll *)malloc(sizeof(struct sll));
    if (*node == NULL) {
        printf("\nMemory is not allocated\n");
        exit(0);
    }

    struct sll *current = *node;
    // Read the data of the first node
    printf("Enter the data of %d node: ", i);
    scanf("%d", &current->data);
    current->next = NULL;
    i++;
    while ((ch = getchar()) != '\n'); // Clear the newline from input buffer

    do {
        current->next = (struct sll *)malloc(sizeof(struct sll));
        if (current->next == NULL) {
            printf("\nMemory is not allocated ");
            exit(0);
        }
        current = current->next;
        printf("\nEnter the data of the %d node: ", i); // second node
        scanf("%d", &current->data);
        current->next = NULL;
        i++;
        printf("Would you like to continue? (y/n): ");
        while ((ch = getchar()) != '\n'); // Clear the newline from input buffer
        ch = getchar(); // Read the user's choice
    } while (ch == 'y' || ch == 'Y'); // Continue while user enters 'y' or 'Y'
}

// Function to traverse and print the linked list
void traversal(struct sll *node) {
    printf("Linked List: ");
    while (node != NULL) {
        printf("\t%d\t", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to insert a new node at the end of the linked list
void insert(struct sll *node) {
    struct sll *newNode;
    newNode = (struct sll *)malloc(sizeof(struct sll));
    if (newNode == NULL) {
        printf("\nMemory is not allocated");
        exit(0);
    }
    printf("\nEnter the data of the new node: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = newNode;
}

// Function to search for an element in the linked list
int search(struct sll *node, int target) {
    int position = 1;
    while (node != NULL) {
        if (node->data == target) {
            return position;
        }
        node = node->next;
        position++;
    }
    return -1;
}

// Function to sort the linked list in ascending order
void sort(struct sll **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    int swapped;
    struct sll *ptr1;
    struct sll *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap data values
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to reverse the linked list
void reverse(struct sll **head) {
    struct sll *prev = NULL;
    struct sll *current = *head;
    struct sll *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

// Function to count the number of elements in the linked list
int count(struct sll *node) {
    int count = 0;
    while (node != NULL) {
        count++;
        node = node->next;
    }
    return count;
}

// Function to delete a node after the current node
void deleteAfter(struct sll *node) {
    if (node == NULL || node->next == NULL) {
        printf("Cannot delete. List is empty or the last node.\n");
        return;
    }

    struct sll *temp = node->next;
    node->next = temp->next;
    free(temp);
}

// Function to delete a node before a specific target node value
void deleteBefore(struct sll **head, int target) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("Cannot delete. List is empty or has only one element.\n");
        return;
    }

    if ((*head)->data == target) {
        printf("Cannot delete before the first node.\n");
        return;
    }

    struct sll *current = *head;
    while (current->next != NULL && current->next->data != target) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Element %d not found in the list.\n", target);
        return;
    }

    struct sll *temp = current->next;
    current->next = temp->next;
    free(temp);
}

// Function to delete a node at a specific position
void deleteAtPosition(struct sll **head, int position) {
    if (*head == NULL) {
        printf("Cannot delete. List is empty.\n");
        return;
    }

    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        struct sll *temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }

    struct sll *current = *head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct sll *temp = current->next;
    current->next = temp->next;
    free(temp);
}

// Function to delete a node after a specific node value
void deleteAfterNode(struct sll **head, int data) {
    struct sll *current = *head;

    while (current != NULL && current->data != data) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Element %d not found in the list.\n", data);
        return;
    }

    if (current->next == NULL) {
        printf("Cannot delete. Element %d is the last node.\n", data);
        return;
    }

    struct sll *temp = current->next;
    current->next = temp->next;
    free(temp);
}

// Function to insert a new node after a specific node value
void insertAfter(struct sll *node, int data, int newData) {
    struct sll *current = node;
    while (current != NULL) {
        if (current->data == data) {
            struct sll *newNode = (struct sll *)malloc(sizeof(struct sll));
            if (newNode == NULL) {
                printf("\nMemory is not allocated");
                exit(0);
            }
            newNode->data = newData;
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    printf("Element %d not found in the list. Insertion failed.\n", data);
}

// Function to insert a new node before a specific node value
void insertBefore(struct sll **head, int data, int newData) {
    struct sll *current = *head;
    struct sll *prev = NULL;

    while (current != NULL) {
        if (current->data == data) {
            struct sll *newNode = (struct sll *)malloc(sizeof(struct sll));
            if (newNode == NULL) {
                printf("\nMemory is not allocated");
                exit(0);
            }
            newNode->data = newData;
            newNode->next = current;
            if (prev != NULL) {
                prev->next = newNode;
            } else {
                *head = newNode;
            }
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Element %d not found in the list. Insertion failed.\n", data);
}

// Function to append List 2 to List 1
void appendList(struct sll **list1, struct sll *list2) {
    if (*list1 == NULL) {
        *list1 = list2;
    } else {
        struct sll *current = *list1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = list2;
    }
}
