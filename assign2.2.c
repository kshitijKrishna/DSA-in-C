#include<stdio.h>
void upper(int matrix[4][4], int row, int col)
{
    int i, j;      
    for (i = 0; i < row; i++)
   {
     for (j = 0; j < col; j++)
   {
     if (i > j)
    { 
    printf(" 0 ");
    }
    else
    printf("%d\t",matrix[i][j]);
   }
   
   printf("\n");
 }
} 
int main()
{
int matrix[4][4] = {8, 2, 1, 0,1, 0, 7, 6,0, 6, 2, 4, 3, 9, 5, 0};
int row = 4, col = 4;      
printf("Upper triangular matrix: \n");
upper(matrix, row, col);      
return 0;
}
