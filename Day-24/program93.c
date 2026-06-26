#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
bool areRotations(char *str1, char *str2) {
    int len1=strlen(str1);
    int len2=strlen(str2);
    if (len1 !=len2||len1== 0) {
        return false;
    }

    char*temp=(char*)malloc(sizeof(char)*(len1*2+1));
    if (temp==NULL) {
        printf("Memory allocation failed!\n");
        return false;
    }
    strcpy(temp, str1);
    strcat(temp, str1);
    bool isRotation = false;
    if (strstr(temp, str2) != NULL) {
        isRotation = true;
    }
    free(temp);
     return isRotation;
}

int main() {
    char str1[100], str2[100];

    printf("Input the first string: ");
    if (fgets(str1, sizeof(str1), stdin) != NULL) {
        str1[strcspn(str1, "\n")] = '\0'; 
    }

    printf("Enter the second string: ");
    if (fgets(str2, sizeof(str2), stdin) !=NULL) {
        str2[strcspn(str2, "\n")]='\0'; 
    }

    if (areRotations(str1, str2)) {
        printf("\"%s\" and \"%s\" ARE rotations of each other.\n", str1, str2);
    } else {
        printf("\"%s\" and \"%s\" are NOT rotations of each other.\n", str1, str2);
    }

    return 0;
}