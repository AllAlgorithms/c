// multiply using linked list
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
        struct node *te = mat->head;
        while (te->next != NULL)
        {
            te = te->next;
        }
        te->next = new_node;
    }
}

void multiply(struct sparse_matrix *mat1, struct sparse_matrix *mat2, struct sparse_matrix *res)
{
    struct node *temp = mat1->head;
    while (temp != NULL)
    {
        struct node *temp2 = mat2->head;
        while (temp2 != NULL)
        {
            if (temp->col == temp2->row)
            {
                int row = temp->row;
                int col = temp2->col;
                int val = temp->val * temp2->val;

                struct node *te = res->head;
                while (te != NULL && (te->row < row || te->col < col))
                {
                    te = te->next;
                }

                if (te == NULL || te->row != row || te->col != col)
                {
                    insert_node(res, row, col, val);
                }
                else
                {
                    te->val += val;
                }
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

void print_sparse_matrix(struct sparse_matrix *mat)
{
    struct node *te = mat->head;
    while (te != NULL)
    {
        printf("(%d, %d, %d) ", te->row, te->col, te->val);
        te = te->next;
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

    multiply(&mat1, &mat2, &res);

    printf("The product of the two sparse matrices is: ");
    print_sparse_matrix(&res);

    return 0;
}
