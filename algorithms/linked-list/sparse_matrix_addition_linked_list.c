// add using liked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int row;
    int col;
    int val;
    struct node *next;
};

struct sparse_matrix
{
    struct node *head;
};

void insert_node(struct sparse_matrix *mat, int row, int col, int val)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->row = row;
    new_node->col = col;
    new_node->val = val;
    new_node->next = NULL;

    if (mat->head == NULL)
    {
        mat->head = new_node;
    }
    else
    {
        struct node *temp = mat->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void add(struct sparse_matrix *mat1, struct sparse_matrix *mat2, struct sparse_matrix *res)
{
    struct node *temp = mat1->head;
    struct node *temp2 = mat2->head;

    while (temp != NULL && temp2 != NULL)
    {
        if (temp->row < temp2->row)
        {
            insert_node(res, temp->row, temp->col, temp->val);
            temp = temp->next;
        }
        else if (temp->row > temp2->row)
        {
            insert_node(res, temp2->row, temp2->col, temp2->val);
            temp2 = temp2->next;
        }
        else
        {
            if (temp->col < temp2->col)
            {
                insert_node(res, temp->row, temp->col, temp->val);
                temp = temp->next;
            }
            else if (temp->col > temp2->col)
            {
                insert_node(res, temp2->row, temp2->col, temp2->val);
                temp2 = temp2->next;
            }
            else
            {
                insert_node(res, temp->row, temp->col, temp->val + temp2->val);
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
    }

    while (temp != NULL)
    {
        insert_node(res, temp->row, temp->col, temp->val);
        temp = temp->next;
    }

    while (temp2 != NULL)
    {
        insert_node(res, temp2->row, temp2->col, temp2->val);
        temp2 = temp2->next;
    }
}

void print(struct sparse_matrix *mat)
{
    struct node *temp = mat->head;
    while (temp != NULL)
    {
        printf("(%d, %d, %d) ", temp->row, temp->col, temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct sparse_matrix mat1;
    struct sparse_matrix mat2;
    struct sparse_matrix res;

    mat1.head = NULL;
    mat2.head = NULL;
    res.head = NULL;

    insert_node(&mat1, 1, 2, 3);
    insert_node(&mat1, 2, 3, 4);

    insert_node(&mat2, 1, 3, 5);
    insert_node(&mat2, 2, 4, 6);

    add(&mat1, &mat2, &res);

    printf("The sum of the two sparse matrices is: ");
    print(&res);

    return 0;
}
