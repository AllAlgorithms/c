#include<stdio.h>
#define MAX 2
int m =2;
int n =2;
int p =2;
void MatrixMutiply(int m,int n,int p,int matrix1[MAX][MAX],
int matrix2[MAX][MAX],int matrixResult[MAX][MAX])
{
int  sum;
for(int i=0;i<m;i++)
  for(int j=0;j<p;j++)
  {
   sum=0;
   for(int k=0;k<n;k++)
    sum+=matrix1[i][k]*matrix2[k][j];
   matrixResult[i][j]=sum;
  }
}
int main()
{
int matrix1[MAX][MAX] ={0};
int matrix2[MAX][MAX] = {0};
int matrixResult[MAX][MAX] = {0};
int temp=0;
int m =2;
int n =2;
int p =2;
printf("\nPlease elements of Matrix1(%d*%d):\n",m,n);
for(int i=0;i<m;i++)
  for(int j=0;j<n;j++)
  {
   scanf("%d",&temp);
   matrix1[i][j]=temp;
  }

printf("\nPlease elements of Matrix2(%d*%d):\n",n,p);
for(int i=0;i<n;i++)
  for(int j=0;j<p;j++)
  {
   scanf("%d",&temp);
   matrix2[i][j]=temp;
  }

MatrixMutiply(m,n,p,matrix1,matrix2,matrixResult);

printf("\nResult matrix: \n");
for(int i=0;i<m;i++)
{
  for(int j=0;j<p;j++)
   printf("%d ",matrixResult[i][j]);
  printf("\n");
}
 return 0;
}
