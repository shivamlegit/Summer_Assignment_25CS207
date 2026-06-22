#include<stdio.h>

int main() 
{
    int r1, c1, r2, c2;
    int a[100][100],b[100][100],sum[100][100];
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for second matrix= ");
    scanf("%d %d", &r2, &c2);
    if (r1 != r2 || c1 != c2) {
        printf("Error! Matrices cannot be added. Rows and columns must match.\n");
        return 1;
    }

    printf("Enter elements of first matrix= \n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter elements of second matrix= \n");
    for (int i=0;i<2;i++)
     {
        for (int j=0;j<c2;j++)
         {
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 0; i < r1; i++)
     {
        for (int j = 0; j < c1; j++) 
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("Sum of the matrices= \n");
    for(int i=0;i<r1;i++) 
    {
        for(int j=0;j<c1;j++) 
        {
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }
return 0;
}