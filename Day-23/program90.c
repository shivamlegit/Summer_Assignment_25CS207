#include <stdio.h>
#include <string.h>

int firstRepeatingChar(char *str) {
    // Array to store the frequency of each character
    int count[256] = {0}; 
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++; 
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (count[(unsigned char)str[i]] > 1) {
            return i;         }
    }
    return -1; 
}
int main() {
    char str[100];
    printf("Input a string= ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
    }

    int index=firstRepeatingChar(str);

    if (index==-1) {
        printf("No repeating characters found in the string.\n");
    } else {
        printf("The first repeating character is '%c' at index %d.\n", str[index], index);
    }

    return 0;
}