#include<stdio.h>
int main()
{
    int n,sum=0;
    printf("Input a number to check weather it is perfect or not= ");
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        if(n%i==0)
        {
            sum=sum+i;
        }
    }
    if(sum==n)
    {
        printf(" provided number=%d :is a perfect number\n",n);
    } else
    {
        printf("provided number=%d :is not a perfect number\n",n);
    }

    return 0;
}