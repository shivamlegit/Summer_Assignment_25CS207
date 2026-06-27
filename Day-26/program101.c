#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int secretNumber;
    int guess;
    int attempts = 0;

    srand(time(NULL));
    secretNumber = rand() % 100 + 1;
    printf("========================================\n");
    printf("   Welcome to the Number Guessing Game! \n");
    printf("========================================\n");
    printf("I have picked a number between 1 and 100.\n");
    printf("Can you guess what it is?\n\n");
    do {
        printf("input your guess= ");
        
        // Read the user's input
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n'); 
            continue;
        }

        attempts++;
        if (guess > secretNumber) {
            printf("Too high! Try again.\n\n");
        } else if (guess < secretNumber) {
            printf("Too low! Try again.\n\n");
        } else {
            printf("\nCongratulations! You guessed the number in %d attempts!\n", attempts);
        }

    } while (guess != secretNumber);

    return 0;
}