#include<stdio.h>

long long factorial(int n) {
    if (n==0||n==1)
    {
        return 1;
    }
    return n * factorial(n-1);
}

int main()
{
    int n;

    printf("Input a number= ");
    scanf("%d",&n);

    if(n<0)
    {
        printf("factorial does not exist for negative numbers.\n");
    } else
    {
        printf("factorial of %d = %lld\n", n, factorial(n));
    }
     return 0;
}