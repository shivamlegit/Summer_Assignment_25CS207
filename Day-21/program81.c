#include<stdio.h>

int main(void) 
{
    char str[200];
    int len=0;

    printf("Input a sstring = ");
    if (fgets(str, sizeof str, stdin) == NULL) return 0;

    /* Remove trailing newline if present */
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '\n') { str[i] = '\0'; break; }
    }
    while (str[len] != '\0') len++;

    printf("Length of the string is == %d\n", len);
    return 0;
}