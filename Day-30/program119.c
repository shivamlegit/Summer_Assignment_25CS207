#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_LEN 50

struct Employee {
    int id;
    char name[MAX_LEN];
    char department[MAX_LEN];
    float salary;
};

void addEmployee(struct Employee emp[], int *count);
void displayEmployees(struct Employee emp[], int count);
void searchEmployee(struct Employee emp[], int count);
void updateEmployee(struct Employee emp[], int count);
void deleteEmployee(struct Employee emp[], int *count);

int main() {
    struct Employee emp[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    do {
        printf("\n=== Mini Employee Management System ===\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(emp, &count);
                break;
            case 2:
                displayEmployees(emp, count);
                break;
            case 3:
                searchEmployee(emp, count);
                break;
            case 4:
                updateEmployee(emp, count);
                break;
            case 5:
                deleteEmployee(emp, &count);
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

void addEmployee(struct Employee emp[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Employee database is full!\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &emp[*count].id);
    while (getchar() != '\n');

    printf("Enter Employee Name: ");
    fgets(emp[*count].name, MAX_LEN, stdin);
    emp[*count].name[strcspn(emp[*count].name, "\n")] = 0;

    printf("Enter Department: ");
    fgets(emp[*count].department, MAX_LEN, stdin);
    emp[*count].department[strcspn(emp[*count].department, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &emp[*count].salary);

    (*count)++;
    printf("Employee added successfully!\n");
}

void displayEmployees(struct Employee emp[], int count) {
    if (count == 0) {
        printf("No employee records found.\n");
        return;
    }

    printf("\n------------------------------------------------------------------\n");
    printf("%-10s %-20s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-20s %-10.2f\n",
               emp[i].id, emp[i].name, emp[i].department, emp[i].salary);
    }

    printf("------------------------------------------------------------------\n");
}

void searchEmployee(struct Employee emp[], int count) {
    int id, found = 0;

    if (count == 0) {
        printf("No employee records to search.\n");
        return;
    }

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == id) {
            printf("\nEmployee Found!\n");
            printf("ID: %d\n", emp[i].id);
            printf("Name: %s\n", emp[i].name);
            printf("Department: %s\n", emp[i].department);
            printf("Salary: %.2f\n", emp[i].salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found!\n");
    }
}

void updateEmployee(struct Employee emp[], int count) {
    int id, found = 0;

    if (count == 0) {
        printf("No employee records to update.\n");
        return;
    }

    printf("\nEnter Employee ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == id) {
            found = 1;
            while (getchar() != '\n');

            printf("Enter New Name: ");
            fgets(emp[i].name, MAX_LEN, stdin);
            emp[i].name[strcspn(emp[i].name, "\n")] = 0;

            printf("Enter New Department: ");
            fgets(emp[i].department, MAX_LEN, stdin);
            emp[i].department[strcspn(emp[i].department, "\n")] = 0;

            printf("Enter New Salary: ");
            scanf("%f", &emp[i].salary);

            printf("Employee record updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Employee not found!\n");
    }
}

void deleteEmployee(struct Employee emp[], int *count) {
    int id, found = 0;

    if (*count == 0) {
        printf("No employee records to delete.\n");
        return;
    }

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (emp[i].id == id) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                emp[j] = emp[j + 1];
            }
            (*count)--;
            printf("Employee record deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Employee not found!\n");
    }
}