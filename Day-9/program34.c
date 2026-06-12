#include<stdio.h>

int main(void) {
    int rows=5;
    int i=rows;
    while(i>=1)
    {
        int j=1;
        while(j<=i)
        {
            printf("%d",j);
            ++j;
        }
        printf("\n");
        --i;
    }
    return 0;
}