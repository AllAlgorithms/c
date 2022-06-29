#include<stdio.h>
#include<stdlib.h>
struct CET
{
char name[20];
int marks;
char city[20];
int phone;
struct CET *next;
};
typedef struct CET NODE;
NODE *LLnode,*head,*temp,*prev;
NODE* insert_at_front(NODE *);
NODE* insert_at_end(NODE *);
NODE* delete_at_front(NODE *);
NODE* delete_at_end(NODE *);
void display(NODE *);


main()
{
int ch;
head=NULL;

do
{
    printf("1--insert node at the front\n");
    printf("2--insert node at the end\n");
    printf("3--delete a node at the front\n");
    printf("4--delete a node at the end\n");
    printf("5--display the linked list\n");
   printf("6--close the program\n");

printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:  head=insert_at_front(head);

                break;
case 2: head=insert_at_end(head);

                break;
case 3:head=delete_at_front(head);

                 break;
case 4: head=delete_at_end(head);

                 break;
case 5:   display(head);
                break;
case 6: exit(0);break;
default:printf("Invalid choice\n");
                break;
}
}while(ch!=6);


}
NODE* insert_at_front(NODE *head)
{
    LLnode=(NODE *)malloc(sizeof(NODE));
                printf("enter the name, marks, city, phone\n");
                scanf("%s%d%s%d",&LLnode->name,&LLnode->marks,&LLnode->city,&LLnode->phone);

                if(head==NULL)
                {
                    head=LLnode;
                    head->next=NULL;
                }
                else
                {
                  LLnode->next=head;
                  head=LLnode;
                }
        return(head);

}

NODE* insert_at_end(NODE *head)
{
    LLnode=(NODE *)malloc(sizeof(NODE));
                printf("enter the name, marks, city, phone\n");
                scanf("%s%d%s%d",&LLnode->name,&LLnode->marks,&LLnode->city,&LLnode->phone);
                LLnode->next=NULL;
                if(head==NULL)
                {
                    head=LLnode;
                }
                else
                {
                    temp=head;
                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=LLnode;
                }
        return(head);

}

NODE* delete_at_front(NODE *head)
{
    if(head==NULL)
                {
                    printf("Linked list is empty...cant delete a node\n");
                 }
                 else
                 {
                     temp=head;
                     printf("node deleted=%s%d%s%d\n",temp->name,temp->marks,temp->city,temp->phone);
                     head=head->next;
                     free(temp);
                 }
                return(head);
}

NODE*  delete_at_end(NODE *head)
{
    if(head==NULL)
                {
                    printf("Linked list is empty...cant delete a node\n");
                 }
                 else if(head->next==NULL)
                 {
                     printf("node deleted=%s%d%s%d\n",temp->name,temp->marks,temp->city,temp->phone);
                     free(head);
                     head=NULL;
                 }
                 else
                 {
                     temp=head;
                     while(temp->next!=NULL)
                     {
                         prev=temp;
                         temp=temp->next;
                     }
                     printf("node deleted=%s%d%s%d\n",temp->name,temp->marks,temp->city,temp->phone);
                     free(temp);
                     prev->next=NULL;
                 }
                 return(head);
}


void display(NODE *head)
{
    if(head==NULL)
              {
                    printf("Students data list is empty\n");
                }
                else
                {
                printf("Students information is as below\n");
                   temp=head;
                   while(temp!=NULL)
                   {
                       printf("name= %s\nmarks= %d\ncity= %s\nphone= %d\n",temp->name,temp->marks,temp->city,temp->phone);
                       temp=temp->next;
                   }
                   printf("\n");
                }
}
