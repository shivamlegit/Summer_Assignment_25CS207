#include<stdio.h>
int removeDuplicates(int arr[],int size)
 {
    int i,j,k;
    for (i=0;i<size;i++) 
    {
        for (j=i+1;j<size;j++) 
        {
            if (arr[i]==arr[j])
             {
                for (k=j;k<size-1;k++)
                 {
                    arr[k]=arr[k + 1];
                }
                size--; 
                j--; 
            }
        }
    }
    
    return size;  
}

int main() {
    int arr[] = {1,2,3,2,4,1,5,3,6,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    
    printf("Original array is = ");
    for(i=0;i<size;i++)
     {
        printf("%d ",arr[i]);
    }
    printf("\n");
    int newSize=removeDuplicates(arr,size);
    
    printf("After removing duplicates= ");
    for (i=0;i<newSize;i++) 
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("New size is = %d\n", newSize);
    
    return 0;
}