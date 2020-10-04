#include <stdio.h>
#include<stdlib.h>

#define MAX 5

void Push();
void Pop();
void Display();
int Stack[5];
int Top=-1;

void main()
{
    int ch;

    do
    {
        printf("\n\n\n1. PUSH \n2. POP \n3. DISPLAY \n4. EXIT");
        printf("\nENTER YOUR CHOICE\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: Push();
                    break;
            case 2: Pop();
                    break;
            case 3: Display();
                    break;
        }
    }while(ch!=4);
}

void Push()
{
    int item;

    if(Top==MAX-1)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("Enter a value you want to PUSH\n");
        scanf("%d",&item);

        Top=Top+1;

        Stack[Top]=item;
    }
}

void Pop()
{
    int item;
    if(Top==-1)
    {
        printf("\nUNDERFLOW\n");
    }
    else
    {

        item=Stack[Top];
        Top=Top-1;

        printf("\n%d Item Deleted from stack",item);
    }
}
void Display()
{
    int i;

    if(Top==-1)
    {
        printf("\nUNDERFLOW\n");
    }
    else
    {
        printf("\nStack element are --->");
        for(i=Top;i>=0;i--)
        {
            printf("\n%d",Stack[i]);
        }
    }
