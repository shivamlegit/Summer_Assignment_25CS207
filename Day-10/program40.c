#include<stdio.h>

int main() {
    int rows=5;
    
    for (int i=1;i<=rows;i++) 
    {
        
        for (int j=1;j<=rows-i;j++)
         {
            printf(" ");
        }
        for (int k=0;k<i;k++)
        {
            printf("%c", 'A' + k);
        }
        for (int k=i-2;k>=0;k--)
         {
            printf("%c", 'A' + k);
        }
        printf("\n");
    }
    
    return 0;
}