#include <stdio.h>

int main() {
    int n;
    int a[100][100];
    int sum = 0;
    printf("Enter size of square matrix===");
    scanf("%d", &n);
    printf("\nEnter elements of matrix:\n");
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            printf("Input element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    for (int i=0;i<n;i++) {
        sum=sum+a[i][i];
    }
    printf("\nMatrix:\n");
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\nSum of main diagonal elements = %d\n", sum);

    return 0;
}