#include<stdio.h>

int main() 
{
    int n,original,reverse=0,digit;

    printf("provide a number to check number is palindron or not.= ");
    scanf("%d",&n);

    original = n;

    while(n!=0)
     {
        digit=n%10;
        reverse=reverse*10+digit;
        n =n/10;
    }

    if(original==reverse)
        printf("provided number is a palindrome number\n");
    else
        printf("provided number is not a palindrome number\n");

    return 0;
}