#include <stdio.h>

int main(void)
{
    int n;
    printf("input number of elements= ");
    if (scanf("%d",&n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int num;
    int even_count = 0;
    int odd_count = 0;
    for (int i = 0; i < n; ++i) {
        printf("Input element %d= ",i+1);
        if (scanf("%d", &num) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        if (num % 2 == 0) 
        {
            even_count++;
        } else {
            odd_count++;
        }
    }
    printf("Even elements: %d\n", even_count);
    printf("Odd elements: %d\n", odd_count);

    return 0;
}
