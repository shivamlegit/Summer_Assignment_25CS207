#include <stdio.h>
int sum(int a,int b) 
{
    return a+b;
}
int main()
{
    int n1,n2;
    printf("Input first number= ");
    scanf("%d",&n1);
    
    printf("Input second number= ");
    scanf("%d",&n2);
    int result=sum(n1,n2);
    printf("Sum of %d and %d is: %d\n",n1,n2,result);
    
    return 0;
}