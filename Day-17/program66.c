#include<stdio.h>
int isPresent(int arr[], int size, int element) 
{
    for(int i=0;i<size;i++)
     {
        if(arr[i]==element)
         {
            return 1;
        }
    }
    return 0; 
    }

int main() 
{
    int arr1[]={7,1,5,2,3,6,1}; 
    int arr2[]={3,8,6,20,7};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]);
    int unionArr[size1 + size2];
    int unionSize=0; 
    for (int i=0;i<size1;i++) {
        if(!isPresent(unionArr,unionSize,arr1[i])) {
            unionArr[unionSize]=arr1[i];
            unionSize++;
        }
    }
    for (int i=0;i<size2;i++) {
        if (!isPresent(unionArr,unionSize,arr2[i])) {
            unionArr[unionSize]=arr2[i];
            unionSize++;
        }
    }
    printf("Union of the arrays= ");
    for(int i=0;i<unionSize;i++) {
        printf("%d ",unionArr[i]);
    }
    printf("\n");
    
    return 0;
}