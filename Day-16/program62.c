#include<stdio.h>
int findMaxFrequencyElement(int arr[], int size) {
    int i,j,max_freq=0,max_freq_elem=arr[0];
    for(i=0;i<size;i++) 
    {
        int freq=1;
        for (j=i+1;j<size;j++) 
        {
            if(arr[i]==arr[j]) 
            {
                freq++;
            }
        }
        if (freq>max_freq)
         {
            max_freq=freq;
            max_freq_elem=arr[i];
        }
    }
    
    return max_freq_elem;
}

int main() {
    int arr[]={1,3,2,3,4,3,2,3,5,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    int max_elem = findMaxFrequencyElement(arr, size);
    printf("The most frequent element is=9 %d\n", max_elem);
    return 0;
}