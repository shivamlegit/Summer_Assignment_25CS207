#include<stdio.h>
#include<string.h>
int main() {
    char words[5][50]={
        "Elephant",
        "Cat",
        "Hippopotamus",
        "Dog",
        "Tiger"
    };
    
    int n=5;
    char temp[50];
    printf("Words before sorting=\n");
    for (int i = 0; i < n; i++) {
        printf("%s (Length: %lu)\n", words[i], strlen(words[i]));
    }
    printf("\n");
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (strlen(words[j]) > strlen(words[j + 1])) {
                // Swap words[j] and words[j+1] using strcpy
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    printf("Words after sorting by length (shortest to longest):\n");
    for (int i = 0; i < n; i++) {
        printf("%s (Length: %lu)\n", words[i], strlen(words[i]));
    }

    return 0;
}
