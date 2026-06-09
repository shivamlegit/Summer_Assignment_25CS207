#include<stdio.h>

int main()
{
    long long binary;
    int decimal=0,b=1,r;    //b is base and r is remainder

    printf("Input a binary number= ");
    scanf("%lld",&binary);

    long long temp=binary; 

    
    while(binary>0)
    {
        r=binary%10;          
        decimal=decimal+r*b; 
        b=b*2;           
        binary=binary/10;       
    }
    printf("Binary= %lld = Decimal; %d\n", temp, decimal);

    return 0;
}
