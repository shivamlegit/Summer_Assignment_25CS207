#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int countDigits(int n) {
    int count=0;
    if (n==0) return 1;
    while(n>0)
     {
        count++;
        n/=10;
    }
    return count;
}
bool isArmstrong(int num) {
    int original = num;
    int sum = 0;
    int digits = countDigits(num);
    while (num) 
    {
        int digit = num % 10;
        sum += pow(digit, digits);
        num /= 10;
    }
    
    return (sum == original);
}

int main() {
    int number;
    
    printf("Input a number: ");
    scanf("%d",&number);
    if (isArmstrong(number)) {
        printf("%d is an Armstrong number\n", number);
    } else {
        printf("%d is not an Armstrong number\n", number);
    }
    printf("\nSome Armstrong numbers: ");
    for (int i=1;i<=10000;i++)
     {
        if (isArmstrong(i))
         {
            printf("%d ",i);
        }
    }
    printf("\n");
    
    return 0;
}