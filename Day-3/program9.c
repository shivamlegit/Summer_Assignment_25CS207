#include<stdio.h>

int main()
{
    int n,i,prime=1;

    printf("Provide the input numbar to check weather it is prime or not= ");
    scanf("%d",&n);

    if (n<=1) 
    {
        prime=0;
    } else 
    {
        for (i=2;i<n;i++)
         {
            if (n%i==0)
             {
                prime=0;
                break;
            }
        }
    }

    if(prime)
        printf("%d provided number is a Prime Number", n);
    else
        printf("%d provided number is not a Prime Number", n);

    return 0;
}