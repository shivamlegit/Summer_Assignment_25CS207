#include<stdio.h>
#include<string.h>
#define MAX 100
struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};
void addItem(struct Item inventory[], int *count);
void displayItems(struct Item inventory[], int count);
void searchItem(struct Item inventory[], int count);
void updateQuantity(struct Item inventory[], int count);
void deleteItem(struct Item inventory[], int *count);

int main() {
    struct Item inventory[MAX]; 
    int itemCount = 0;         
    int choice;

    do {
        printf("\n=== Inventory Management System ===\n");
        printf("1. Add New Item\n");
        printf("2. Display All Items\n");
        printf("3. Search Item by ID\n");
        printf("4. Update Item Quantity\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(inventory, &itemCount);
                break;
            case 2:
                displayItems(inventory, itemCount);
                break;
            case 3:
                searchItem(inventory, itemCount);
                break;
            case 4:
                updateQuantity(inventory, itemCount);
                break;
            case 5:
                deleteItem(inventory, &itemCount);
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select an option between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to add a new item
void addItem(struct Item inventory[], int *count) {
    if (*count >= MAX) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    printf("\nEnter Item ID: ");
    scanf("%d", &inventory[*count].id);

    // Clear input buffer before taking a string
    while (getchar() != '\n'); 

    printf("Enter Item Name: ");
    fgets(inventory[*count].name, 50, stdin);
    // Remove newline character from fgets
    inventory[*count].name[strcspn(inventory[*count].name, "\n")] = 0;

    printf("Enter Quantity: ");
    scanf("%d", &inventory[*count].quantity);

    printf("Enter Price per unit: ");
    scanf("%f", &inventory[*count].price);

    (*count)++;
    printf("Item added successfully!\n");
}

// Function to display all items in a formatted table
void displayItems(struct Item inventory[], int count) {
    if (count == 0) {
        printf("\nThe inventory is currently empty.\n");
        return;
    }

    printf("\n------------------------------------------------------------\n");
    printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price ($)");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10d %-10.2f\n", 
               inventory[i].id, 
               inventory[i].name, 
               inventory[i].quantity, 
               inventory[i].price);
    }
    printf("------------------------------------------------------------\n");
}

// Function to search for an item by its ID
void searchItem(struct Item inventory[], int count) {
    if (count == 0) {
        printf("\nThe inventory is empty.\n");
        return;
    }

    int searchId, found = 0;
    printf("\nEnter the Item ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == searchId) {
            printf("\nItem Found!\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: $%.2f\n", 
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", searchId);
    }
}

// Function to update the quantity of an existing item
void updateQuantity(struct Item inventory[], int count) {
    if (count == 0) {
        printf("\nThe inventory is empty.\n");
        return;
    }

    int searchId, newQuantity, found = 0;
    printf("\nEnter the Item ID to update quantity: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == searchId) {
            printf("Current Quantity: %d\n", inventory[i].quantity);
            printf("Enter new Quantity: ");
            scanf("%d", &newQuantity);
            inventory[i].quantity = newQuantity;
            printf("Quantity updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", searchId);
    }
}

// Function to delete an item
void deleteItem(struct Item inventory[], int *count) {
    if (*count == 0) {
        printf("\nThe inventory is empty.\n");
        return;
    }

    int deleteId, found = 0;
    printf("\nEnter the Item ID to delete: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < *count; i++) {
        if (inventory[i].id == deleteId) {
            found = 1;
            // Shift all subsequent items one space to the left to overwrite the deleted item
            for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*count)--;
            printf("Item deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", deleteId);
    }
}