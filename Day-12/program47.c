#include<stdio.h>
void printFibonacci(int terms) 
{
    int first=0,second=1,next;
     printf("Fibonacci Series= ");

    for (int i=0;i<terms;i++)
     {
        if (i<=1) 
        {
            next=i; 
        } else {
            next=first+second;
            first=second;        
            second=next;        
        }
        printf("%d ",next);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Input the number of terms= ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("enter a positive integer greater than 0.\n");
    } else {
        printFibonacci(n);
    }

    return 0;
}
