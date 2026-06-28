#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_LEN 50

struct Book {
    int id;
    char title[MAX_LEN];
    char author[MAX_LEN];
    int copies;
    int issued;
};

void addBook(struct Book library[], int *count);
void displayBooks(struct Book library[], int count);
void searchBook(struct Book library[], int count);
void issueBook(struct Book library[], int count);
void returnBook(struct Book library[], int count);

int main() {
    struct Book library[MAX_BOOKS];
    int count = 0;
    int choice;

    do {
        printf("\n=== Mini Library System ===\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                displayBooks(library, count);
                break;
            case 3:
                searchBook(library, count);
                break;
            case 4:
                issueBook(library, count);
                break;
            case 5:
                returnBook(library, count);
                break;
            case 6:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}

void addBook(struct Book library[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &library[*count].id);
    while (getchar() != '\n');

    printf("Enter Book Title: ");
    fgets(library[*count].title, MAX_LEN, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = 0;

    printf("Enter Author Name: ");
    fgets(library[*count].author, MAX_LEN, stdin);
    library[*count].author[strcspn(library[*count].author, "\n")] = 0;

    printf("Enter Number of Copies: ");
    scanf("%d", &library[*count].copies);

    library[*count].issued = 0;
    (*count)++;

    printf("Book added successfully!\n");
}

void displayBooks(struct Book library[], int count) {
    if (count == 0) {
        printf("No books found.\n");
        return;
    }

    printf("\n--------------------------------------------------------------------------------\n");
    printf("%-10s %-25s %-25s %-10s %-10s\n", "ID", "Title", "Author", "Copies", "Issued");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-25s %-10d %-10d\n",
               library[i].id,
               library[i].title,
               library[i].author,
               library[i].copies,
               library[i].issued);
    }

    printf("--------------------------------------------------------------------------------\n");
}

void searchBook(struct Book library[], int count) {
    int id, found = 0;

    if (count == 0) {
        printf("No books to search.\n");
        return;
    }

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            printf("\nBook Found!\n");
            printf("ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Copies: %d\n", library[i].copies);
            printf("Issued: %d\n", library[i].issued);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found!\n");
    }
}

void issueBook(struct Book library[], int count) {
    int id;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            if (library[i].issued < library[i].copies) {
                library[i].issued++;
                printf("Book issued successfully!\n");
            } else {
                printf("No available copies to issue.\n");
            }
            return;
        }
    }

    printf("Book not found!\n");
}

void returnBook(struct Book library[], int count) {
    int id;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            if (library[i].issued > 0) {
                library[i].issued--;
                printf("Book returned successfully!\n");
            } else {
                printf("No issued copies to return.\n");
            }
            return;
        }
    }

    printf("Book not found!\n");
}