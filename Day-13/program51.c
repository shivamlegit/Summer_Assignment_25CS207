#include<stdio.h>
#include<limits.h>

int main(void) {
    int n;
    if (printf("Input number of elements: "), scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int num;
    int largest = INT_MIN; 
    int smallest = INT_MAX; 
    for (int i = 0; i < n; ++i) {
        printf("Enter element %d: ", i + 1);
        if (scanf("%d", &num) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        if (num > largest)
         {
            largest = num;
        }
        if (num<smallest) {
            smallest=num;
        }
    }
    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);

    return 0;
}
