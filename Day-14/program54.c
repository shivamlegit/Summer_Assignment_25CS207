#include<stdio.h>
int findFrequency(int arr[],int size,int key) 
{
    int count=0;
    for (int i=0;i<size;i++)
     {
        if (arr[i]==key) {
            count++;  
        }
    }
    return count;
}

int main() 
{
    int arr[] = {10,5,10,20,5,10,30};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key;
    
    printf("Array elements= ");
    for (int i=0;i<size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    printf("Input element to find frequency= ");
    scanf("%d", &key);
    
    int frequency=findFrequency(arr,size,key);
    
    if (frequency == 0) 
    {
        printf("Element %d not found in the array.\n", key);
    } else {
        printf("Frequency of %d is: %d\n", key, frequency);
    }
    
    return 0;
}