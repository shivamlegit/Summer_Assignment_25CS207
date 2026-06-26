#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void compressString(char *str) {
    int len=strlen(str);    
    if (len <=1) {
        return; 
    }
    char*compressed=(char*)malloc(len * 2 + 1);
    if (compressed==NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    int compIndex = 0; 
    for (int i=0;i<len;i++) {
        int count=1;
        while (i+1<len&&str[i]==str[i+1]) {
            count++;
            i++; 
        }
        compressed[compIndex++] = str[i];
        compIndex += sprintf(&compressed[compIndex], "%d", count);
    }
    
    compressed[compIndex]='\0';   
    if (strlen(compressed)<len) {
        strcpy(str, compressed);
    }
    free(compressed);
}

int main() {
    char str[100];

    printf("Enter a string to compress: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
    }
      printf("Original string: %s\n", str);
    compressString(str);
    printf("Compressed string: %s\n", str);
     return 0;
}