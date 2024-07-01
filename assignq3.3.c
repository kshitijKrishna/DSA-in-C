#include <stdio.h>

void add_polynomials(int poly1[], int degree1, int poly2[], int degree2, int result[]) {
    int max_degree = degree1 > degree2 ? degree1 : degree2;

    for (int i = 0; i <= max_degree; i++) {
        result[i] = 0;
        if (i <= degree1) {
            result[i] += poly1[i];
        }
        if (i <= degree2) {
            result[i] += poly2[i];
        }
    }
}

int main() {
    int degree1, degree2;

    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);
    int poly1[degree1 + 1];

    for (int i = degree1; i >= 0; i--) {
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d", &poly1[i]);
    }

    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &degree2);
    int poly2[degree2 + 1];

    for (int i = degree2; i >= 0; i--) {
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d", &poly2[i]);
    }

    int max_degree = degree1 > degree2 ? degree1 : degree2;
    int result[max_degree + 1];

    add_polynomials(poly1, degree1, poly2, degree2, result);

    printf("Resultant polynomial after addition:\n");
    for (int i = max_degree; i >= 0; i--) {
        printf("%dx^%d ", result[i], i);
        if (i != 0) {
            printf("+ ");
        }
    }
    printf("\n");

    return 0;
}
