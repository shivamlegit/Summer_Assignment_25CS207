#include<stdio.h>
int factorial(int n)
{
    int fact=1;
    for (int i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    return fact;
}

int main()
{
    int n,temp,sum = 0, digit;
    printf("Enter a number: ");
    scanf("%d", &n);

    temp=n;

    while(temp>0)
    {
        digit=temp%10;
        sum=sum+factorial(digit);
        temp/=10;
    }

    if(sum==n)
    {
          printf("The number: = %d : Is a Strong Number.\n",n);
    } else
    {
        printf("The number: = %d is NOT a Strong Number try something different.\n",n);
    }

    return 0;
}
