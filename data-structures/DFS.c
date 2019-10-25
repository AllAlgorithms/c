#include<stdio.h>
int a[10][10], s[10], n;
void read_AM( int a[10][10], int n)
{
int i,j;
for( i=0; i<n; i++)
{
for (j=0; j<n; j++)
{
scanf("%d", &a[i][j]);
}
}
}
void dfs(int u)
{
int
v;
s[u]=1;
printf("%d",u);
for(v=0; v<n; v++)
{
if(a[u][v]==1 && s[v]==0)
dfs(v);
printf("\t");
}
printf("\n");
}
void main()
{
int i, source;
printf("Enter the number of nodes in the graph:");
scanf("%d",&n);
printf("Enter the adjacency matrix:");
read_AM(a,n);
for(source=0; source<n; source++)
{
for(i=0; i<n; i++)
s[i]=0;
printf("The nodes reachable from %d", source);
dfs(source);
}
}
