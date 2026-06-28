#include<stdio.h>
struct Student {
    int rollNo;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade;
};
void calculateResult(struct Student *s) {
    int i;
    s->total = 0;
    for (i = 0; i < 5; i++) {
        s->total += s->marks[i];
    }
    s->percentage = s->total / 5.0f;
    if (s->percentage >= 90)
        s->grade = 'A';
    else if (s->percentage >= 80)
        s->grade = 'B';
    else if (s->percentage >= 70)
        s->grade = 'C';
    else if (s->percentage >= 60)
        s->grade = 'D';
    else
        s->grade = 'F';
}
void printMarksheet(struct Student s) {
    int i;
    printf("\n========== MARKSHEET ==========\n");
    printf("Roll No. : %d\n", s.rollNo);
    printf("Name     : %s\n", s.name);

    for (i = 0; i < 5; i++) {
        printf("Subject %d Marks: %d\n", i + 1, s.marks[i]);
    }

    printf("Total    : %d\n", s.total);
    printf("Percent  : %.2f%%\n", s.percentage);
    printf("Grade    : %c\n", s.grade);
    printf("================================\n");
}

int main() {
    struct Student s;
    int i;
    printf("Enter Roll No: ");
    scanf("%d", &s.rollNo);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
        for (i = 0; i < 5; i++) {
        printf("Enter marks for Subject %d: ", i + 1);
        scanf("%d", &s.marks[i]);
    }
    calculateResult(&s);
    printMarksheet(s);
    return 0;
}