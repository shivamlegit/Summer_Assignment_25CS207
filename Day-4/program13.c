#include<stdio.h>

int main() 
{
    int n;
    
    unsigned long long first=0,second=1,next;

    
    printf("Provide the number of terms= ");
    scanf("%d", &n);


    if (n<=0) 
    {
        printf("enter a positive integer .\n");
        return 0;
    }

    printf("Here fibonacci Series are= ");

    
    for (int i=1;i<=n;i++) {
        if (i==1) 
        {
            printf("%llu",first);
            continue;
        }
        if (i==2) 
        {
            printf(", %llu",second);
            continue;
        }
        
        next = first + second;
        printf(", %llu", next);
        first=second;
        second=next;
    }

    printf("\n");
    return 0;
}

