#include<stdio.h>
int main() 
{
    int rows,cols;
    int matrix[100][100];
    int i,j;
    int rowSum;
    printf("Input number of rows and columns= ");
    scanf("%d %d",&rows,&cols);
    printf("\nEnter elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Input element matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nMatrix:\n");
    for (i = 0; i < rows; i++)
     {
        for (j=0;j<cols;j++)
         {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nRow-wise Sum:\n");
    for (i = 0; i < rows; i++) {
        rowSum = 0; 
        for (j=0;j<cols;j++) {
            rowSum=rowSum+matrix[i][j];  
               }
        printf("Sum of row %d = %d\n", i + 1, rowSum);
    }

    return 0;
}