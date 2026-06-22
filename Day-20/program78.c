#include<stdio.h>

int main() {
    int n;
    int matrix[100][100];
    int i,j;
    int isSymmetric = 1; 
    printf("Enter the dimension of the square matrix (n x n)= ");
    scanf("%d", &n);
    printf("\nEnter elements of the matrix=\n");
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
         {
            printf("Enter element matrix[%d][%d]== ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            if (matrix[i][j]!=matrix[j][i]) {
                isSymmetric = 0; 
                break;
            }
        }
        if (isSymmetric == 0) {
            break;
        }
    }
    printf("\nMatrix:\n");
    for(i=0;i<n;i++) 
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    if (isSymmetric)
     {
        printf("The matrix is symmetric.\n");
    }else{
        printf("The matrix is not symmetric.\n");
    }
    return 0;
}