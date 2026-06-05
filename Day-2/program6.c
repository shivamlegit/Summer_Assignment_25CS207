#include<stdio.h>

int main()
 {
    int n,digit,reverse=0;

    printf("Enter a number n= ");
    scanf("%d",&n);

    while(n!=0) 
    {
        digit=n%10;           // To get last digit
        reverse = reverse*10+digit;
        n = n/10;             // To remove last digit
    }

    printf("Reversed of number n is=%d\n",reverse);

    return 0;
}