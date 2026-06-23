#include<stdio.h>
#include<ctype.h>
int main() 
{
    char sentence[1000];
    int vowels=0,consonants=0;

    printf("Input a sentenses== ");
    if (fgets(sentence, sizeof(sentence), stdin) != NULL) {
        for (int i=0;sentence[i ]!= '\0'; i++) 
        {
            
                        char ch = tolower(sentence[i]);

                if (isalpha(ch)) 
                {
            
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    vowels++;
                } else 
                {
                    consonants++;
                }
            }
        }

        // Print the final counts
        printf("Vowels are = %d\n", vowels);
        printf("Consonants are = %d\n", consonants);
        
    } else {
        printf("OOps! reading input.\n");
    } 

    return 0;
}