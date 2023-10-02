#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int data)
{
    struct Node *n = malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
struct Node *Recsearch(struct Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return Recsearch(root->left, key);
    }
    else
    {
        return Recsearch(root->right, key);
    }
}
struct Node *Itersearch(struct Node *root, int key)
{
    while (root!=NULL){
        if (key==root->data){
            return root;
        }
        else if (key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}
int main()
{
    struct Node *p = createNode(50);
    struct Node *q = createNode(40);
    struct Node *r = createNode(20);
    struct Node *s = createNode(45);
    struct Node *t = createNode(60);
    p->left = q;
    q->left = r;
    q->right = s;
    p->right = t;
    struct Node *n = Recsearch(p, 45);
    printf("Search node: %d\n", n->data);
    struct Node *m = Itersearch(p, 20);
    printf("Search node: %d", m->data);
    return 0;
}
