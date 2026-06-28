#include<stdio.h>
#include<string.h>
struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

int main() {
    struct Contact phonebook[100];
    int contactCount = 0;
    int choice;
    while (1) {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add a New Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search for a Contact by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                if (contactCount < 100) {
                    printf("Enter Name: ");
                    fgets(phonebook[contactCount].name, 50, stdin);
                    phonebook[contactCount].name[strcspn(phonebook[contactCount].name, "\n")] = 0;

                    printf("Enter Phone Number: ");
                    fgets(phonebook[contactCount].phone, 20, stdin);
                    phonebook[contactCount].phone[strcspn(phonebook[contactCount].phone, "\n")] = 0;

                    printf("Enter Email Address: ");
                    fgets(phonebook[contactCount].email, 50, stdin);
                    phonebook[contactCount].email[strcspn(phonebook[contactCount].email, "\n")] = 0;

                    contactCount++;
                    printf("Contact added successfully!\n");
                } else {
                    printf("The phonebook is full!\n");
                }
                break;

            case 2:
                // Display all stored contacts
                printf("\n--- Contact List ---\n");
                if (contactCount == 0) {
                    printf("Your phonebook is currently empty.\n");
                } else {
                    for (int i = 0; i < contactCount; i++) {
                        printf("%d. Name: %s | Phone: %s | Email: %s\n", 
                               i + 1, 
                               phonebook[i].name, 
                               phonebook[i].phone, 
                               phonebook[i].email);
                    }
                }
                break;

            case 3:
                // Search for a specific contact using string comparison
                {
                    char searchName[50];
                    int found = 0;
                    
                    printf("Enter the Name to search: ");
                    fgets(searchName, 50, stdin);
                    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

                    for (int i = 0; i < contactCount; i++) {

                        if (strcmp(phonebook[i].name, searchName) == 0) {
                            printf("\n--- Contact Found ---\n");
                            printf("Name  : %s\n", phonebook[i].name);
                            printf("Phone : %s\n", phonebook[i].phone);
                            printf("Email : %s\n", phonebook[i].email);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Contact named '%s' was not found.\n", searchName);
                    }
                }
                break;
            case 4:
                printf("Exiting the Contact Management System...\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option (1-4).\n");
        }
    }

    return 0;
}