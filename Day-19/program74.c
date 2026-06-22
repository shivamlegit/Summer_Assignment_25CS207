#include<stdio.h>
int main() 
{
    int r1, c1, r2, c2;
    int a[100][100],b[100][100],diff[100][100];
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for second matrix= ");
    scanf("%d %d",&r2,&c2);
    if (r1 != r2 || c1 != c2) {
        printf("Oops! Matrices cannot be subtracted. Rows and columns must match.\n");
        return 1;
    }
    printf("Input elements of first matrix=\n");
    for (int i=0;i<r1;i++)
     {
        for(int j=0;j<c1;j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter elements of second matrix= \n");
    for (int i=0;i<r2;i++)
     {
        for (int j=0;j<c2;j++)
         {
            scanf("%d", &b[i][j]);
        }
    }

    for(int i=0;i<r1;i++)
     {
        for (int j=0;j<c1;j++) {
            diff[i][j]=a[i][j]-b[i][j];
        }
    }
    printf("Difference of the matrices (A - B)============= \n");
    for (int i=0;i<r1;i++) {
        for (int j=0;j<c1;j++) {
            printf("%d ",diff[i][j]);
        }
        printf("\n");
    }

    return 0;
}