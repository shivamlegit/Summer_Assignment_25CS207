#include<stdio.h>
#include<string.h>
#define MAX_STUDENTS 100 
#define MAX_LENGTH 50    
struct Student {
    int rollNumber;
    char name[MAX_LENGTH];
    char course[MAX_LENGTH];
    float marks;
};
void addStudent(struct Student records[], int *count);
void displayStudents(struct Student records[], int count);
void searchStudent(struct Student records[], int count);
int main () {
    struct Student records[MAX_STUDENTS]; 
    int studentCount = 0;                 
    int choice;

    do {
        printf("\n=== Student Record System ===\n");
        printf("1. Add New Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStudent(records, &studentCount);
                break;
            case 2:
                displayStudents(records, studentCount);
                break;
            case 3:
                searchStudent(records, studentCount);
                break;
            case 4:
                printf("Exiting the system. Best of luck with your classes!\n");
                break;
            default:
                printf("Invalid choice! Please select an option between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

void addStudent(struct Student records[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nDatabase is full! Cannot add more students.\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &records[*count].rollNumber);

    // Clear the input buffer before taking string inputs
    while (getchar() != '\n');

    printf("Enter Student Name: ");
    fgets(records[*count].name, MAX_LENGTH, stdin);
    // Remove the newline character added by fgets
    records[*count].name[strcspn(records[*count].name, "\n")] = 0;

    printf("Enter Course Name: ");
    fgets(records[*count].course, MAX_LENGTH, stdin);
    // Remove the newline character added by fgets
    records[*count].course[strcspn(records[*count].course, "\n")] = 0;

    printf("Enter Marks (out of 100): ");
    scanf("%f", &records[*count].marks);

    (*count)++; // Increment the total number of students
    printf("\nStudent record added successfully!\n");
}

// Function to display all student records in a table format
void displayStudents(struct Student records[], int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n------------------------------------------------------------------\n");
    printf("%-15s %-25s %-15s %-10s\n", "Roll Number", "Name", "Course", "Marks");
    printf("------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15d %-25s %-15s %-10.2f\n", 
               records[i].rollNumber, 
               records[i].name, 
               records[i].course, 
               records[i].marks);
    }
    printf("------------------------------------------------------------------\n");
}

// Function to search for a specific student by Roll Number
void searchStudent(struct Student records[], int count) {
    if (count == 0) {
        printf("\nNo student records to search.\n");
        return;
    }

    int searchRoll, found = 0;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &searchRoll);

    for (int i = 0; i < count; i++) {
        if (records[i].rollNumber == searchRoll) {
            printf("\n--- Student Found ---\n");
            printf("Roll Number: %d\n", records[i].rollNumber);
            printf("Name:        %s\n", records[i].name);
            printf("Course:      %s\n", records[i].course);
            printf("Marks:       %.2f\n", records[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with Roll Number %d not found in the system.\n", searchRoll);
    }
}