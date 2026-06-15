#include<stdio.h>
int factorial(int n) 
{
    if(n<=0) {
        return 1;  
    }
    
    int result=1;
    for (int i=1;i<=n;i++)
     {
        result=result*i;
    }
    
    return result;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    int result=factorial(n);
    printf("Factorial of %d is: %d\n",n,result);
    
    return 0;
}