//
// Sparse Matrix Sum illustration
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

void sum(int tupleA[][3], int tupleB[][3], int tupleC[][3]) {
	
	tupleC[0][0] = tupleA[0][0];
	tupleC[0][1] = tupleA[0][1]; 
	
	int l = 0;
	int t1 = 1, t2 = 1;

	while(t1 <= tupleA[0][2] && t2 <= tupleB[0][2]) {

		if(tupleA[t1][0] < tupleB[t2][0]) {

			tupleC[++l][0] = tupleA[t1][0];
			tupleC[l][1] = tupleA[t1][1];
			tupleC[l][2] = tupleA[t1++][2];

		} else	if(tupleB[t2][0] < tupleA[t1][0]) {

			tupleC[++l][0] = tupleB[t2][0];
			tupleC[l][1] = tupleB[t2][1];
			tupleC[l][2] = tupleB[t2++][2];

		} else {
			if(tupleA[t1][1] < tupleB[t2][1]) {

				tupleC[++l][0] = tupleA[t1][0];
				tupleC[l][1] = tupleA[t1][1];
				tupleC[l][2] = tupleA[t1++][2];

			} else if(tupleB[t2][1] < tupleA[t1][1]) {

				tupleC[++l][0] = tupleB[t2][0];
				tupleC[l][1] = tupleB[t2][1];
				tupleC[l][2] = tupleB[t2++][2];

			}
			else {
				tupleC[++l][0] = tupleA[t1][0];
				tupleC[l][1] = tupleA[t1][1];
				tupleC[l][2] = tupleA[t1++][2] + tupleB[t2++][2];
			}
		}
	}
	
	while(t2 <= tupleB[0][2]) {
		tupleC[++l][0] = tupleB[t2][0];
		tupleC[l][1] = tupleB[t2][1];
		tupleC[l][2] = tupleB[t2++][2];
	}

	while(t1 <= tupleA[0][2]) {
		tupleC[++l][0] = tupleA[t1][0];
		tupleC[l][1] = tupleA[t1][1];
		tupleC[l][2] = tupleA[t1++][2];
	}
	
	tupleC[0][2] = l;
	
	printf("\n\tSUM:\n");
	for(int i=0; i<=l; i++) {
		printf("(%d, %d, %d)\n", tupleC[i][0], tupleC[i][1], tupleC[i][2]);
	}
	printf("\n");
}

int matrixNum = 0;

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
	printf("\n\tSparse Matrix %d:\n", matrixNum);
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
		printf("\nEnter no of columns: ");
		scanf("%d", &c);
		r_c[0] = r;
		r_c[1] = c;
	}
	else {
		r = r_c[0];
		c = r_c[1];
	}
	matrixNum++;
	printf("\n\t\tMATRIX %d: ", matrixNum);
	int nonzeros = 0;
	printf("\n");
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++)
		{
			printf("\nEnter %d,%d value: ", i+1, j+1);
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("\t\tMATRIX %d: \n[\n", matrixNum);
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
	int matrixB[100][100];
	int tupleB_length = read(matrixB);
	int tupleB[100][3];
	tupleMaker(r_c[0], r_c[1], matrixB, tupleB_length-1, tupleB);
	int tupleC[100][3];
	sum(tupleA, tupleB, tupleC);	
	printf("\nMatrix 1:\n");
	matrixMaker(tupleA);
	printf("\nMatrix 2:\n");
	matrixMaker(tupleB);
	printf("\nSum Matrix:\n");
	matrixMaker(tupleC);
}