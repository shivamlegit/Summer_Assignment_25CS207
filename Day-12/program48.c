#include<stdio.h>
int isPerfect(int num) {
    int sum = 0;
    for (int i=1;i<=num/2;i++)
     {
        if (num%i==0)
         {
            sum=sum+i; 
        }
    }
    if(sum==num&&num>0) 
    {
        return 1; 
    } else {
        return 0; 
    }
}

int main() {
    int number;

    printf("Input a positive integer: ");
    scanf("%d",&number);
    if (isPerfect(number)) {
        printf("%d is a perfect number.\n",number);
    } else{
        printf("%d is NOT a perfect number.\n",number);
    }

    return 0;
}
