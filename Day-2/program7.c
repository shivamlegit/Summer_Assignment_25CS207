#include<stdio.h>

int main() 
{
    int n,product=1,digit;

    printf("Enter a number n= ");
    scanf("%d",&n);


    while(n!= 0)
     {
        digit=n%10;      //TO get last digit
        product=product*digit;
        n =n/10;        // To remove last digit
    }

    printf("Product of digits=%d\n",product);

    return 0;
}