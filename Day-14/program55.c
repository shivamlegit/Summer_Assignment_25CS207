#include<stdio.h>
#include<limits.h>
int findSecondLargest(int arr[], int size)
 {
    if (size < 2) {
        printf("Oops= Array must have at least 2 elements.\n");
        return INT_MIN;
    }
    
    int largest=INT_MIN;
    int secondLargest=INT_MIN;
    
    for (int i=0;i<size;i++) {
        if (arr[i]>largest) {
            secondLargest=largest;
            largest = arr[i];
        }
        else if (arr[i]>secondLargest&&arr[i] !=largest) 
        {
            secondLargest=arr[i];
        }
    }
    
    if (secondLargest==INT_MIN) {
        printf("Oops=: No second largest element (all elements are same).\n");
        return INT_MIN;
    }
    
    return secondLargest;
}

int main() {
    int arr[] = {10,5,20,8,15,25,20};
    int size=sizeof(arr)/sizeof(arr[0]);
    
    printf("Array elements= ");
    for (int i=0;i<size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    int secondLargest=findSecondLargest(arr,size);
    if (secondLargest != INT_MIN) 
    {
        printf("Second largest element isfound to be = %d\n", secondLargest);
    }
    
    return 0;
}