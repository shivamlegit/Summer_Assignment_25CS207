#include<stdio.h>
#include<string.h>
struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

int main() {
    struct Account bank[100];
    int accountCount = 0;
    int choice;
    while (1) {
        printf("\n--- Bank Account System ---\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Account Details / Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (accountCount < 100) {
                    printf("Enter Account Number: ");
                    scanf("%d", &bank[accountCount].accountNumber);
                    getchar(); 
                     printf("Enter Account Holder Name= ");
                    fgets(bank[accountCount].name, 50, stdin);
                    // Remove trailing newline from fgets
                    bank[accountCount].name[strcspn(bank[accountCount].name, "\n")] = 0;
                    
                    bank[accountCount].balance = 0.0; // Initial balance is 0
                    accountCount++;
                    printf("Account created successfully! Initial balance is $0.00\n");
                } else {
                    printf("The bank's database is full!\n");
                }
                break;

            case 2:
                // Deposit money
                {
                    int searchAcc;
                    float amount;
                    int found = 0;
                    
                    printf("Enter Account Number: ");
                    scanf("%d", &searchAcc);
                    
                    for (int i = 0; i < accountCount; i++) {
                        if (bank[i].accountNumber == searchAcc) {
                            printf("Enter amount to deposit: $");
                            scanf("%f", &amount);
                            if (amount > 0) {
                                bank[i].balance += amount;
                                printf("Deposit successful! New Balance: $%.2f\n", bank[i].balance);
                            } else {
                                printf("Invalid amount. Deposit must be greater than 0.\n");
                            }
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Account Number %d not found.\n", searchAcc);
                    }
                }
                break;

            case