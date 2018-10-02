#include <stdio.h>
#include <stdlib.h>
struct llnode {
    int data;
    struct llnode *next;
};

void print(struct llnode *head) {
    struct llnode *tmp;
    tmp = head;
    while (tmp != NULL) {
        printf(" %d ", tmp->data);
        tmp = tmp->next;
    }
}
struct llnode *create(struct llnode *head) {
    struct llnode *newnode, *tmp;
    if (head == NULL) {
        int n, i = 2;
        printf("\nENTER NUMBER OF NODES=");
        scanf("%d", &n);
        head = (struct llnode *)malloc(sizeof(struct llnode));
        printf("\nENTER ELEMENTS: ");
        scanf("%d", &head->data);
        newnode = head;
        newnode->next = NULL;
        while (i <= n) {
            newnode->next = (struct llnode *)malloc(sizeof(struct llnode));
            newnode = newnode->next;
            scanf("%d", &newnode->data);
            i++;
        }
        newnode->next = NULL;
    }
    printf("\n");
    print(head);
    return head;
}

void copy() {
    struct llnode *head, *head1, *tmp, *newnode;
    head = NULL;
    head = create(head);
    tmp = head;
    head1 = (struct llnode *)malloc(sizeof(struct llnode));
    newnode = head1;
    newnode->data = tmp->data;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        newnode->next = (struct llnode *)malloc(sizeof(struct llnode));
        newnode = newnode->next;
        newnode->data = tmp->data;
    }
    newnode->next = NULL;
    printf("\nDUPLICATE LinkedList Is\n");
    print(head1);
}

void concat() {
    struct llnode *head1, *head2, *tmp;
    head1 = NULL; head2 = NULL;
    head1 = create(head1); head2 = create(head2);
    tmp = head1;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = head2;
    head2 = NULL;
    printf("\nCONCAT\n");
    print(head1);
}

void split() {
    struct llnode *head1, *head2, *tmp;
    int i = 1, n;
    head1 = NULL;
    head1 = create(head1);
    printf("\nENTER POSITION TO SPLIT=");
    scanf("%d", &n);
    tmp = head1;
    while (i < n - 1) {
        tmp = tmp->next;
        i++;
    }
    head2 = tmp->next;
    tmp->next = NULL;
    printf("\nll 1.\n");
    print(head1);
    printf("\nll 2.\n");
    print(head2);
}

struct llnode* reverseR(struct llnode *head) {
    if (head==NULL) {
        return NULL;
    } else if (head->next==NULL) {
        return head;
    } else {
        struct llnode *rest=reverseR(head->next);
        head->next->next=head;
        head->next=NULL;
        return rest;
    }
}

void reverse() {
    struct llnode *head, *rev;
    head = NULL;
    head = create(head);
    rev=reverseR(head);    
    printf("\nREVERSE\n");
    print(rev);
}

void noOfNodes() {
    struct llnode *head, *tmp;
    int n = 0;
    head = NULL;
    head = create(head);
    tmp = head;
    n++;
    while (tmp->next != NULL) {
        n++;
        tmp = tmp->next;
    }
    printf("\nNUMBER OF NODES=%d", n);
}

void main() {
    int c;
    while (1) {
        printf("\nSELECT AN OPTION\n1.COPY\t2.CONCATENATE\t3.SPLIT\t4.REVERSE\t5.NO OF NODES\t6.Exit\n");
        scanf("%d", &c);
        switch (c) {
        case 1:
            copy();
            break;
        case 2:
            concat();
            break;
        case 3:
            split();
            break;
        case 4:
            reverse();
            break;
        case 5:
            noOfNodes();
            break;
        case 6:
            exit(0);
        }
    }
}