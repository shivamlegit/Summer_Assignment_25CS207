#include<stdio.h>

int main() {
    int m,n,o,p;
    int a[100][100],b[100][100],result[100][100];
    printf("Enter rows and columns for first matrix===  ");
    scanf("%d %d",&m,&n);
    printf("Enter rows and columns for second matrix== ");
    scanf("%d %d", &o, &p);
    if (n!=o)
    {
        printf("OOps! Matrix multiplication is not possible.\n");
        printf("Columns of first matrix must equal rows of second matrix.\n");
        return 1;
    }
    printf("\nEnter elements of first matrix:\n");
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            printf("Input element a%d%d= ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nEnter elements of second matrix:\n");
    for (int i=0;i<o;i++) {
         for (int j = 0; j < p; j++) {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<p;j++)
         {
            for(int k=0;k<n;k++)
             {
                result[i][j] +=a[i][k]*b[k][j];
            }
        }
    }
    printf("\nFirst Matrix:\n");
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\nSecond Matrix:\n");
    for (int i = 0; i < o; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("\nProduct of the matrices (A × B)==\n");
    for (int i=0;i<m;i++) {
        for (int j=0;j<p;j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}