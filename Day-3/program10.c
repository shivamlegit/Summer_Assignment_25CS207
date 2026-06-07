#include<stdio.h>

int main() {
    int start,end,i,j,isPrime;

    // 1. Take range from the user
    printf("Provide the starting number= ");
    scanf("%d",&start);
    printf("Provide the ending number= ");
    scanf("%d",&end);

    printf("All the prime numbers between %d and %d are:\n",start,end);

    for (i=start;i<= end;i++)
     {
        
        if (i<=1) {
            continue; 
        }

        isPrime=1;

        // 2. Inner loop= try to divide i by the every number ramge from 2 up to (i - 1)
        for(j=2;j<i;j++)
         {
            if (i%j==0)
             {
                isPrime=0; // It divided evenly hence the number is nOT a prime (0 means No)
                break;       // here if We found a factor we do no need to keep checking
            }
        }

        // 3. If our assumption held true and it is still a prime then print it
        if(isPrime==1)
         {
            printf("%d ",i);
        }
    }

    printf("\n");
    return 0;
}