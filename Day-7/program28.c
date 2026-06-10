#include<stdio.h>

int m(int n, int rev)        //m is reverse number
{
    if (n==0)
        return rev;
    return m(n/10, rev*10+n%10);
}

int main()
{
    int n;

    printf("Input a number= ");
    scanf("%d",&n);

    if(n<0)
    {
        printf("Reverse of %d is -%d\n", n, m(-n, 0));
    } else {
        printf("Reverse of %d is %d\n", n, m(n, 0));
    }

    return 0;
}