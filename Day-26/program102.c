#include <stdio.h>

int main() {
    int age;

    printf("=================================\n");
    printf("    Voting Eligibility Checker   \n");
    printf("=================================\n\n");

    // Ask the user to input their age
    printf("Please enter your age= ");
    if (scanf("%d", &age) != 1) {
        printf("Invalid input! Please enter a numerical value.\n");
        return 1; 
    }
    if (age>=18) {
        printf("\nYou are %d years old. Congratulations, you are eligible to vote!\n", age);
    } else if (age>=0) {
        printf("\nYou are %d years old. You are not eligible to vote yet.\n", age);
        printf("You will be eligible in %d year(s).\n", 18 - age);
    } else {
        printf("\nInvalid age! Age cannot be a negative number.\n");
    }

    return 0;
}