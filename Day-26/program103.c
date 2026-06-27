#include<stdio.h>
int main() {
    float balance=1000.00; 
    int pin=1234;          
    int enteredPin;
    int attempts=0;
    int choice;
    float amount;

    printf("=================================\n");
    printf("       Welcome to the ATM        \n");
    printf("=================================\n\n");
    while (attempts<3) {
        printf("Please Input your 4-digit PIN= ");
        if (scanf("%d", &enteredPin) != 1) {
            printf("Invalid input! Please enter numbers only.\n");
            while(getchar() != '\n'); 
            attempts++;
            continue;
        }

        if (enteredPin == pin) {
            printf("\nPIN accepted. Access granted.\n");
            break; 
        } else {
            printf("Incorrect PIN.\n");
            attempts++;
        }
    }
    if (attempts == 3) {
        printf("\nToo many incorrect attempts. Your account is temporarily locked.\n");
        return 1;
    }
    do {
        printf("\n========== ATM MENU ==========\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("==============================\n");
        printf("Enter your choice (1-4): ");
         if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number between 1 and 4.\n");
            while(getchar() != '\n'); 
            continue;
        }
        switch (choice) {
            case 1:
                printf("\n>>> Your current balance is: $%.2f <<<\n", balance);
                break;
                
            case 2:
                printf("\nEnter amount to deposit: $");
                if (scanf("%f", &amount) == 1 && amount > 0) {
                    balance += amount;
                    printf(">>> $%.2f deposited successfully. <<<\n", amount);
                } else {
                    printf(">>> Invalid amount. Deposit failed. <<<\n");
                    while(getchar() != '\n'); 
                }
                break;
                
            case 3:
                printf("\nEnter amount to withdraw: $");
                if (scanf("%f", &amount) == 1 && amount > 0) {
                    if (amount <= balance) {
                        balance -= amount;
                        printf(">>> Please collect your cash: $%.2f <<<\n", amount);
                    } else {
                        printf(">>> Insufficient funds! Your balance is only $%.2f <<<\n", balance);
                    }
                } else {
                    printf(">>> Invalid amount. Withdrawal failed. <<<\n");
                    while(getchar() != '\n'); 
                }
                break;
                
            case 4:
                printf("\nThank you for using our ATM. Please take your card. Goodbye!\n");
                break;
                
            default:
                printf("\n>>> Invalid choice! Please select an option between 1 and 4. <<<\n");
        }

    } while (choice != 4); 

    return 0;
}