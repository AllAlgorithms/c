#ifndef tree__
#define tree__
typedef struct tree_
{
    int n;
    int max;
    int min;
    struct tree_ *left;
    struct tree_ *right;
    int flag;
    int sum;
} tree;
tree *createNode(int n);
tree *makeTree(int arr[], int n);
void preorder(tree *t, int h[], int *g);
void postorder(tree *t);
void postorder1(tree *t);

#endif
