#include<stdio.h>

int main() {
    int n, originalNum;
    int binaryArray[32]; 
    int i=0;
    printf("Input a  a positive decimal number= ");
    scanf("%d",&n);

   
    if(n==0)
    {
        printf("binary equivalent of 0 is= 0\n");
        return 0;
    }

    originalNum=n; 

    while(n>0)
    {
        binaryArray[i]=n%2;  
        n=n/2;           
        i++;                       }
    
    printf("The binary equivalent of %d is= ", originalNum);
    for (int j=i-1;j>=0;j--)
    {
        printf("%d",binaryArray[j]);
    }
    printf("\n");

    return 0;
}