#include <stdio.h>

typedef struct {
    int row;
    int col;
    int value;
} SparseMatrixEntry;

void addSparseMatrices(SparseMatrixEntry mat1[], int size1, SparseMatrixEntry mat2[], int size2, SparseMatrixEntry result[], int *resultSize) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (mat1[i].row < mat2[j].row || (mat1[i].row == mat2[j].row && mat1[i].col < mat2[j].col)) {
            result[k] = mat1[i];
            i++;
        } else if (mat1[i].row > mat2[j].row || (mat1[i].row == mat2[j].row && mat1[i].col > mat2[j].col)) {
            result[k] = mat2[j];
            j++;
        } else {
            result[k] = mat1[i];
            result[k].value += mat2[j].value;
            i++;
            j++;
        }
        k++;
    }

    while (i < size1) {
        result[k] = mat1[i];
        i++;
        k++;
    }

    while (j < size2) {
        result[k] = mat2[j];
        j++;
        k++;
    }

    *resultSize = k;
}

int main() {
    SparseMatrixEntry matrix1[] = {
        {0, 3, 30},
        {1, 1, 10},
        {2, 3, 40},
        {3, 4, 21}
    };
    int size1 = sizeof(matrix1) / sizeof(matrix1[0]);

    SparseMatrixEntry matrix2[] = {
        {0, 2, 65},
        {1, 1, 12},
        {2, 3, 45},
        {3, 3, 71}
    };
    int size2 = sizeof(matrix2) / sizeof(matrix2[0]);

    SparseMatrixEntry result[size1 + size2];
    int resultSize;

    addSparseMatrices(matrix1, size1, matrix2, size2, result, &resultSize);

    printf("Resultant matrix:\n");
    for (int i = 0; i < resultSize; i++) {
        printf("(%d, %d, %d)\n", result[i].row, result[i].col, result[i].value);
    }

    return 0;
}
