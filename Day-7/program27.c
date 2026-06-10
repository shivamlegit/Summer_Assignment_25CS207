#include<stdio.h>

int p(int n)       
{  
    if(n==0)
        return 0;
    else
        return (n%10)+p(n / 10);
}

int main()
{
    int n,s;   // s is sum of digits

    printf("Input a number= ");
    scanf("%d",&n);

    if (n<0)
        n =-n;

    s=p(n);

    printf("sum of digits = %d\n",s);

    return 0;
}