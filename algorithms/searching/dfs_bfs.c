// dfs_bfs.c
// Depth First Search and Breadth First Search
#include<stdio.h>
#include<malloc.h>
#define n 10
#define max 10

int top=-1;
int front=-1,rear=-1;
int cq[max];
int adj[n][n];
int stack[max];
int visited1[max];
int visited2[max];

void push(int val)
{
if(top==max-1)
printf("\n overflow");
else
stack[++top]=val;
}

int pop()
{
if(top==-1)
{
printf("\nunderflow");
return -1;
}
else
return stack[top--];
}

void add(int val)
{
if((rear==max-1&&front==0))
printf("\noverflow");
else if(rear==-1)
{
rear=0;front=0;
}
else if(rear==max-1)
rear=0;
else
rear++;
cq[rear]=val;
}

int delete()
{
int val;
if(rear==-1)
printf("\nempty");
else if(front==max-1)
front=0;
else if(front==rear)
front=rear=-1;
else front++;
return(cq[front]);
}

void dfs(int visited2[],int start)
{   int i;
for(i=0;i<max;i++)
visited2[i]=0;
push(start);
printf("\t%d",start);
visited2[start]=1;
while(top!=-1)
{
	start=pop();
	for(i=0;i<max;i++)
	{
		if(adj[start][i]==1 &&visited2[i]==0)
		{
			push(i);
			printf("\t%d",i);
			visited2[i]=1;

		}
	}
	}
}

void bfs(int visited1[],int start)
{
int i,u;
for(i=0;i<max;i++)
visited1[i]=0;
add(start);
printf("\t%d",start);
visited1[start]=1;
visited1[0]=1;
while(front!=-1)
{
for(i=0;i<max;i++)
{
	if(adj[start][i]==1&&visited1[i]==0)
	{
		add(i);
	}
}
	start=delete();
	if(visited1[start]==0)
	{
	printf("\t%d",start);
	visited1[start]=1;
	}
}
}

void initialise()
{
int i,j;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
	adj[i][j]=0;
}
}
}

void addedge(int i,int j)
{
adj[i][j]=1;
adj[j][i]=1;
}

void removeedge(int i,int j)
{
adj[i][j]=0;
adj[j][i]=0;
}
int adjacent(int i,int j)
{
return(adj[i][j]);
}

void main()
{
int i,j;
int a,b,start;
int opt;
initialise();
do
{
printf("\n 1=create edge \n 2= delete edge \n 3= bfs \n 4=dfs \n enter choice \n");
scanf("%d", &opt);
switch(opt){
    case 1:
    printf("\n Enter two numbers to create edge");
scanf("%d %d",&i,&j);
addedge(i,j);
break;
case 2:
printf("\nenter two numbers to delete edge");
scanf("%d %d",&i,&j);
removeedge(i,j);
break;
case 3:
printf("\nenter the start for bfs ");
scanf("%d",&start);
bfs(visited1,start);
break;
case 4:
printf("\nenter start for dfs");
scanf("%d",&start);
dfs(visited2,start);
break;
default:
printf("Invalid input");
}
printf("Continue? \n 1=yes \n 0=no");
scanf("%d", &opt);
}while(opt==1);
}
