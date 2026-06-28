#include<stdio.h>
#include<string.h>
#define MAX 100

struct Employee {
    int id;
    char name[50];
    char designation[50];
    float salary;
};

struct Employee emp[MAX];
int n = 0;

void addEmployee() {
    if (n >= MAX) {
        printf("Employee list is full.\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &emp[n].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", emp[n].name);

    printf("Enter Designation: ");
    scanf(" %[^\n]", emp[n].designation);

    printf("Enter Salary: ");
    scanf("%f", &emp[n].salary);

    n++;
    printf("Employee added successfully.\n");
}

void displayEmployees() {
    int i;
    if (n == 0) {
        printf("No employee records found.\n");
        return;
    }

    printf("\nEmployee Records:\n");
    printf("--------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("ID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Designation: %s\n", emp[i].designation);
        printf("Salary: %.2f\n", emp[i].salary);
        printf("--------------------------------------------------\n");
    }
}

void searchEmployee() {
    int id, i, found = 0;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++) {
        if (emp[i].id == id) {
            printf("Employee Found:\n");
            printf("ID: %d\n", emp[i].id);
            printf("Name: %s\n", emp[i].name);
            printf("Designation: %s\n", emp[i].designation);
            printf("Salary: %.2f\n", emp[i].salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found.\n");
    }
}

void updateEmployee() {
    int id, i, found = 0;
    printf("Enter Employee ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++) {
        if (emp[i].id == id) {
            printf("Enter New Name: ");
            scanf(" %[^\n]", emp[i].name);

            printf("Enter New Designation: ");
            scanf(" %[^\n]", emp[i].designation);

            printf("Enter New Salary: ");
            scanf("%f", &emp[i].salary);

            printf("Employee record updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found.\n");
    }
}

void deleteEmployee() {
    int id, i, j, found = 0;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++) {
        if (emp[i].id == id) {
            for (j = i; j < n - 1; j++) {
                emp[j] = emp[j + 1];
            }
            n--;
            printf("Employee deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: return 0;
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}