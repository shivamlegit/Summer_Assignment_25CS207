#include<stdio.h>
int countSetBits(unsigned int num)
{
    int count = 0;
    while (num)
    {
        num &=(num-1);  
        count++;
    }
    return count;
}

int main()
 {
    unsigned int num = 103; 
    
    int result =countSetBits(num);
    
    printf("Number of set bits in %u= %d\n", num, result);
    
    return 0;
}