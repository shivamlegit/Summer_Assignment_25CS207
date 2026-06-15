#include<stdio.h>
int main()
 {
    int n;
    printf("Input the size of the array= ");
    scanf("%d",&n);
    if(n<=0)
     {
        printf("Array size must be a positive integer.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ",i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nThe elements in the array are: ");
    for (int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}
