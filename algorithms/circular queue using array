#include <stdio.h>

int isfull();
int isempty();
void enqueue(int);
int dequeue();
void display();

int cq[5] ={0};
int rear=-1;
int front=-1;

main()
{
    int ch,ele;
    do
    {
        printf("\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\n Enter Your Choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                if(isfull())
                    printf("\n Circular Queue is Full");
                else
                {
                    printf("\n Enter Element to Insert:");
                    scanf("%d",&ele);
                    enqueue(ele);
                }
                break;
                
            case 2:
                if(isempty())
                    printf("\n Circular Queue is Empty");
                else
                {
                    ele=dequeue();
                    printf("\n %d is deleted Element",ele);
                }
                break;
                
            case 3:
                if(isempty())
                    printf("\n Circular Queue is Empty");
                    else
                        display();
                    break;
        }
    }while(ch!=5);
}

int isfull()
{
    if((front==0 && rear==4)  ||  (rear+1 == front))
       return 1;
    else
       return 0;
}

int isempty()
{
    if(front==-1)
       return 1;
    else
       return 0;
}

void enqueue(int ele)
{
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else if(rear ==4)
        rear=0;
    else
        rear=rear+1;
    cq[rear]=ele;
}

int dequeue()
{
    int ele;
    ele = cq[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front == 4)
        front=0;
    else
        front = front + 1;
    return ele;
}
void display()
{
    int i;
    printf("\n front = %d and rear = %d\n",front,rear);
    if(rear > front)
    {
        for(i=front;i<=rear;i++)
            printf("| %d |",cq[i]);
    }
    else
    {
        for(i=front;i<=4;i++)
            printf("| %d |",cq[i]);
        for(i=0;i<=rear;i++)
            printf("| %d |",cq[i]);
    }
}
