#include <stdio.h>
#include <stdlib.h>

typedef struct CLL{
    int id;
    int burstTime;
    int timeLeft;
    struct CLL *next;
} cll;

cll *createNode(int burst, int id){
    cll *node=(cll *)malloc(sizeof(cll));
    node->id=id;
    node->burstTime=burst;
    node->timeLeft=burst;
    node->next=NULL;
    return node;
}

int main(){

    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("\n");

    int burstTime;
    cll *head, *node;

    for (i = 0; i < n; i++)
    {
        printf("Name of the process: %d\n", i+1);
        printf("Enter the burst time: ");
        scanf("%d", &burstTime);
        if(i==0){
            head=createNode(burstTime, i+1);
            node=head;
        }
        else{
            node->next=createNode(burstTime, i+1);
            node=node->next;
        }
        printf("\n");
    }
    
    int quantum, wait=0, turn=0; 
    float waitSum=0.0, turnSum=0.0;
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    printf("\n");

    printf("process name\tburst time\twaiting time\tturn around time\n");
    
    while(head!=NULL){
        if(head->timeLeft<quantum){
            turn+=(head->timeLeft);

            printf("%d\t\t%d\t\t%d\t\t%d\n", head->id, head->burstTime, turn-(head->burstTime), turn);

            waitSum+=(turn-(head->burstTime));
            turnSum+=turn;
            cll *nullTemp=head;
            head=head->next;
            nullTemp->next=NULL;
        }else{
            turn+=quantum;
            (head->timeLeft)-=quantum;
            cll *nextTemp=head;
            head=head->next;
            node->next=nextTemp;
            node=node->next;
            nextTemp->next=NULL;
        }
    }

    printf("average waiting time is %.6f\n", waitSum/n);
    printf("average turn around time is %.6f\n", turnSum/n);

    return 0;
}