#include<stdio.h>

// the function to find gcd
int findgcd(int a,int b)
 {
    int remainder;
    
    // continue loop until the remainder becomes 0
    while(b!= 0)
     {
        remainder=a%b; // to get the remainder of a divided by b
        a=b;             // change a with b
        b=remainder;     // change b with the remainder
    }
    
    // When b becomes 0, a contains the GCD
    return a;
}

int main() 
{
    int n1,n2,gcd;
    printf("enter two integers= ");
    scanf("%d %d",&n1,&n2);

    // for the negative input
    // gcd is always a positive number)
    int a=(n1 >0) ? n1: -n1;
    int b= (n2 >0) ? n2: -n2;
    gcd = findgcd(a,b);

    printf("hence the gcd of %d and %d is %d\n", n1,n2,gcd);

    return 0;
}