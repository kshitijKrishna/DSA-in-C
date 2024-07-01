#include <stdio.h>

void compareNumbers(int *a, int *b) 
{
    if (*a > *b) 
    {
        printf("%d is greater than %d\n", *a, *b);
    } 
    else if (*a < *b) 
    {
        printf("%d is less than %d\n", *a, *b);
    } 
    else 
    {
        printf("%d is equal to %d\n", *a, *b);
    }
}

int main() 
{
    int a, b;

    printf("Enter the first number: ");
    scanf("%d", &a);

    printf("Enter the second number: ");
    scanf("%d", &b);

    compareNumbers(&a, &b);

    return 0;
}
