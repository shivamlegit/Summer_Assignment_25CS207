#include <stdio.h>
#include <string.h>

void removeSpaces(char str[]) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[count] = str[i];
            count++;
        }
    }

    str[count] = '\0';
}

int main() {
    char str[1000];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
        removeSpaces(str);
        printf("String after removing spaces: '%s'\n", str);
        
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}