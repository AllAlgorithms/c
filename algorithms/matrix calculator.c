#include<stdio.h>

void read_and_display()
{
	int i,j,row,col,p;
	printf("input the number of rows : ");
	scanf("%d",&row);
	printf("input the number of columns : ");
	scanf("%d",&col);
	p=col*row;
	int matrix[row][col];
	printf("input the %d elements of matrix row wise : ",p);
	for(i=0;i<row;i++)
	{
	for(j=0;j<col;j++)
	{
		scanf("%d",&matrix[i][j]);
	}
	}
	printf("\nThe entered matrix is:\n");
	for(i=0;i<row;i++)
	{
		printf("\n");
	for(j=0;j<col;j++)
	{
		printf("%d \t",matrix[i][j]);
		
	}
	}
}

void sum()
{
		int i,j,row,col,p;
	printf("input the number of rows of two matrix : ");
	scanf("%d",&row);
	printf("input the number of columns of two matrix : ");
	scanf("%d",&col);
	p=col*row;
	int matrix_one[row][col],matrix_two[row][col],matrix_sum[row][col];
	printf("input the %d elements of first matrix row wise : ",p);
	for(i=0;i<row;i++)
	{
	for(j=0;j<col;j++)
	{
		scanf("%d",&matrix_one[i][j]);
	}
	}
	printf("input the %d elements of second matrix row wise : ",p);
	for(i=0;i<row;i++)
	{
	for(j=0;j<col;j++)
	{
		scanf("%d",&matrix_two[i][j]);
	}
	}
	for(i=0;i<row;i++)
	{
	for(j=0;j<col;j++)
	{
	 matrix_sum[i][j]=matrix_one[i][j]+matrix_two[i][j];
	}
	}
			for(i=0;i<row;i++)
	{
		printf("\n");
	for(j=0;j<col;j++)
	{
		printf("%d \t",matrix_sum[i][j]);
		
	}
	}
}

void product()
{
		int i,j,row1,col1,row2,col2,p1,p2,k;
	printf("input the number of rows of first matrix : ");
	scanf("%d",&row1);
	printf("input the number of columns of first matrix : ");
	scanf("%d",&col1);
	printf("input the number of rows of second matrix : ");
	scanf("%d",&row2);
	printf("input the number of columns of second matrix : ");
	scanf("%d",&col2);
	p1=row1*col1;
	p2=row2*col2;
	if(col1==row2)
	{
	int matrix_one[row1][col1],matrix_two[row2][col2],matrix_product[row1][col2];
	printf("input the %d elements of first matrix row wise : ",p1);
	for(i=0;i<row1;i++)
	{
	for(j=0;j<col1;j++)
	{
		scanf("%d",&matrix_one[i][j]);
	}
	}
	printf("input the %d elements of second matrix row wise : ",p2);
	for(i=0;i<row2;i++)
	{
	for(j=0;j<col2;j++)
	{
		scanf("%d",&matrix_two[i][j]);
	}
	}
	for(i=0;i<row1;i++)
	{
	for(j=0;j<col2;j++)
	{
	 matrix_product[i][j]=0;    
     for(k=0;k<col1;k++)    
	{    
	matrix_product[i][j]+=matrix_one[i][k]*matrix_two[k][j];    
	}
	}
	}
		for(i=0;i<row1;i++)
	{
		printf("\n");
	for(j=0;j<col2;j++)
	{
		printf("%d \t",matrix_product[i][j]);
		
	}
	}
	}
	else
	printf("enter valid matrix");
}

void transpose()
{
		int i,j,row,col,p;
	printf("input the number of rows : ");
	scanf("%d",&row);
	printf("input the number of columns : ");
	scanf("%d",&col);
	p=col*row;
	int matrix[row][col],transpose[col][row];
	printf("input the %d elements of matrix row wise : ",p);
	for(i=1;i<=row;i++)
	{
	for(j=1;j<=col;j++)
	{
		scanf("%d",&matrix[i][j]);
	}
	}
		for(i=1;i<=col;i++)
	{
	for(j=1;j<=row;j++)
	{
	 transpose[i][j]=matrix[j][i];
	}
	}
	printf(" \n transpose of given matrix:  ");
	for(i=1;i<=col;i++)
	{
		printf("\n");
	for(j=1;j<=row;j++)
	{
		printf("%d \t",transpose[i][j]);
		
	}
	}
	
}

void main()
{
	int n;
	printf("OPERATION MENU:");
	printf("\n");
	printf("1. Read and display");
	printf("\n2. Sum of two matrix");
	printf("\n3. Product of two matrix");
	printf("\n4. Transpose of a matrix");
	printf("\n \n Enter an option :");
	scanf("%d",&n);
	switch(n)
		{
			case 1:
				read_and_display();
				break;
			case 2:
				sum();
				break;
			case 3:
				product();
				break;
			case 4:
				transpose();
				break;
			default:
				printf("Enter a valid option");
				break;
		}
}
