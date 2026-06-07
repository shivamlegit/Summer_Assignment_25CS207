#include<stdio.h>
long long int fibonacci(int n) 
{
    if(n<=1) {
        return n;
    }
    long long int a=0; 
    long long int b=1; 
    long long int nextTerm;
    
    for(int i=2;i<=n;i++)
     {
        nextTerm=a+b;
        a=b;            
        b=nextTerm;   
    }
    
    return b;
}
int main() {
    int n;
    
    printf("provide the positive number n for fibonacci term=");
    scanf("%d", &n);
    
    if(n<0)
     {
        printf("Please type a positive integer\n");
    } else
    {
        printf("fibonacci series term at position %d is= %lld\n", n, fibonacci(n));
    }
    return 0;
}