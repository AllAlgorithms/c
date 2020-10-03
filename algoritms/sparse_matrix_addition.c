#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

struct sparse {
	int num_rows, num_cols, num_non_zero;
	int row[MAXSIZE], col[MAXSIZE], val[MAXSIZE];
};

struct sparse addMatrix(struct sparse a, struct sparse b) {

	struct sparse sum_mat;
	sum_mat.num_rows = a.num_rows;
	sum_mat.num_cols = a.num_cols;
	int i = 0, j = 0, k = 0;

	while (i < a.num_non_zero && j < b.num_non_zero) {

		if (a.row[i] < b.row[j] || (a.row[i] == b.row[j] && a.col[i] < b.col[j])) {
			sum_mat.row[k] = a.row[i];
			sum_mat.col[k] = a.col[i];
			sum_mat.val[k] = a.val[i];
			i++;
		}
		else if (a.row[i] > b.row[j] || (a.row[i] == b.row[j] && a.col[i] > b.col[j])) {
			sum_mat.row[k] = b.row[j];
			sum_mat.col[k] = b.col[j];
			sum_mat.val[k] = b.val[j];
			j++;
		}
		else {
			sum_mat.row[k] = a.row[i];
			sum_mat.col[k] = a.col[i];
			sum_mat.val[k] = a.val[i] + b.val[j];
			i++;
			j++;
		}

		k++;
	}

	while (i < a.num_non_zero) {
		sum_mat.row[k] = a.row[i];
		sum_mat.col[k] = a.col[i];
		sum_mat.val[k] = a.val[i];
		i++;
		k++;
	}

	while (j < b.num_non_zero) {
		sum_mat.row[k] = b.row[j];
		sum_mat.col[k] = b.col[j];
		sum_mat.val[k] = b.val[j];
		j++;
		k++;
	}

	sum_mat.num_non_zero = k;

	return sum_mat;
}

void readMatrix(struct sparse *s) {

	printf("Enter matrix dimensions:\n");
	scanf("%d%d", &s->num_rows, &s->num_cols);

	printf("Enter the number of non-zero elements:\n");
	scanf("%d", &s->num_non_zero);

	printf("Enter row number, column number and value of each element:\n");
	for (int i = 0; i < s->num_non_zero; i++)
		scanf("%d %d %d", &s->row[i], &s->col[i], &s->val[i]);
}

void printMatrix(struct sparse s) {

	int k = 0;
	for (int i = 0; i < s.num_rows; i++) {
		for (int j = 0; j < s.num_cols; j++) {
			if (i == s.row[k] && j == s.col[k])
				printf("%d\t", s.val[k++]);
			else
				printf("0\t");
		}
		printf("\n");
	}
}

int main() {

	struct sparse a, b;
	printf("READING MATRIX A\n");
	readMatrix(&a);
	printf("READING MATRIX B\n");
	readMatrix(&b);
	printf("MATRIX A:\n");
	printMatrix(a);
	printf("MATRIX B:\n");
	printMatrix(b);
	if (a.num_rows == b.num_rows && a.num_cols == b.num_cols) {
		struct sparse add = addMatrix(a, b);
		printf("\nADDITION OF MATRICES:\n");
		printMatrix(add);
	}
	else
		printf("\nERROR: CAN'T ADD MATRICES BECAUSE OF DIFFERENT DIMENSIONS\n");

	return 0;
}