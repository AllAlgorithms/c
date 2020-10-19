/*

Input format:
    First line would contain number n, which represents number of nodes in the graph (1 to n).
    Next n line would represent cost matrix. Where each line, representing a distance vector for that node, will have n numbers (separated by space) to represent direct distance from that node to all other nodes.
    Distance from node to itself is 0 and -1 if there is no direct edge to any node.
    Last line would contain node number of the source whose shortest distance from each other node need to be calculated.

Output format:
    Output is n lines containing 3 information per line (separated by space):
    Destination node, Shortest Distance to that node and path from source to that node.

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

typedef struct Edge 
{
    Node* dest;
    int weight;
}Edge;

struct Node {
    int data;
    Edge** adj_list;
    Node *parent;
    int connected_vertices;
    int weight;
    int is_visited;
};
Node** vertices;

int N;

Edge* createEdge(Node* Dest,int weight){

    Edge* new_Edge = (Edge*)malloc(sizeof(Edge));
    new_Edge->dest = Dest;
    new_Edge->weight = weight;

    
    return new_Edge;
}

void addEdge(Node* src,int weight,Node* Dest){
    
        Edge* new_Edge = createEdge(Dest,weight);
        src->adj_list[src->connected_vertices++] = new_Edge;
}

Node* FindSmallest()
{
    Node* min = vertices[0];
    int i=0;
    while(min->weight == -1 || min->is_visited == 1)
    {
        i++;
        if(i == N)
        {
            return NULL;
        }
        min = vertices[i];
    }

    for(;i<N;i++)
    {
        if(vertices[i]->weight > 0 && vertices[i]->is_visited == 0 &&  min->weight > vertices[i]->weight)
            min = vertices[i];
    }

    return min;
}

void Dijks(Node* start){

    Edge** adj = start->adj_list;
    start->is_visited = 1;
    for(int i=0;i<start->connected_vertices;i++)
    {
        if(adj[i]->dest->weight == -1 || start->weight + adj[i]->weight <  adj[i]->dest->weight)
        {
            adj[i]->dest->parent = start;
            adj[i]->dest->weight = start->weight + adj[i]->weight;
        }
    }

    Node* small = FindSmallest(start);
    if(small == NULL)
    {
        return;
    }

    Dijks(small);
}

void printPath(Node* end)
{

    if(end== NULL || end->parent == NULL)
        return;

    printPath(end->parent);

    printf("->%d",end->data);

}

int main()
{
    int w;
    
    scanf("%d",&N);
    vertices =(Node**) malloc(sizeof(Node*)*N);
    for(int i=0;i<N;i++)
    {
        vertices[i] = (Node*)malloc(sizeof(Node));
        vertices[i]->data = i+1;
        vertices[i]->adj_list =(Edge**)malloc(sizeof(Edge*)*N);
        vertices[i]->parent = NULL;
        vertices[i]->connected_vertices = 0;
        vertices[i]->weight = -1;
        vertices[i]->is_visited = 0;
    }

    for(int i=1;i<=N;i++)
    {
        
        for(int j=1;j<=N;j++)
        {
            scanf("%d",&w);

            if(j == i && w != 0)
            {
                printf("Weight of the edge %d <-> %d must be 0",i,j);
                exit(0);
            }

            else if(j !=i &&w == 0)
            {
                printf("Weight of the edge %d <-> %d can not be 0",i,j);
                exit(0);
            }
            if(w < -1)
            {
                printf("Weight of the edge %d <-> %d can not be negative",i,j);
                exit(0);
            }
            else if(w != -1 &&  w != 0)
            {
                addEdge(vertices[i-1],w,vertices[j-1]);
            }
        }
    }
    int start;
    scanf("%d",&start);

    vertices[start-1]->weight = 0;
    Dijks(vertices[start-1]);

    for(int i=0;i<N;i++)
    {
        printf("%d\t%d\t%d",i+1,vertices[i]->weight,start);
        printPath(vertices[i]);
        printf("\n");
    }

}