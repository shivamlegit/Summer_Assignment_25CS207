#include<stdio.h>
int power(int base,int exp)
{
    int result=1;
    for (int i=0;i<exp;++i)
    {
        result*=base;
    }
    return result;
}

int main()
{
    int n,originalNum,remainder,digits=0,result=0;

    printf("please provide a integer= ");
    scanf("%d",&n);
    originalNum=n;
    while (originalNum!=0)
    {
        originalNum /= 10;
        digits++;
    }
    originalNum=n;
    while (originalNum != 0) {
        remainder=originalNum%10;                 
        result +=power(remainder,digits);       
        originalNum/=10;                         
    }
    if(result==n)
    {
        printf("%d Is an armstrong number\n",n);
    } else 
{
         printf("%d Is not an armstrong number\n",n);
    }

    return 0;
}