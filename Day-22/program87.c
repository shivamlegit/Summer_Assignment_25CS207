#include<stdio.h>
#include<string.h>
int main() 
{
    char str[1000];
    int freq[256]={0};

    printf("Input your a string= ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
        for (int i = 0; str[i] != '\0'; i++) {
            freq[(unsigned char)str[i]]++;
        }

        printf("\nCharacter Frequencies:\n");
        printf("----------------------\n");
        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {
                printf("'%c' == %d\n", i, freq[i]);
            }
        }
    } else {
        printf("Oops reading input.\n");
    }

    return 0;
}