#include<stdio.h>
int findMissingNumber(int arr[], int size) {
    int i, sum = 0;
    int n=size+1; 
    for (i=0;i<size;i++)
     {
        sum=sum+ arr[i];
    }
    return (n *(n+1))/2-sum;
}

int main() 
{
    int arr[] = {1,2,3,4,5,6,7,9,10};  
    int size=sizeof(arr)/sizeof(arr[0]);
    int missing = findMissingNumber(arr, size);
    printf("Here the missing number is= %d\n", missing);
    return 0;
}