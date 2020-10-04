#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node*next;
	int data;
};
struct Node*top=NULL;
void push(struct Node**node,int key){
	struct Node*new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=key;
	if(*node==NULL){
		new_node->next=*node;
		*node=new_node;
		top=new_node;
	}
	else{
		struct Node*temp=*node;
		new_node->next=temp;
	   *node=new_node;
		top=new_node;
	}
}
void pop(struct Node**node){
	if(*node==NULL){
		printf("deletion is not possible");
	}
	else{
		printf("\nthe value deleted is:-%d",top->data);
		struct Node*temp=*node;
		*node=temp->next;
		top=*node;
	}
}
void display(struct Node*node){
	while(node!=NULL){
		printf("\n%d",node->data);
		node=node->next;
	}
	printf("\nthe top value is:-%d",top->data);
}
int main(){
	struct Node*head=NULL;

	int i,a;
	do {
		printf("enter 1 for push\nenter 2 for pop \n enter 3 for display\nenter 4 for exit");
		printf("\n******************");
		printf("\nthe choice is :-");
		scanf("%d",&i);
		switch(i){
		
		case 1:
			printf("\nthe value you want to push :-");
			scanf("%d",&a);
			push(&head,a);
			break;
		
		case 2:
			pop(&head);
		     break;
		     
		case 3:
			display(head);
		    break;
		case 4:
		printf("you are exited");
		break;	
		default:printf("enter the valid choice");
	}
}while(i!=4);
	return 0;
}
