#include<stdio.h>

int main() 
{
    int n;
    unsigned long long fact = 1;

    printf("Input a integer= ");
    scanf("%d",&n);

    if(n< 0)
    {
        printf("Oops! factorial of a negative number doesn't exist.\n");
    } 
    else
    {
        for (int i=1;i<=n;i++)
        {
            fact=fact*i;
        }
        
        printf("Factorial of a number %d = %llu\n",n, fact);
    }

    return 0;
}