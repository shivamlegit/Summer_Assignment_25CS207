#include<stdio.h>
#include<stdlib.h>
#define MAX 100 
void display(int arr[], int size);
void insert(int arr[], int *size);
void deleteElement(int arr[], int *size);
void search(int arr[], int size);

int main() {
    int arr[MAX];
    int size = 0;
    int choice;

    do {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Create / Initialize Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Search Element\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements you want to add (max %d): ", MAX);
                scanf("%d", &size);
                if (size > MAX || size < 0) {
                    printf("Invalid size! Setting size to 0.\n");
                    size = 0;
                } else {
                    printf("Enter %d elements:\n", size);
                    for (int i = 0; i < size; i++) {
                        scanf("%d", &arr[i]);
                    }
                    printf("Array initialized successfully.\n");
                }
                break;
            case 2:
                display(arr, size);
                break;
            case 3:
                insert(arr, &size);
                break;
            case 4:
                deleteElement(arr, &size);
                break;
            case 5:
                search(arr, size);
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select an option between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
void display(int arr[], int size) {
    if (size == 0) {
        printf("The array is currently empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insert(int arr[], int *size) {
    if (*size >= MAX) {
        printf("Array Overflow! Cannot insert more elements.\n");
        return;
    }
    
    int pos, element;
    printf("Enter the position (1 to %d) to insert the new element: ", *size + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > *size + 1) {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &element);
    for (int i = *size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
     arr[pos - 1] = element; 
    (*size)++;              
    printf("Element %d successfully inserted at position %d.\n", element, pos);
}

// Function to delete an element from a specific position
void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("Array Underflow! The array is already empty.\n");
        return;
    }

    int pos;
    printf("Enter the position (1 to %d) of the element to delete: ", *size);
    scanf("%d", &pos);

    // Validating position
    if (pos < 1 || pos > *size) {
        printf("Invalid position!\n");
        return;
    }

    int deletedElement = arr[pos - 1];


for (int i = pos - 1; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    (*size)--; 
    printf("Element %d successfully deleted from position %d.\n", deletedElement, pos);
}

// Function to search for an element using Linear Search
void search(int arr[], int size) {
    if (size == 0) {
        printf("The array is empty. Nothing to search.\n");
        return;
    }

    int element, found = 0;
    printf("Enter the element to search for: ");
    scanf("%d", &element);

    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("Element %d found at position %d (index %d).\n", element, i + 1, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", element);
    }
}