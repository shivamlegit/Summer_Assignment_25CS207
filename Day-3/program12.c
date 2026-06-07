#include<stdio.h>

int main()
{
    int n1,n2, m;

    //1: two numberprovided by user
    printf("provide two positive numbers= ");
    scanf("%d %d", &n1,&n2);

    //2: to get the the larger of the two number
    rs
    //lcm cannot be smaller than the largest input
    if (n1> n2) 
    {
        m=n1;
    } else
     {
        m=n2;
    }

    //3= counting up until we find the LCM
    while(1)
    { // This creates a loop that runs until we use break
        
        if ((m%n1 == 0) && (m%n2 == 0)) {
            printf("The LCM of %d and %d is %d\n",n1,n2,m);
            break; // We found the LCM! Stop the loop entirely.
        }
        
        m++; 
    }

    return 0;
}
