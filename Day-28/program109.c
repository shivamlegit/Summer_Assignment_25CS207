#include<stdio.h>
#include<string.h>

// Define a structure to hold book information
struct Book {
    int id;
    char title[100];
    char author[50];
    int isAvailable; 
};

int main() {
    // Array of structures to store up to 100 books
    struct Book library[100];
    int bookCount = 0; 
    int choice;

    // Infinite loop to keep the menu active until the user exits
    while (1) {
        printf("\n--- Library Management System ---\n");
        printf("1. Add a Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add a new book
                if (bookCount < 100) {
                    printf("Enter Book ID: ");
                    scanf("%d", &library[bookCount].id);
                    
                    // Clear the newline character left by scanf before using fgets
                    getchar(); 
                    
                    printf("Enter Book Title: ");
                    fgets(library[bookCount].title, 100, stdin);
                    // Remove the trailing newline character added by fgets
                    library[bookCount].title[strcspn(library[bookCount].title, "\n")] = 0; 
                    
                    printf("Enter Author Name: ");
                    fgets(library[bookCount].author, 50, stdin);
                    library[bookCount].author[strcspn(library[bookCount].author, "\n")] = 0;
                    
                    library[bookCount].isAvailable = 1; // 1 means available
                    bookCount++;
                    printf("Book added successfully!\n");
                } else {
                    printf("The library database is full!\n");
                }
                break;

            case 2:
                // Display all stored books
                printf("\n--- List of Books ---\n");
                if (bookCount == 0) {
                    printf("No books are currently in the library.\n");
                } else {
                    for (int i = 0; i < bookCount; i++) {
                        printf("ID: %d | Title: %s | Author: %s | Status: %s\n",
                               library[i].id, 
                               library[i].title, 
                               library[i].author,
                               library[i].isAvailable ? "Available" : "Issued");
                    }
                }
                break;

            case 3:
                // Search for a specific book using a linear search
                {
                    int searchId;
                    int found = 0;
                    printf("Enter Book ID to search: ");
                    scanf("%d", &searchId);
                    
                    for (int i = 0; i < bookCount; i++) {
                        if (library[i].id == searchId) {
                            printf("Book Found - Title: %s, Author: %s\n", 
                                   library[i].title, library[i].author);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Book with ID %d was not found.\n", searchId);
                    }
                }
                break;

            case 4:
                // Terminate the program
                printf("Exiting the system...\n");
                return 0;

            default:
                // Handle invalid inputs
                printf("Invalid choice! Please select a valid option (1-4).\n");
        }
    }
    
    return 0;
}