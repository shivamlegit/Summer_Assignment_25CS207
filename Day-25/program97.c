#include<stdio.h>
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int mergedArr[]) {
    int i=0; 
    int j=0; 
    int k=0; 
    while (i < size1 && j < size2) {
        if (arr1[i]<=arr2[j]) {
            mergedArr[k] = arr1[i];
            i++;
        } else 
        {
            mergedArr[k]=arr2[j];
            j++;
        }
        k++;
    }
    while (i<size1) {
        mergedArr[k] = arr1[i];
        i++;
        k++;
    
    while(j < size2) {
        mergedArr[k] = arr2[j];
        j++;
        k++;
    }
}
int main() {
    int arr1[]={1,3,5,7};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int arr2[]={2,4,6,8,10};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
  int mergedSize = size1 + size2;
    int mergedArr[mergedSize];
    mergeArrays(arr1, size1,arr2,size2,mergedArr);
    printf("Merged the Array= ");
    for (int i=0;i<mergedSize; i++) {
        printf("%d ", mergedArr[i]);
    }
    printf("\n");

    return 0;
}