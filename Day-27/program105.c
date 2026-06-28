#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
    int rollNo;
    char name[50];
    int age;
    float marks;
};

void addStudent() {
    FILE *fp = fopen("students.dat", "ab");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Student s;
    printf("Enter Roll No: ");
    scanf("%d", &s.rollNo);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name); // reads string with spaces
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(struct Student), 1, fp);
    fclose(fp);
    printf("Record added successfully!\n");
}

void displayAll() {
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    struct Student s;
    printf("\n--- All Student Records ---\n");
    printf("Roll\tName\t\tAge\tMarks\n");
    printf("--------------------------------------\n");

    while (fread(&s, sizeof(struct Student), 1, fp)) {
        printf("%d\t%-15s\t%d\t%.2f\n", s.rollNo, s.name, s.age, s.marks);
    }
    fclose(fp);
}

void searchStudent() {
    int roll, found = 0;
    printf("Enter Roll No to search: ");
    scanf("%d", &roll);

    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    struct Student s;
    while (fread(&s, sizeof(struct Student), 1, fp)) {
        if (s.rollNo == roll) {
            printf("\nRecord Found:\n");
            printf("Roll: %d\nName: %s\nAge: %d\nMarks: %.2f\n",
                   s.rollNo, s.name, s.age, s.marks);
            found = 1;
            break;
        }
    }
    if (!found) printf("Student with Roll No %d not found.\n", roll);
    fclose(fp);
}

void deleteStudent() {
    int roll, found = 0;
    printf("Enter Roll No to delete: ");
    scanf("%d", &roll);

    FILE *fp = fopen("students.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (fp == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Student s;
    while (fread(&s, sizeof(struct Student), 1, fp)) {
        if (s.rollNo == roll) {
            found = 1;
        } else {
            fwrite(&s, sizeof(struct Student), 1, temp);
        }
    }
    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found) printf("Record deleted successfully!\n");
    else printf("Student with Roll No %d not found.\n", roll);
}

int main() {
    int choice;
    while (1) {
        printf("\n=== Student Record Management System ===\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}