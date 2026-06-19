#include<stdio.h>
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; 
        }
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}
int main() {
    int arr[] = {2,3,4,10,14,19,22,40};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=14; 
    
    printf("Array= ");
    for (int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\nTarget= %d\n", target);
    int result = binarySearch(arr,0,n-1,target);
    if (result==-1) {
        printf("Result= Element is not present in the array.\n");
    } else {
        printf("Result= Element is present at index %d.\n", result);
    }

    return 0;
}