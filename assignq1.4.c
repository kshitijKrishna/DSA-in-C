#include <stdio.h>
typedef struct {
    int real;
    int imaginary;
} Complex;

Complex com_sum(Complex num1, Complex num2) {
    Complex sum;
    sum.real = num1.real + num2.real;
    sum.imaginary = num1.imaginary + num2.imaginary;
    return sum;
}

void com_multiply(Complex num1, Complex num2, Complex *result) {
    result->real = num1.real * num2.real - num1.imaginary * num2.imaginary;
    result->imaginary = num1.real * num2.imaginary + num1.imaginary * num2.real;
}

int main() {
    int select, a1, b1, a2, b2, flag = 1;

    while (flag) {
        printf("Enter the First Complex Number separated by a space: ");
        scanf("%d %d", &a1, &b1);

        printf("Enter the Second Complex Number separated by a space: ");
        scanf("%d %d", &a2, &b2);

        Complex num1 = {a1, b1};
        Complex num2 = {a2, b2};
        Complex result; 

        printf("Menu:\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("Enter your choice: ");
        scanf("%d", &select);

        switch (select) {
            case 1:
                {
                    Complex sum = com_sum(num1, num2);
                    printf("Sum of both complex numbers is %d + %di\n", sum.real, sum.imaginary);
                    break;
                }
            case 2:
                {
                    com_multiply(num1, num2, &result);
                    printf("Product of both complex numbers is %d + %di\n", result.real, result.imaginary);
                    break;
                }
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Enter 1 to compute another number or any other number to exit: ");
        scanf("%d", &flag);
    }

    return 0;
}
