#include<stdio.h>
int maximum(int a,int b)
{
    if(a>b)
    {
        return a;
    } else
    {
        return b;
    }
}

int main() {
    int n1,n2;
    printf("Input first numbe= ");
    scanf("%d",&n1);
    printf("Enter second number: ");
    scanf("%d",&n2);
    int result = maximum(n1,n2);
    printf("The maximum of %d and %d is: %d\n",n1,n2,result);
    
    return 0;
}