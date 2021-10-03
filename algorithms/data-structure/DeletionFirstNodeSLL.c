#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
  
struct node *start=NULL, *temp = NULL;
  
struct node *create(struct node *start);
struct node *display(struct node *start);
struct node *insert_beg(struct node *start);
struct node *insert_end(struct node *start);
struct node *insert_before(struct node *start);
struct node *insert_after(struct node *start);
struct node *insert_at_sorted(struct node *start);
struct node *delete_beg(struct node *start);
struct node *delete_node(struct node *start);
struct node *delete_end(struct node *start);
struct node *delete_before(struct node *start);
struct node *delete_after(struct node *start);
struct node *delete_list(struct node *start);
struct node *sort_list(struct node *start);

main()
{
	int option;
	do
		{
			printf("\n\n*************MAIN MENU***********************");
			printf("\n 1. create a list");
			printf("\n 2. display the list");
			printf("\n 3. add a node at the begining");
			printf("\n 4. add a node at the end");
			printf("\n 5. add a node before at the given node");
			printf("\n 6. add a node after at the given node");
			printf("\n 7. add a node in a sorted linked list");
			printf("\n 8. delete a node at the begining ");
			printf("\n 9. delete a node at the end ");
			printf("\n 10. delete a node");
			printf("\n 11. delete a node before at the given node");
			printf("\n 12. delete a node after at the given node");
			printf("\n 13. delete a node in a sorted linked list");
			printf("\n 14. sort a list");
			printf("\n 15. exit");
			printf("\n\n*********************************************");
			printf("\n enter your option:");
			scanf("%d",&option);
			switch(option)
		{
					case 1:
						start=create(start);
						printf("\n linked list created");
						break;
					case 2:
					    start=display(start);
						break;
					case 3:
					     start=insert_beg(start);
						 break;
					case 4:
					     start=insert_end(start);
					     break;
					case 5:
					     start=insert_before(start);
						 break;
					case 6:
					     start=insert_after(start);
						 break;
					case 7:
					      start=insert_at_sorted(start);
					      break;
					case 8:
						  start=delete_beg(start);
						  break;
					case 9:
						  start=delete_end(start);
						  break;
					case 10:
					      start=delete_node(start);
						  break;	  
					case 11:
						  start=delete_before(start);
						  break;
					case 12:
						  start=delete_after(start);
						  break;
					case 13:
						  
						  break;
					case 14:
					      start=delete_list(start);
					      break;
					case 15:
						  start=sort_list(start);
						  break;  	  
					default:
					     printf("\n you entered a wrong option");	 	 	 	 	 		
		}
	}
	while(option!=15);
	getch();
	return 0;
}
struct node *create(struct node *Start)
{
	struct node *new_node;
	int n;
	printf("\n enter -1 to end");
	printf("\n enter the data:");
	scanf("%d",&n);
	while(n!=-1)
	{
			new_node=(struct node*)malloc(sizeof(struct node*));
			new_node->data = n;
			new_node->next=NULL;
			if(start==NULL)
			{
				start=new_node;
				temp = new_node;
			}
			else
			{
				temp->next=new_node;
				temp = temp -> next;
			}
		printf("\n enter the data:");
		scanf("%d",&n); 
	}	
	return start;
}		
struct node *display(struct node *Start)
{
	struct node *ptr;
	ptr=start;
	printf("\n");
	while(ptr!= NULL)
		{
			printf("\t %d",ptr->data);
			ptr=ptr->next;		 
		}
		return start;      
}
struct node *insert_beg(struct node *start)
{
struct node *new_node;
	int n;
	printf("\n Enter the data : ");
	scanf("%d", &n);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = n;
	new_node -> next = start;
	start = new_node;
	return start;
}
struct node *insert_end(struct node *start)
{
	struct node *ptr, *new_node;
	int n;
	printf("\n Enter the data : ");
	scanf("%d", &n);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = n;
	new_node -> next = NULL;
	
	if(start == NULL)
	{
		return new_node;
	}
	
