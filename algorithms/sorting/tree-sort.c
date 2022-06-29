#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
int data;
struct node *left, *right;
};
struct node *root;
void ins(struct node *, int, int);
void inser(struct node *, int);
void display(struct node *);
int main()
{
int choice, no = 0, parentnode;
root = (struct node *) malloc (sizeof(struct node));
printf("\n Enter a number for parent node : ");
scanf("%d",&parentnode);
root -> data = parentnode;
root -> left = root -> right = NULL;
do{
printf("\n 1.Add element");
printf("\n 2.Sort");
printf("\n 3.Exit");
printf("\n Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter the element to insert : \n");
scanf("%d",&no);
inser(root, no);
break;
case 2:
printf("\n Sorted elements are : \n");
display(root);
break;
default:
printf("\n Invalid press...");
exit(0);
}
}while(choice < 3);
return 0;
}
void ins(struct node *n, int value, int opt)
{
struct node *t;
t = (struct node *)malloc (sizeof (struct node));
t -> data = value;
t -> left = t -> right = NULL;
if(opt == 1)
n -> left = t;
else
n -> right = t;
printf("%d is inserted",value);
if(opt == 1)
printf(" at the left \n");
else
printf(" at the right \n");
}
void inser(struct node *t,int x)
{
if(t -> data > x)
if(t -> left == NULL)
ins(t,x,1);
else
inser(t -> left, x);
else if(t -> data < x)
if(t -> right == NULL)
ins(t, x, 2);
else
inser(t -> right,x);
else
printf(" Element is already exist in the list ");
}
void display(struct node *p)
{
if(p != NULL)
{
display(p -> left);
printf("%5d",p -> data);
display(p -> right);
}
}