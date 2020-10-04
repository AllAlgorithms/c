#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* link;
}node;
node *head = NULL;

node* add_at_beg(int d)
{
	node* ptr = head;
	node *temp = malloc(sizeof(node));
	temp->data = d;
	temp->link = ptr;
	head = temp;
	return head;
}

node* add_at_end(node* ptr,int d)
{
	node* temp = malloc(sizeof(node));
	temp->data = d;
	temp->link = NULL;
	ptr->link = temp;
	ptr = temp;
	return temp;
}

void create_list(int n)
{
	int d,i;
	head = malloc(sizeof(node));
	printf("\nEnter the data for node 1 : ");
	scanf("%d",&d);
	head->data = d;
	head->link = NULL;
	node* ptr = head;
	for(i=2;i<=n;i++)
	{
		printf("\nEnter the data for node %d : ",i);
		scanf("%d",&d);
		ptr = add_at_end(ptr,d);
	}
}

void add_at_pos(int pos,int d)
{
	int i;
	node* ptr = head;
	node* temp = malloc(sizeof(node));
	temp->data = d;
	temp->link = NULL;
	if(pos==1)
	head = add_at_beg(d);
	else
	{
	while(pos!=2)
	{
		ptr = ptr->link;
		pos--;
	}
	temp->link = ptr->link;
	ptr->link = temp;
	}
}

void display(int m)
{
	node* ptr = head;
	if(m==1)
	printf("\nOur linked list is : ");
	else
	printf("\nOur updated linked list is : ");
	while(ptr!=NULL)
	{
		printf("%d -> ",ptr->data);
		ptr = ptr->link;
	}
	printf("NULL");
}

int main()
{
	int n,m=1,d,pos;
	char ch;
	printf("Enter the number of nodes you want in your list : ");
	scanf("%d",&n);
	create_list(n);
	display(m);
	printf("\nDo you want to insert a node in your list (y/n) : ");
	ch = getch();
	if(ch == 'y' || ch == 'Y')
	{
		printf("\nEnter the position at which you want to insert your node : ");
		scanf("%d",&pos);
		if(pos<1 || pos>n+1)
		{
		printf("\nInvalid Position!");
		exit(0);
	    }
		else
		{
		printf("\nEnter the data you want to insert : ");
		scanf("%d",&d);
		}
		add_at_pos(pos,d);
		m=2;
		display(m);
	}
	else
	printf("\nTheir is no updation in our linked list.");
	return 0;
}
