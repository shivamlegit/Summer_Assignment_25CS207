#include<stdio.h>
int main() 
{
    int arr1[]={10,20,30,40};
    int arr2[]={50,60,70};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int mergedSize = size1 + size2;
    int mergedArr[mergedSize];
    for (int i = 0; i < size1; i++) {
        mergedArr[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++){
        mergedArr[size1 + i] = arr2[i]; 
    }
    printf("Merged Array= ");
    for (int i=0;i<mergedSize;i++) {
        printf("%d ", mergedArr[i]);
    }
    printf("\n");
     return 0;
}