#include<stdio.h>
int main()
 {
    int rows,cols;
    int matrix[100][100];
    int i,j;
    int colSum;
    printf("Input number of rows and columns== ");
    scanf("%d %d",&rows,&cols);
   printf("\nEnter elements of the matrix==\n");
    for(i=0;i<rows;i++)
     {
        for(j=0;j<cols;j++)
         {
            printf("Input element matrix[%d][%d]= ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nMatrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nColumn-wise Sum==\n");
    for (j=0;j<cols;j++)
    {
        colSum=0;  
        for (i=0;i<rows;i++)
         {
            colSum = colSum + matrix[i][j]; 
        }
        printf("Sum of column %d = %d\n", j + 1, colSum);
    }

    return 0;
}