#include <stdio.h>
#include <limits.h>
int min(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    int n,m;             // n-> Number of Vertices, m-> Number of unidirectional Edges
    scanf("%d %d",&n,&m);
    int AdjList[n][n];   // Adjlist-> Adjacency list
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                AdjList[i][j]=(INT_MAX/10);
            }
            else
            {
                AdjList[i][i]=0;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        int u,v,x;
        scanf("%d %d %d",&u,&v,&x);   // edge from u to v (0 based indexing) with edge cost x;
        AdjList[u][v]=x;
    }

    // Floyd-Warshall Algorithm
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                AdjList[i][j]=min((AdjList[i][k]+AdjList[k][j]),AdjList[i][j]);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(AdjList[i][j]!=(INT_MAX/10))
            {
                printf("%d ",AdjList[i][j]);
            }
            else
            {
                printf("-1 ");
            }
        }
        printf("\n");
    }
}
