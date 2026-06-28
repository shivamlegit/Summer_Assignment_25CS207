#include<stdio.h>
#include<string.h>
#define MAX 100
struct Employee {
    int id;
    char name[50];
    char department[50];
    float basicSalary;
    float hra;
    float da;
    float grossSalary;
};

struct Employee emp[MAX];
int n = 0;
void calculateSalary(int i) {
    emp[i].grossSalary = emp[i].basicSalary + emp[i].hra + emp[i].da;
}

void addEmployee() {
    if (n >= MAX) {
        printf("Record list is full.\n");
        return;
    }
    printf("Enter Employee ID: ");
    scanf("%d", &emp[n].id);
    printf("Enter Name: ");
    scanf(" %[^\n]", emp[n].name);
    printf("Enter Department: ");
    scanf(" %[^\n]", emp[n].department);
    printf("Enter Basic Salary: ");
    scanf("%f", &emp[n].basicSalary);
    printf("Enter HRA: ");
    scanf("%f", &emp[n].hra);
    printf("Enter DA: ");
    scanf("%f", &emp[n].da);
    calculateSalary(n);
    n++;
    printf("Salary record added successfully.\n");
}
void displayEmployees() {
    int i;
    if (n == 0) {
        printf("No records found.\n");
        return;
    }
    printf("\nSalary Records:\n");
    printf("--------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("ID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Department: %s\n", emp[i].department);
        printf("Basic Salary: %.2f\n", emp[i].basicSalary);
        printf("HRA: %.2f\n", emp[i].hra);
        printf("DA: %.2f\n", emp[i].da);
        printf("Gross Salary: %.2f\n", emp[i].grossSalary);
        printf("--------------------------------------------------\n");
    }
}
void searchEmployee() {
    int id, i, found = 0;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);
    for (i = 0; i < n; i++) {
        if (emp[i].id == id) {
            printf("Record Found:\n");
            printf("ID: %d\n", emp[i].id);
            printf("Name: %s\n", emp[i].name);
            printf("Department: %s\n", emp[i].department);
            printf("Basic Salary: %.2f\n", emp[i].basicSalary);
            printf("HRA: %.2f\n", emp[i].hra);
            printf("DA: %.2f\n", emp[i].da);
            printf("Gross Salary: %.2f\n", emp[i].grossSalary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record not found.\n");
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
            printf("Enter New Department: ");
            scanf(" %[^\n]", emp[i].department);
            printf("Enter New Basic Salary: ");
            scanf("%f", &emp[i].basicSalary);
            printf("Enter New HRA: ");
            scanf("%f", &emp[i].hra);
            printf("Enter New DA: ");
            scanf("%f", &emp[i].da);
            calculateSalary(i);
            printf("Record updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found.\n");
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
            printf("Record deleted successfully.\n");
            found = 1;
            break;
        }
    }
if (!found) {
        printf("Record not found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Salary Management System =====\n");
        printf("1. Add Salary Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
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