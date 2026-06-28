#include<stdio.h>
#include<string.h>
#define MAX_STUDENTS 100
#define MAX_LEN 50
struct Student {
    int roll;
    char name[MAX_LEN];
    char course[MAX_LEN];
    float marks;
};
void addStudent(struct Student s[], int *count);
void displayStudents(struct Student s[], int count);
void searchStudent(struct Student s[], int count);
void updateStudent(struct Student s[], int count);
void deleteStudent(struct Student s[], int *count);
void showTopper(struct Student s[], int count);
int main() {
    struct Student s[MAX_STUDENTS];
    int count = 0, choice;
        do {
        printf("\n=== Student Management System ===\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Show Topper\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(s, &count); break;
            case 2: displayStudents(s, count); break;
            case 3: searchStudent(s, count); break;
            case 4: updateStudent(s, count); break;
            case 5: deleteStudent(s, &count); break;
            case 6: showTopper(s, count); break;
            case 7: printf("Exiting program...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}

void addStudent(struct Student s[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student database is full!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &s[*count].roll);
    while (getchar() != '\n');

    printf("Enter Name: ");
    fgets(s[*count].name, MAX_LEN, stdin);
    s[*count].name[strcspn(s[*count].name, "\n")] = 0;

    printf("Enter Course: ");
    fgets(s[*count].course, MAX_LEN, stdin);
    s[*count].course[strcspn(s[*count].course, "\n")] = 0;

    printf("Enter Marks: ");
    scanf("%f", &s[*count].marks);

    (*count)++;
    printf("Student added successfully!\n");
}

void displayStudents(struct Student s[], int count) {
    if (count == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\n------------------------------------------------------------------\n");
    printf("%-10s %-20s %-20s %-10s\n", "Roll", "Name", "Course", "Marks");
    printf("------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-20s %-10.2f\n",
               s[i].roll, s[i].name, s[i].course, s[i].marks);
    }

    printf("------------------------------------------------------------------\n");
}

void searchStudent(struct Student s[], int count) {
    int roll, found = 0;

    if (count == 0) {
        printf("No records to search.\n");
        return;
    }

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            printf("\nStudent Found!\n");
            printf("Roll: %d\n", s[i].roll);
            printf("Name: %s\n", s[i].name);
            printf("Course: %s\n", s[i].course);
            printf("Marks: %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }
}

void updateStudent(struct Student s[], int count) {
    int roll, found = 0;

    if (count == 0) {
        printf("No records to update.\n");
        return;
    }

    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);
    while (getchar() != '\n');

    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            found = 1;

            printf("Enter New Name: ");
            fgets(s[i].name, MAX_LEN, stdin);
            s[i].name[strcspn(s[i].name, "\n")] = 0;

            printf("Enter New Course: ");
            fgets(s[i].course, MAX_LEN, stdin);
            s[i].course[strcspn(s[i].course, "\n")] = 0;

            printf("Enter New Marks: ");
            scanf("%f", &s[i].marks);

            printf("Record updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }
}

void deleteStudent(struct Student s[], int *count) {
    int roll, found = 0;

    if (*count == 0) {
        printf("No records to delete.\n");
        return;
    }

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < *count; i++) {
        if (s[i].roll == roll) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                s[j] = s[j + 1];
            }
            (*count)--;
            printf("Record deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }
}

void showTopper(struct Student s[], int count) {
    if (count == 0) {
        printf("No records available.\n");
        return;
    }

    int top = 0;
    for (int i = 1; i < count; i++) {
        if (s[i].marks > s[top].marks) {
            top = i;
        }
    }

    printf("\nTopper Details:\n");
    printf("Roll: %d\n", s[top].roll);
    printf("Name: %s\n", s[top].name);
    printf("Course: %s\n", s[top].course);
    printf("Marks: %.2f\n", s[top].marks);
}