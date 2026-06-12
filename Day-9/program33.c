#include<stdio.h>

int main(void)
{
    int rows=5;           
    for (int i=rows;i>=1;--i)
    {  
        for (int j=0;j<i;++j)
        {   
            putchar('*');
        }
        putchar('\n');                 
    }
    return 0;
}