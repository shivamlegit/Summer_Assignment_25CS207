#include<stdio.h>
long long power(int x, int n) 
 {
    long long result=1;
    
    for(int i=0;i<n;i++)
     {
        result= result*x;
    }
    
    return result;
}

int main()
 {
    int x=2,n=5;
    
    long long result = power(x, n);
    
    printf("%d^%d = %lld\n", x, n, result);
    
    return 0;
}