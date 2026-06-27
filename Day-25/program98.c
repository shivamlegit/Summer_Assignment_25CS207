#include<stdio.h>
void findCommonCharacters(char *str1, char *str2) {
    int present1[256]={0};
    int present2[256]={0};
    int foundCommon=0;
    for (int i = 0; str1[i] != '\0'; i++) {
        present1[(unsigned char)str1[i]] = 1;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        present2[(unsigned char)str2[i]] = 1;
    }

    printf("Common characters found  ===== ");
    for (int i = 0; i < 256; i++) {
        if (present1[i] == 1 && present2[i] == 1) {
            if (i != ' ') {
                printf("%c ", i);
                foundCommon = 1;
            }
        }
    }

    if (!foundCommon) {
        printf("None found.");
    }
    printf("\n");
}

int main() {
    char str1[] = "programming";
    char str2[] = "algorithm";

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    findCommonCharacters(str1, str2);

    return 0;
}