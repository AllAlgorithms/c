#include <stdio.h>
#include <stdlib.h>

struct btreenode
{
    struct btreenode *leftchild;
    int data ;
    struct btreenode *rightchild;
};
 
void insert ( struct btreenode **, int );
void inorder ( struct btreenode * );
 
int main( )
{
    struct btreenode *bt;
    int i, j;
    bt = NULL ;

    int arr[] = {12, 11, 13, 5, 6, 7};
    int num = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    for (i = 0 ; i < num ; i++){
        printf ( "%d\t", arr[i]) ;
    }
 
    for (j = 0 ; j < num ; j++){
        insert ( &bt, arr[j] ) ;
    }
 
    printf("\nSorted array is \n");
    inorder (bt) ;
 
    return 0;
}
 
void insert (struct btreenode **sr, int num)
{
    if ( *sr == NULL ){
        *sr = malloc (sizeof(struct btreenode));
 
        (*sr)->leftchild = NULL;
        (*sr)->data = num;
        (*sr)->rightchild = NULL;

    }else{
        if (num < (*sr)->data){
            insert (&( (*sr)->leftchild), num);
        }
        else{
            insert (&( (*sr)->rightchild), num);
        }
    }
}
 
void inorder (struct btreenode *sr)
{
    if ( sr != NULL ){
        inorder (sr->leftchild);
        printf ("%d\t", sr->data);
        inorder (sr->rightchild);
    }
}