#include<stdio.h>
void findDuplicates(int arr[], int size) {
    printf("Duplicate elements: ");
    int found=0;
     for (int i=0;i<size;i++) 
     {
        for (int j=i+1;j<size;j++) 
        {
            if (arr[i]==arr[j])
             {
                int alreadyPrinted = 0;
                for (int k = 0; k < i; k++) {
                    if (arr[k] == arr[i]) {
                        alreadyPrinted = 1;
                        break;
                    }
                }
            
                if (!alreadyPrinted) {
                    printf("%d ", arr[i]);
                    found = 1;
                }
                break;  
            }
        }
    }
      if(!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    int arr[]={10,5,20,8,10,15,5,20,25};
    int size=sizeof(arr)/sizeof(arr[0]); 
    printf("Arrays elements= ");
    for (int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    findDuplicates(arr,size);
    
    return 0;
}