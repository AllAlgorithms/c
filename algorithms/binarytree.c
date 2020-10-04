#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
typedef struct Node Node;
struct Node{
    int value;
    Node* left;
    Node* right;
};

Node* CreateNode(int value) {
    Node* node=(Node*)malloc(sizeof(Node));
    node->value=value;
    node->left = NULL;
    node->right = NULL;
}
void AddValue(Node* node,int value){
    if(value>node->value){
        if(node->right) return AddValue(node->right,value);
        node->right=CreateNode(value);
    }else if(value<node->value){
        if(node->left) return AddValue(node->left,value);
        node->left=CreateNode(value);
    }
}
void Print(Node* node){
    if(node->left) Print(node->left);
    printf("%d ",node->value);
    if(node->right) Print(node->right);
}
int findValue(Node* node,int value){
    if( node->value > value ) {
        if(node->left)return findValue(node->left,value);
    }
    else if( node->value < value ) {
        if(node->right) return findValue(node->right,value);
    }
    else return 1;
    return 0;
}
Node* CreateRandomTree(){
    
    int n = 5,i;
    srand(time(0));
    Node* root=CreateNode(rand() % 100);
    int deep= rand() % 50;
    for(  i=0 ; i<deep; i++){
        AddValue(root,rand() %  100);
    }
    return root;
}

int main(){
    Node* x=CreateRandomTree();
    AddValue(x,20);
    Print(x);
    return 0;
}