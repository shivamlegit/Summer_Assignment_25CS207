#include<stdio.h>
int linearSearch(int arr[],int size,int key)
 {
    for (int i=0;i<size;i++)
     {
        if (arr[i]==key) 
        {
            return i;  
        }
    }
    return -1;  
}

int main() 
{
    int arr[] = {10,5,20,8,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key;
    
    printf("Array element =");
    for (int i=0;i<size;i++) 
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    printf("Input element to search= ");
    scanf("%d", &key);
    
    int result=linearSearch(arr,size,key);
    
    if (result !=-1) 
    {
        printf("Element found = %d\n", result);
    } else {
        printf("Element not found.\n");
    }
    
    return 0;
}