#include<stdio.h>
#include<string.h>
char getMaxOccurringChar(char *str) {
    int count[256]={0}; 
    int i;
    int maxCount=-1;
    char maxChar='\0';
    for (i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++; 
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (count[(unsigned char)str[i]] > maxCount) {
            maxCount = count[(unsigned char)str[i]];
            maxChar = str[i];
        }
    }

    return maxChar;
}

int main() {
    char str[100];

    printf("Input a string= ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
    }
    if (strlen(str) == 0) {
        printf("The string is empty.\n");
        return 0;
    }

    char result = getMaxOccurringChar(str);
      printf("The maximum occurring character is '%c'.\n", result);

    return 0;
}