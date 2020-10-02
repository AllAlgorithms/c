#include <stdio.h>
#include <stdlib.h>

int lcount = 0;

struct tnode
{
    int data;
    struct tnode *left, *right;
};

struct tree
{
    struct tnode *root;
};

void insert(struct tree *q, int x)
{
    struct tnode *p, *prev;
    prev = NULL;
    p = (struct tnode *)malloc(sizeof(struct tnode));
    p->data = x;
    p->left = p->right = NULL;
    if (q->root == NULL)
    {
        q->root = p;
    }
    else
    {
        struct tnode *l = q->root;
        while (l)
        {
            prev = l;
            if (p->data < l->data)
                l = l->left;
            else
                l = l->right;
        }
        if (p->data >= prev->data)
            prev->right = p;
        else
            prev->left = p;
    }
}

void deletenode(struct tree *q, int x)
{
    struct tnode *p, *rp, *prev, *f, *s;

    prev = NULL;
    p = q->root;

    while (p != NULL)
    {
        if (p->data == x)
        {
            break;
        }
        prev = p;
        if (x < p->data)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    if (p == NULL)
    {
        printf("Element Not Found!\n");
        return;
    }
    if (p->left == NULL && p->right == NULL)
    {
        rp = NULL;
    }
    else if (p->left == NULL)
    {
        rp = p->right;
    }
    else if (p->right == NULL)
    {
        rp = p->left;
    }
    else
    {
        rp = p->right;
        s = rp->left;
        if (s == NULL)
        {
            rp->left = p->left;
        }
        else
        {
            while (s != NULL)
            {
                f = rp;
                rp = s;
                s = s->left;
            }
            f->left = rp->right;
            rp->left = p->left;
            rp->right = p->right;
        }
    }
    if (prev == NULL)
    {
        q->root = rp;
    }
    else if (prev->left == p)
    {
        prev->left = rp;
    }
    else
    {
        prev->right = rp;
    }
}

void disp_inorder(struct tnode *q)
{
    if (q != NULL)
    {
        disp_inorder(q->left);
        printf("%d\t", q->data);
        disp_inorder(q->right);
    }
}

void disp_preorder(struct tnode *q)
{
    if (q != NULL)
    {
        printf("%d\t", q->data);
        disp_inorder(q->left);
        disp_inorder(q->right);
    }
}

void disp_postorder(struct tnode *q)
{
    if (q != NULL)
    {
        disp_inorder(q->left);
        disp_inorder(q->right);
        printf("%d", q->data);
    }
}

int leafcount(struct tnode *p)
{
    if (p != NULL)
    {
        if (p->left == NULL && p->right == NULL)
        {
            lcount++;
        }
        else
        {
            leafcount(p->left);
            leafcount(p->right);
        }
    }
}

int count_interiornode(struct tnode *root)
{
    int count = 0;
    if (root == NULL)
        return 0;
    else if ((root->left == NULL) && (root->right == NULL))
        return 0;
    if (root->left != NULL || root->right != NULL)
    {
        count = 1;
        if (root->left != NULL)
            count += count_interiornode(root->left);
        if (root->right != NULL)
            count += count_interiornode(root->right);
    }
    return count;
}

int count_node(struct tnode *root)
{
    return ((leafcount(root)) + (count_interiornode(root)));
}

int main()
{
    struct tree t1;
    t1.root = NULL;
    int choice, ele, count;
    do
    {
        printf("\nEnter the choice from the following :\n");
        printf("1.Add an element in the binary tree\n");
        printf("2.Delete an element in the binary tree\n");
        printf("3.Display in inorder fashion\n");
        printf("4.Display in preorder fashion\n");
        printf("5.Display in postorder fashion\n");
        printf("6.Number of Leaf Nodes\n");
        printf("7.Number of Interior Nodes\n");
        printf("8.Total Number of Nodes\n");
        printf("9.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be added to the binary tree :");
            scanf("%d", &ele);
            insert(&t1, ele);
            printf("The element  %d is inserted", ele);
            break;
        case 2:
            printf("Enter the element to be deleted from binary tree :");
            scanf("%d", &ele);
            deletenode(&t1, ele);
        case 3:
            printf("\nThe numbers in the inorder fashion are : ");
            disp_inorder(t1.root);
            break;
        case 4:
            printf("\nThe numbers in the preorder fashion are : ");
            disp_preorder(t1.root);
            break;
        case 5:
            printf("\nThe numbers in the postorder fashion are : ");
            disp_postorder(t1.root);
            break;
        case 6:
            count = leafcount(t1.root);
            printf("The number of Leaf nodes are : %d", count);
            break;
        case 7:
            count = count_interiornode(t1.root);
            printf("The number of interior nodes are : %d", count);
            break;
        case 8:
            count = count_node(t1.root);
            printf("The total number of nodes are : %d", count);
            break;
        }
    } while (choice != 9);
    return 0;
}
