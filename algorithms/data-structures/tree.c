#include "tree.h"
#include "deque.h"
#include <stdio.h>
#include <stdlib.h>
tree *createNode(int n)
{
    tree *t = (tree *)malloc(sizeof(tree));
    t->flag = 0;
    t->left = NULL;
    t->right = NULL;
    t->n = n;
    t->min = 0;
    t->max = 0;
    t->sum = 0;
    return t;
}
tree *makeTree(int arr[], int n)
{
    tree *t = createNode(arr[0]);
    deque *a = NULL;
    pushback(&a, t);
    int f = 0;
    for (int i = 1; i < n; i++)
    {
        tree *temp;
        if (arr[i] != 0)
        {
            temp = createNode(arr[i]);
            pushback(&a, temp);
        }
        else
        {
            temp = NULL;
        }
        if (f == 0)
        {
            tree *h = front(a);
            h->left = temp;
            f++;
            f %= 2;
        }
        else
        {
            tree *h = front(a);
            h->right = temp;
            popfront(&a);
            f++;
            f %= 2;
        }
    }
    while (!isempty(a))
    {
        popback(&a);
    }
    free(a->next);
    free(a->last);
    free(a);
    return t;
}
void preorder(tree *t, int h[], int *g)
{
    if (t == NULL)
    {
        return;
    }
    if (t->left != NULL)
    {
        preorder(t->left, h, g);
    }
    if (t->right != NULL)
    {
        preorder(t->right, h, g);
    }
    if (t->right == NULL && t->left == NULL)
    {
        t->max = t->n;
        t->min = t->n;
        t->sum = t->n;
        t->flag = 1;
    }
    else if (t->right == NULL)
    {
        t->max = (t->n) > (t->left->max) ? (t->n) : (t->left->max);
        t->min = (t->n) < (t->left->min) ? (t->n) : (t->left->min);
        t->sum = t->left->sum + t->n;
        t->flag = 0;
        if (t->left->flag == 1 && t->left->max < t->n)
        {
            t->flag = 1;
        }
    }
    else if (t->left == NULL)
    {
        t->max = (t->n) > (t->right->max) ? (t->n) : (t->right->max);
        t->min = (t->n) < (t->right->min) ? (t->n) : (t->right->min);
        t->sum = t->n + t->right->sum;
        t->flag = 0;
        if (t->right->flag == 1 && t->right->min > t->n)
        {
            t->flag = 1;
        }
    }
    else
    {
        t->max = (t->n) > (t->left->max) ? (t->n) : (t->left->max);
        t->max = (t->max) > (t->right->max) ? (t->max) : (t->right->max);
        t->min = (t->n) < (t->right->min) ? (t->n) : (t->right->min);
        t->min = (t->min) < (t->left->min) ? (t->min) : (t->left->min);
        t->sum = t->n + t->left->sum + t->right->sum;
        t->flag = 0;
        if (t->left->flag == 1 && t->right->flag == 1 && t->left->max < t->n && t->right->min > t->n)
        {
            t->flag = 1;
        }
    }
    if (t->flag == 1)
    {
        h[(*g)] = t->sum;
        (*g)++;
    }
    return;
}
void postorder(tree *t)
{
    if (t == NULL)
    {
        return;
    }
    postorder(t->left);
    postorder(t->right);
    free(t);
}
void postorder1(tree *t)
{
    if (t == NULL)
    {
        return;
    }
    postorder1(t->left);
    postorder1(t->right);
    tree *temp = t->right;
    t->right = t->left;
    t->left = temp;
    return;
}
