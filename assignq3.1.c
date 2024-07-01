#include <stdio.h>

struct sparse {
	int col;
	int row;
	int value;
};

int main(void) {
	int row, column;
	printf("Rows of matrix: ");
	scanf(" %d", &row);
	printf("Columns of matrix: ");
	scanf(" %d", &column);
	int matrix[row][column];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("Row %d, Column %d: ", i, j);
			scanf(" %d", &matrix[i][j]);
		}
	}

	int size = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (matrix[i][j] != 0) size++;
		}
	}

	struct sparse a[size + 1];
	int k = 0;
	a[k].row = row; a[k].col = column;
	a[k].value = size;
	k++;
	for (int i = 0; i < a[0].row; i++) {
		for (int j = 0; j < a[0].col; j++) {
			if (matrix[i][j] != 0) {
				a[k].row = i; a[k].col = j; a[k].value = matrix[i][j];
				k++;
			}
		}
	}

	printf("\n");
	for (int i = 0; i < (size + 1); i++) {
		printf("%d %d %d\n", a[i].row, a[i].col, a[i].value);
	}
    	struct sparse b[size + 1];
	int n = a[0].value;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = n;

	if (n > 0) {
		k = 1;
		for (int i = 0; i < a[0].col; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[j].col == i) {
					b[k].row = a[j].col;
					b[k].col = a[j].row;
					b[k].value = a[j].value;
					k++;
				}
			}
		}
	}

	printf("\n");
	for (int i = 0; i < (size + 1); i++) {
		printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);
	}

	return 0;
}
