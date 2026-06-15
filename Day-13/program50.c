#include<stdio.h>

int main() {
    int n;
    int sum = 0;
    float average;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Array size must be a positive integer.\n");
        return 1;
    }

    int arr[n]; 
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i]; 
    }
    average=(float)sum/n;
    printf("\n-Results-\n");
    printf("Sum of array elements=%d\n",sum);
    printf("Average of array elements=%.2f\n",average);

    return 0;
}
