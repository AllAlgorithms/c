#include <stdio.h>
#include<conio.h>
#include<stdlib.h>  
void front(int);  
struct node  
{  
    int data;  
    struct node *next;  
};  
struct node *head;  
void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values . . . . .\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
} 
void front(int item)  
    {  
        struct node *ptr = (struct node *)malloc(sizeof(struct node *));  
        if(ptr == NULL)  
        {  
            printf("\nOVERFLOW !!!\n");  
        }  
        else  
        {  
            ptr->data = item;  
            ptr->next = head;  
            head = ptr;  
            printf("\nGiven node is inserted\n");  
        }            
    } 
    void main ()  
{  
    int item;  
        printf("\nEnter the item which you want to insert?\n");  
        scanf("%d",&item);  
        front(item); 
        display();  
} 
