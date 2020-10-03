#include<stdio.h>
#include<conio.h>
bool isSafe(int board[][10], int row, int col, int n)
{
	for(int i=0;i<col;i++)
	{
		if(board[row][i] == 1)
		{
			return false;
		}
	}
	for(int i=row,j=col;i>=0 && j>=0;i--,j--)
	{
		if(board[i][j] ==1)
		{
			return false;
		}
	}
	for(int i=row,j=col;i<n && j>=0;i++,j--)
	{
		if(board[i][j] ==1)
		{
			return false;
		}
	}
	return true;
}
bool nQueen(int board[][10], int col, int n)
{
	if(col>=n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	for(int i=0;i<n;i++)
	{
		if(isSafe(board,i,col,n))
		{
			board[i][col]=1;
			if(nQueen(board,col+1,n))
			{
				return true;
			}
			board[i][col]=0;
		}
	}
	return false;
}
int main()
{
	int n;
	int board[10][10]={0};
	scanf("%d",&n);
	bool check = nQueen(board,0,n);
	if(check == false)
	printf("-1");
	else
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%d    ",board[i][j]);
			}
		printf("\n");
		}
	}
	getch();
	return 0;
}
