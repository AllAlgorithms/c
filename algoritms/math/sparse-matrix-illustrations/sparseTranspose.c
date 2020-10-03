//
// Sparse Matrix Transpose illustration
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/
// https://github.com/allalgorithms/cpp
//
// Contributed by: Nikhil George Mathew
// Github: @Nikcodes10
//

#include<cstdio>

void transpose(int A[][3], int B[][3]) {

	B[0][0] = A[0][1];
	B[0][1] = A[0][0];
	B[0][2] = A[0][2];
	int z = 1;
	for(int i = 1; i <= A[0][1]; i++) {
		for(int j=1; j <= A[0][2]; j++) {

			while(i == A[j][1] && j<=B[0][2]) {
				B[z][0] = i;
				B[z][1] = A[j][0];
				B[z][2] = A[j][2];
				z++;
				j++;
			}
		}
	}
	printf("\n\tTranspose Sparse Matrix:\n");
	for(int i=0; i<=B[0][2]; i++) {
		printf("(%d, %d, %d)\n", B[i][0], B[i][1], B[i][2]);
	}
	printf("\n");
}

void matrixMaker(int tuple[][3]) {
	printf("[\n");
	for(int i=1; i<=tuple[0][0]; i++) {
		for(int j=1; j<=tuple[0][1]; j++) {
			int k = 1;
			while(k <= tuple[0][2]) {
				if(tuple[k][0] == i && tuple[k][1] == j) {
					printf("%d ", tuple[k][2]);
					k = -1;
					break;
				}
				k++;
			}
			if(k!=-1) {
				printf("%d ", 0);
			}
		}
		printf("\n");
	}
	printf("]\n\n");
}

void tupleMaker(int r, int c, int matrix[][100], int nonzeros, int tuple[][3]) {
	tuple[0][0] = r;
	tuple[0][1] = c;
	
	int trow = 0;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(matrix[i][j] != 0) {
				trow++;
				tuple[trow][0] = i+1;
				tuple[trow][1] = j+1;
				tuple[trow][2] = matrix[i][j];
			}

		}
	}
	tuple[0][2] = nonzeros;
	printf("\n\tSparse Matrix:\n");
	for(int i=0; i<=nonzeros; i++) {
		printf("(%d, %d, %d)\n", tuple[i][0], tuple[i][1], tuple[i][2]);
	}
	printf("\n");
}

int r_c[2] = {-1, -1};

int read(int matrix[][100]) {
	int r, c;
	if(r_c[0] == -1) {
		printf("\nEnter no of rows: ");
		scanf("%d", &r);
		printf("Enter no of columns: ");
		scanf("%d", &c);
		r_c[0] = r;
		r_c[1] = c;
	}
	else {
		r = r_c[0];
		c = r_c[1];
	}
	printf("\n\t\tMATRIX:\n");
	int nonzeros = 0;

	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++)
		{
			printf("\nEnter %d,%d value: ", i+1, j+1);
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("\t\tMATRIX:\n[\n");
	for(int i=0; i<r; i++) {
		for (int j = 0; j < c; j++)
		{
			printf("%d ", matrix[i][j]);
			if(matrix[i][j] != 0) {
				nonzeros++;
			}
		}
		printf("\n");
	}
	printf("]\n");
	return nonzeros+1;
}

void main() {
	int matrixA[100][100];
	int tupleA_length = read(matrixA);
	int tupleA[100][3];
	tupleMaker(r_c[0], r_c[1], matrixA, tupleA_length-1, tupleA);
	int tupleTranspose[100][3];
	transpose(tupleA, tupleTranspose);
	printf("\tTranspose Matrix:\n");
	matrixMaker(tupleTranspose);
}