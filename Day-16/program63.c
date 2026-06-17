#include<stdio.h>
int findPairWithSum(int arr[], int size, int sum) 
{
    int i,j;
    for (i=0;i<size-1;i++)
     {
        for(j=i+1;j<size;j++)
         {
           if (arr[i]+arr[j]==sum)
            {
                printf("Pair has found=%d and %d (at indices %d and %d)\n", 
                       arr[i], arr[j],i,j);
                                       return 1; 
                                                }
        }
    }
    
    printf("No pair with the given sum exists.\n");
    return 0;  
}

int main() {
    int arr[]={1,4,6,9,-3,12,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    int target_sum=10;
    printf("Array= ");
    for(int i = 0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    printf("Target Sum is = %d\n", target_sum);
    
    findPairWithSum(arr, size, target_sum);
    
        return 0;
}
