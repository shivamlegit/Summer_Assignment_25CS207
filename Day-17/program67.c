#include<stdio.h>
int isPresent(int arr[], int size, int element) {
    for(int i=0;i<size;i++) {
        if (arr[i]==element) 
        {
            return 1;
        }
    }
    return 0;
}

int main() {
    int arr1[]={7,1,5,2,3,6,7}; 
    int arr2[]={3,8,6,20,7};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]); 
    int minSize = (size1 < size2) ? size1 : size2;
    int intersectionArr[minSize];
    int intersectionSize = 0; 
    for (int i=0;i<size1;i++) {
        if (isPresent(arr2,size2,arr1[i]) && !isPresent(intersectionArr, intersectionSize, arr1[i])) {
            intersectionArr[intersectionSize] = arr1[i];
            intersectionSize++;
        }
    }
    printf("Intersection of the arrays= ");
    for (int i=0;i<intersectionSize;i++) {
        printf("%d ", intersectionArr[i]);
    }
    printf("\n");
    
    return 0;
}