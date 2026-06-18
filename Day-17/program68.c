#include<stdio.h>
int main() 
{
    int arr1[]={1,2,4,5,5,6,8};
    int arr2[]={2,3,5,7,8,9};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]);
    int i=0; 
    int j=0;
    
    printf("Common elements= ");
    while(i<size1&&j<size2) {
        
        if(i>0 && arr1[i]==arr1[i-1]) {
            i++;
            continue;
        }
        if(j>0 && arr2[j]==arr2[j-1]) {
            j++;
            continue;
        }
        if (arr1[i]<arr2[j]) {
            i++;
        } 
        else if (arr2[j]<arr1[i]) {
            
            j++;
        } 
        else 
        {
            printf("%d ",arr1[i]);
            i++;
            j++;
        }
    }
    
    printf("\n");
    
    return 0;
}