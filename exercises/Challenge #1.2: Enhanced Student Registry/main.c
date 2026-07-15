#include <stdio.h>
#include "student_registry.h"
#include "student_registry_example.c"

int main()
{
    int choice;

    loadStudentsFromFile();

    do
    {
		printf("DR. SANTOS STUDENT REGISTRY\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search by Student ID\n");
        printf("4. Search by GPA\n");
        printf("5. Search by Major\n");
        printf("6. Save & Exit\n");

        while (1)
        {
            printf("Enter your choice: ");

            if (scanf("%d", &choice) == 1 &&
                choice >= 1 &&
                choice <= 6)
            {
                getchar();
                break;
            }

            printf("Invalid input.\n");

            while (getchar() != '\n');
        }

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchByID();
                break;

            case 4:
                searchByGPA();
                break;

            case 5:
                searchByMajor();
                break;

            case 6:
                saveStudentsToFile();
                printf("\nThank you for using the Student Registry!\n");
                break;
        }

    } while (choice != 6);

    return 0;
}
