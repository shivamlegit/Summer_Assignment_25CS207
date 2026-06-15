#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isPalindrome(char str[]) 
{
    int len=strlen(str);
    int i;
    for (i=0;i<len/2;i++) 
    {
        if (str[i] != str[len - 1 - i])
         {
            return false;  
        }
    }
    return true;  
}

int main() {
    char input[100];
    
    printf("Enter a string: ");
    fgets(input,sizeof(input),stdin);
    int len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    if (isPalindrome(input))
    {
        printf("\"%s\" is a palindrome\n", input);
    } else {
        printf("\"%s\" is not a palindrome\n", input);
    }
    
    return 0;
}