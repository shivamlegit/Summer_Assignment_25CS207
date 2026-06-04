#include<stdio.h>
int main()
{
    int sum=0,i,n;
    printf("Provide input the natural number n=");
    scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
        
        sum= sum +i;
        }

        printf("sum of the n natural numbers=%d\n",sum);
        return 0;
}