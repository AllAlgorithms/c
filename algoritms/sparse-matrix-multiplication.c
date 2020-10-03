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

struct sparse transpose(struct sparse a) {

	struct sparse res;
	int b[a.num_cols], t[a.num_cols];
	res.num_rows = a.num_cols;
	res.num_cols = a.num_rows;
	res.num_non_zero = a.num_non_zero;

	for (int i = 0; i < a.num_cols; i++)
		b[i] = 0;

	for (int i = 0; i < a.num_non_zero; i++)
		b[a.col[i]]++;

	t[0] = 0;

	for (int i = 1; i < a.num_cols; i++)
		t[i] = t[i - 1] + b[i - 1];

	for (int i = 0; i < a.num_non_zero; i++) {
		res.row[t[a.col[i]]] = a.col[i];
		res.col[t[a.col[i]]] = a.row[i];
		res.val[t[a.col[i]]] = a.val[i];
		t[a.col[i]]++;
	}

	return res;
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

struct sparse multiplyMatrix(struct sparse a, struct sparse b) {

	// transpose b to compare row and column values and add them in the end
	b = transpose(b);

	struct sparse prod_mat;
	prod_mat.num_rows = a.num_rows;
	prod_mat.num_cols = b.num_cols;

	int k = 0;

	for (int i = 0; i < a.num_non_zero;) {
		int r = a.row[i];

		for (int j = 0; j < b.num_non_zero;) {
			int c = b.row[j], x = i, y = j, sum = 0;

			while (x < a.num_non_zero && a.row[x] == r &&
			        y < b.num_non_zero && b.row[y] == c) {

				if (a.col[x] == b.col[y]) {
					sum += a.val[x] * b.val[y];
					x++;
					y++;
				}
				else if (a.col[x] < b.col[y])
					x++;
				else
					y++;
			}

			if (sum != 0) {
				prod_mat.row[k] = r;
				prod_mat.col[k] = c;
				prod_mat.val[k] = sum;
				k++;
			}

			while (j < b.num_non_zero && b.row[j] == c)
				j++;
		}

		while (i < a.num_non_zero && a.row[i] == r)
			i++;
	}

	return prod_mat;
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
	if (a.num_cols == b.num_rows) {
		struct sparse c = multiplyMatrix(a, b);
		printf("\nPRODUCT MATRIX:\n");
		printMatrix(c);
	}
	else
		printf("\nERROR: CAN'T MULIPLY MATRICES, INVALID DIMENSIONS\n");

	return 0;
}