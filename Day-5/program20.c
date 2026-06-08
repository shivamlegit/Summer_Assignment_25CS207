#include<stdio.h>

int main() {
    
    long long n;
    long long largest_factor = -1;
    printf("Input a positive integer: ");
    scanf("%lld",&n);
    if(n<=1)
    {
        printf("No prime factors a numbers less than 2.\n");
        return 0;
    }

    long long originalNum = n;
    long long i = 2;             

    while (n > 1) {
        if (n % i == 0) {
            largest_factor=i; 
            n =n/i;       
        } else
        {
            i++;                
        }
    }

    // 3. Print the result
    printf("The largest prime factor of the number %lld is= %lld\n",originalNum,largest_factor);

    return 0;
}