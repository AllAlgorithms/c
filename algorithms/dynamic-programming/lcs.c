#include<stdio.h>
#include<string.h>
char x[100000],y[100000],b[1000][1000];
int i,j,m,n,a,c[1000][1000];
void lcs_length()
{
	m=strlen(x);
	printf("For String %s  X is length %d\n",x,m);

	n=strlen(y);
	printf("For String %s Y is Length %d\n",y,n);
	for(i=0;i<=m;i++)
		c[i][0]=0;
	for(j=0;j<=n;j++)
		c[0][j]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]='c';
			}
			else
			{
				if(c[i-1][j]>=c[i][j-1])
				{
					c[i][j]=c[i-1][j];
					b[i][j]='u';
				}
				else
				{
					c[i][j]=c[i][j-1];
					b[i][j]='i';
				}
			}			
		}
	}
	printf("The size of Longest Common Subsequence is : %d\n", c[m][n]);
	printf("The Longest Common Subsequence is: ");
	print_lcs(m,n);
}
void print_lcs(int i,int j)
{
	if(i==0 || j==0)
		return ;
	if(b[i][j]=='c')
	{
		print_lcs(i-1,j-1);
		printf("%c",x[i-1]);
	}
	else if(b[i][j]=='u')
	{
		print_lcs(i-1,j);
	}
	else
	{
		print_lcs(i,j-1);
	}
}

int main()
{
	printf("\n Enter 1st Sequence ");
	gets(x);
	printf("\nEnter the 2nd Sequence");
	gets(y);
	printf("\n Longest Common Subsequence is:\n");
	lcs_length();
}