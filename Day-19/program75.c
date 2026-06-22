#include<stdio.h>

int main()
{
    int r,c;
    int a[100][100], transpose[100][100];
    printf("Input rows and columns=  ");
    scanf("%d %d",&r,&c);
    printf("\nEnter matrix elements:\n");
    for (int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            printf("Input element a%d%d: ",i+1,j+1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) 
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    for (int i=0;i<r;i++) {
        for (int j = 0; j < c; j++) {
            transpose[j][i] = a[i][j];
        }
    }
    printf("\nTranspose of the matrix==  \n");
    for (int i = 0; i < c; i++)
     {
         for (int j = 0; j < r; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}