#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool areAnagrams(char *str1, char *str2) {
    int count[256] = {0}; 
    int i;
    if (strlen(str1) != strlen(str2)) {
        return false;
    }
    for (i = 0; str1[i] != '\0'; i++) {
        count[(unsigned char)str1[i]]++; 
        count[(unsigned char)str2[i]]--; 
    }

    for (i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return false; 
        }
    }

    return true; 
}

int main() {
    char str1[100], str2[100];

    printf("Input the first string= ");
    if (fgets(str1, sizeof(str1), stdin) != NULL) {
        str1[strcspn(str1, "\n")] = '\0';
    }

    printf("Input the second string= ");
    if (fgets(str2, sizeof(str2), stdin) != NULL) {
        str2[strcspn(str2, "\n")] = '\0';
    }

    if (areAnagrams(str1, str2)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", str1, str2);
    } else {
        printf("\"%s\" and \"%s\" are NOT anagrams.\n", str1, str2);
    }

    return 0;
}