	ptr = start;
	while(ptr -> next != NULL)
	{
		ptr = ptr -> next; 
	}
	
	ptr->next=new_node;
	new_node->next=NULL; 
 	return start;
}
struct node *insert_before(struct node *start)
{
	struct node *new_node, *ptr, *preptr;
		int num, val;
		printf("\n Enter the data :");
		scanf("%d", &num);
		printf("\n Enter the value before which the data has to be inserted : ");
		scanf("%d", &val);
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node -> data = num;
		ptr = start;
while(ptr->data!=val)
	       {
			preptr = ptr;
			 ptr = ptr -> next;
			}
			preptr -> next = new_node;
			new_node -> next = ptr;
			return start;
}
struct node *insert_after(struct node *start)
{
struct node *new_node, *ptr, *preptr;
	int num, val;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	printf("\n Enter the value after which the data has to be inserted : ");
	scanf("%d", &val);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	
	ptr = start;
	while(ptr -> data != val)
	{
		ptr = ptr -> next;
	}
	temp = ptr -> next;
	ptr -> next = new_node;
	new_node -> next = temp;
	return start;
}

struct node *insert_at_sorted(struct node *start)
{
	struct node *new_node,*ptr,*preptr;
		int num;
		printf("\n enter the data:");
		scanf("%d",&num);
		new_node=(struct node*)malloc(sizeof(struct node*));
		new_node->data=num;
		ptr=start;
		while(ptr->data<num)
		{
			preptr=ptr;
			ptr=ptr->next;
			if(ptr==NULL)
			break;
			if(ptr==NULL)
			{
				preptr->next=new_node;
				new_node->next=NULL;
				
            }
            else
            {
            	new_node->next=ptr;
            	preptr->next=new_node;
			}
			
		}
	return start;		
}
struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr = start;
	start = start -> next;
//	ptr -> next = NULL;
	free(ptr);
	return start;
}

struct node *delete_end(struct node *start)
{
	struct node *ptr, *preptr;
	ptr = start;
    while(ptr->next != NULL)	
		{
			 preptr = ptr;
			 ptr = ptr -> next;
		}
	preptr -> next = NULL;
	free(ptr);
return start;
}

struct node *delete_before(struct node *start)
{
	return start;
}

struct node *delete_node(struct node *start)
{
struct node *ptr, *preptr;
		int val;
		printf("\n Enter the value of the node which has to be deleted : ");
        scanf("%d", &val);
		ptr = start;
	    if(ptr -> data == val)
		{
 			start = delete_beg(start);
 			return start;
		}
		else
		{
		while(ptr -> data != val)
 			{
 				preptr = ptr;
 				ptr = ptr -> next;
 			}
 			preptr -> next = ptr -> next;
 			free(ptr);	
		}
	return start;
}
struct node *delete_after(struct node *start)
{
struct node *ptr;
	int val;
	printf("\n Enter the value after which the node has to deleted : ");
	scanf("%d", &val);
	ptr = start;
		while(ptr -> data != val)
		{
 			ptr = ptr -> next;
		}
	temp = ptr -> next;
	ptr -> next = ptr -> next -> next;
	free(temp);
return start;
}
struct node *delete_list(struct node *start)
{
	 struct node *ptr; 
		if(start!=NULL)
	    {
 			ptr=start;
 			while(ptr != NULL)
 		{
 			printf("\n %d is to be deleted next", ptr -> data);
 			start = delete_beg(ptr);
			ptr = start;
        }
}
return start;
}

struct node *sort_list(struct node *start)
{
	struct node *ptr1,*ptr2;
	int temp1;
	ptr1=start;
	while(ptr1->next!=NULL)
	{
		ptr2=ptr1->next;
		while(ptr2!=NULL)
		{
			if(ptr1->data>ptr2->data)
			{
					temp1=ptr1->data;
					ptr1->data=ptr2->data;
					ptr2->data=temp1;	
			}
			ptr2=ptr2->next;
		}	
		ptr1=ptr1->next;
	 }	 
	 return start;
}
