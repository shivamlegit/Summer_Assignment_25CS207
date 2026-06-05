#include<stdio.h>

int main() {
    int n,digit,sum=0;

    printf("provide a input n whose sum is to find = ");
    scanf("%d",&n);

    while (n != 0) {
        digit =n%10;   // To find last digit
        sum +=digit;       // Add digit to sum
        n/=10;          // TO remove last digit
    }

    printf("sum of the digits will be = %d\n",sum);

    return 0;
}