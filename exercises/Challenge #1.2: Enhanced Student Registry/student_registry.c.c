#include "student_registry.h"
#include <stdio.h>
#include <string.h>

Student students[MAX_STUDENTS];
int totalStudents = 0;

void loadStudentsFromFile()
{
    FILE *file;

    file = fopen(FILE_NAME, "r");

    if (file == NULL)
    {
        printf("No existing data file found. Starting fresh.\n");
        return;
    }

    totalStudents = 0;

    while (totalStudents < MAX_STUDENTS &&
           fscanf(file, "%d|%99[^|]|%49[^|]|%f|%d\n",
                  &students[totalStudents].id,
                  students[totalStudents].name,
                  students[totalStudents].major,
                  &students[totalStudents].gpa,
                  &students[totalStudents].credits) == 5)
    {
        totalStudents++;
    }

    fclose(file);

    printf("Loaded %d student(s).\n", totalStudents);
}

void saveStudentsToFile()
{
    FILE *file;
    int i;

    file = fopen(FILE_NAME, "w");

    if (file == NULL)
    {
        printf("Error saving file.\n");
        return;
    }

    for (i = 0; i < totalStudents; i++)
    {
        fprintf(file,
                "%d|%s|%s|%.2f|%d\n",
                students[i].id,
                students[i].name,
                students[i].major,
                students[i].gpa,
                students[i].credits);
    }

    fclose(file);

    printf("Students saved successfully.\n");
}

void addStudent()
{
    if (totalStudents >= MAX_STUDENTS)
    {
        printf("\nStudent list is full!\n");
        return;
    }

    while (1)
    {
        printf("\nEnter Student ID: ");

        if (scanf("%d", &students[totalStudents].id) == 1 &&
            students[totalStudents].id > 0)
        {
            getchar();
            break;
        }

        printf("Invalid input.\n");

        while (getchar() != '\n');
    }

    printf("Enter Student Name: ");
    fgets(students[totalStudents].name, NAME_LENGTH, stdin);
    students[totalStudents].name[strcspn(students[totalStudents].name, "\n")] = '\0';

    printf("Enter Major: ");
    fgets(students[totalStudents].major, MAJOR_LENGTH, stdin);
    students[totalStudents].major[strcspn(students[totalStudents].major, "\n")] = '\0';

    while (1)
    {
        printf("Enter GPA (0.00 - 4.00): ");

        if (scanf("%f", &students[totalStudents].gpa) == 1 &&
            students[totalStudents].gpa >= 0.0 &&
            students[totalStudents].gpa <= 4.0)
        {
            break;
        }

        printf("Invalid GPA.\n");

        while (getchar() != '\n');
    }

    getchar();

    while (1)
    {
        printf("Enter Credits: ");

        if (scanf("%d", &students[totalStudents].credits) == 1 &&
            students[totalStudents].credits >= 0)
        {
            break;
        }

        printf("Invalid credits.\n");

        while (getchar() != '\n');
    }

    getchar();

    totalStudents++;

    printf("\nStudent added successfully!\n");
}

void displayStudents()
{
    int i;

    if (totalStudents == 0)
    {
        printf("\nNo students found.\n");
        return;
    }

    printf("\nSTUDENT LIST\n");

    for (i = 0; i < totalStudents; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("ID      : %d\n", students[i].id);
        printf("Name    : %s\n", students[i].name);
        printf("Major   : %s\n", students[i].major);
        printf("GPA     : %.2f\n", students[i].gpa);
        printf("Credits : %d\n", students[i].credits);
    }
}
void searchByID()
{
    int id;
    int i;
    int found = 0;

    while (1)
    {
        printf("\nEnter Student ID: ");

        if (scanf("%d", &id) == 1 && id > 0)
        {
            getchar();
            break;
        }

        printf("Invalid input.\n");

        while (getchar() != '\n');
    }

    for (i = 0; i < totalStudents; i++)
    {
        if (students[i].id == id)
        {
            printf("\nStudent Found!\n");
            printf("ID      : %d\n", students[i].id);
            printf("Name    : %s\n", students[i].name);
            printf("Major   : %s\n", students[i].major);
            printf("GPA     : %.2f\n", students[i].gpa);
            printf("Credits : %d\n", students[i].credits);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found.\n");
    }
}

void searchByGPA()
{
    float minimumGPA;
    int i;
    int found = 0;

    while (1)
    {
        printf("\nEnter Minimum GPA: ");

        if (scanf("%f", &minimumGPA) == 1 &&
            minimumGPA >= 0.0 &&
            minimumGPA <= 4.0)
        {
            getchar();
            break;
        }

        printf("Invalid GPA.\n");

        while (getchar() != '\n');
    }

    printf("\nStudents with GPA >= %.2f\n", minimumGPA);

    for (i = 0; i < totalStudents; i++)
    {
        if (students[i].gpa >= minimumGPA)
        {
            printf("ID      : %d\n", students[i].id);
            printf("Name    : %s\n", students[i].name);
            printf("Major   : %s\n", students[i].major);
            printf("GPA     : %.2f\n", students[i].gpa);
            printf("Credits : %d\n", students[i].credits);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nNo students found.\n");
    }
}

void searchByMajor()
{
    char major[MAJOR_LENGTH];
    int i;
    int found = 0;

    printf("\nEnter Major: ");
    fgets(major, MAJOR_LENGTH, stdin);
    major[strcspn(major, "\n")] = '\0';

    printf("\nStudents in %s\n", major);

    for (i = 0; i < totalStudents; i++)
    {
        if (strcmp(students[i].major, major) == 0)
        {
            printf("ID      : %d\n", students[i].id);
            printf("Name    : %s\n", students[i].name);
            printf("Major   : %s\n", students[i].major);
            printf("GPA     : %.2f\n", students[i].gpa);
            printf("Credits : %d\n", students[i].credits);

            found++;
        }
    }

    printf("\nTotal Students: %d\n", found);

    if (found == 0)
    {
        printf("No students found in this major.\n");
    }
}
