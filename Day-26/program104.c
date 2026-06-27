#include<stdio.h>
#include<ctype.h>
int main() {
    int score = 0;
    char answer;
    printf("=================================\n");
    printf("    Welcome to the C Quiz Game!  \n");
    printf("=================================\n\n")
    printf("1. Who is known as the father of the C language?\n");
    printf("   A) Bjarne Stroustrup\n");
    printf("   B) Dennis Ritchie\n");
    printf("   C) James Gosling\n");
    printf("   D) Guido van Rossum\n");
    printf("Your answer: ");
        scanf(" %c", &answer); 
    
    if (toupper(answer) == 'B') {
        printf("Correct!\n\n");
        score++; 
    } else {
        printf("Wrong! The correct answer is B) Dennis Ritchie.\n\n");
    }
    printf("2. What is the standard file extension for a C source code file?\n");
    printf("  A) .cpp\n");
    printf("  B) .java\n");
    printf("  C) .c\n");
    printf("  D) .txt\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    
    if (toupper(answer) == 'C') {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Wrong! The correct answer is C) .c\n\n");
    }

    printf("3. Which keyword is used to exit a loop immediately?\n");
    printf("   A) continue\n");
    printf("   B) exit\n");
    printf("   C) return\n");
    printf("   D) break\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    
    if (toupper(answer) == 'D') {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Wrong! The correct answer is D) break\n\n");
    }
    printf("=================================\n");
    printf("  Quiz Over! You scored %d out of 3. \n", score);
    printf("=================================\n");

    return 0;
}