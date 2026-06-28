#include <stdio.h>
#include <string.h>

#define MAX 100 
void removeNewline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
void reverseString(char *str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int choice;
    char str1[MAX], str2[MAX];
    int result;

    do {
        printf("\n--- String Operations Menu ---\n");
        printf("1. Find Length of a String\n");
        printf("2. Copy a String\n");
        printf("3. Concatenate (Join) Two Strings\n");
        printf("4. Compare Two Strings\n");
        printf("5. Reverse a String\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        while (getchar() != '\n'); 

        switch (choice) {
            case 1: 
                printf("Enter a string: ");
                fgets(str1, MAX, stdin);
                removeNewline(str1);
                printf("Length of the string is: %lu\n", strlen(str1));
                break;

            case 2: 
                printf("Enter the source string: ");
                fgets(str1, MAX, stdin);
                removeNewline(str1);
                strcpy(str2, str1); // Copies str1 into str2
                printf("Copied string is: %s\n", str2);
                break;

            case 3: 
                printf("Enter the first string: ");
                fgets(str1, MAX, stdin);
                removeNewline(str1);
                printf("Enter the second string: ");
                fgets(str2, MAX, stdin);
                removeNewline(str2);
                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 4: 
                printf("Enter the first string: ");
                fgets(str1, MAX, stdin);
                removeNewline(str1);
                
                printf("Enter the second string: ");
                fgets(str2, MAX, stdin);
                removeNewline(str2);
                
                result = strcmp(str1, str2);
                if (result == 0) {
                    printf("Result: Both strings are exactly equal.\n");
                } else if (result < 0) {
                    printf("Result: String 1 is alphabetically less than String 2.\n");
                } else {
                    printf("Result: String 1 is alphabetically greater than String 2.\n");
                }
                break;

            case 5: 
                printf("Enter a string to reverse: ");
                fgets(str1, MAX, stdin);
                removeNewline(str1);
                reverseString(str1);
                printf("Reversed string is: %s\n", str1);
                break; 
                case 6: 
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please select an option between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}