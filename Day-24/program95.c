#include<stdio.h>
#include<string.h>
#include<ctype.h>
void findLongestWord(char *str) {
    int maxLen=0,maxStart=0;
    int currLen=0,currStart=0;
    int i=0;
    while (str[i] != '\0') {
        if (isalnum((unsigned char)str[i])) {
            if (currLen==0) {
                currStart=i;
            }
            currLen++; 
        } else {
            if (currLen>maxLen) {
                maxLen=currLen;
                maxStart=currStart;
            }
            currLen=0; 
        }
        i++;
    }
    if (currLen > maxLen) {
        maxLen = currLen;
        maxStart = currStart;
    }
    if (maxLen > 0) {
        printf("The longest word is= \"");
        for (int j = 0; j < maxLen; j++) {
            printf("%c", str[maxStart + j]);
        }
        printf("\" (Length: %d)\n",maxLen);
    } else {
        printf("No valid words found in the string.\n");
    }
}
int main() {
    char str[200];

    printf("Iput a sentence= ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
    }

    findLongestWord(str);

    return 0;
}