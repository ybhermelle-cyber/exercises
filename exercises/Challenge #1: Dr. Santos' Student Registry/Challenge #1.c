#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define NAME_LENGTH 50
#define MAJOR_LENGTH 50

int studentID[MAX_STUDENTS];
char studentName[MAX_STUDENTS][NAME_LENGTH];
char studentMajor[MAX_STUDENTS][MAJOR_LENGTH];
float studentGPA[MAX_STUDENTS];
int studentCredits[MAX_STUDENTS];

int totalStudents = 0;

void addStudent();
void displayStudents();
void searchByID();
void searchByGPA();
void searchByMajor();

int main()
{
    int choice;

    do
    {
        printf("DR. SANTOS STUDENT REGISTRY\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search by Student ID\n");
        printf("4. Search by GPA\n");
        printf("5. Search by Major\n");
        printf("6. Exit\n");
		
		while (1)
		{
    		printf("Enter your choice: ");

    		if (scanf("%d", &choice) == 1 && choice >= 1 && choice <= 6)
    	{
        getchar();
        break;
    }

    printf("Invalid input.\n");

    while (getchar() != '\n');
	}
	
        switch(choice)
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
                printf("\nThank you for using the Student Registry!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while(choice != 6);

    return 0;
}

void addStudent()
{
    if(totalStudents >= MAX_STUDENTS)
    {
        printf("\nStudent list is full!\n");
        return;
    }

	while (1)
	{
    printf("\nEnter Student ID: ");

    if (scanf("%d", &studentID[totalStudents]) == 1 &&
        studentID[totalStudents] > 0)
    {
        getchar();
        break;
    }

    printf("Invalid!\n");

    while (getchar() != '\n');
	}

    printf("Enter Student Name: ");
    fgets(studentName[totalStudents], NAME_LENGTH, stdin);
    studentName[totalStudents][strcspn(studentName[totalStudents], "\n")] = '\0';

    printf("Enter Major: ");
    fgets(studentMajor[totalStudents], MAJOR_LENGTH, stdin);
    studentMajor[totalStudents][strcspn(studentMajor[totalStudents], "\n")] = '\0';

	while (1)
	{
    printf("Enter GPA: ");

    if (scanf("%f", &studentGPA[totalStudents]) == 1 &&
        studentGPA[totalStudents] >= 0.0 &&
        studentGPA[totalStudents] <= 4.0)
    {
        break;
    }

    printf("Invalid.\n");

    while (getchar() != '\n');
	}

	getchar();

	while (1)
	{
    printf("Enter Credits: ");

    if (scanf("%d", &studentCredits[totalStudents]) == 1 &&
        studentCredits[totalStudents] >= 0)
    {
        break;
    }

    printf("Invalid!\n");

    while (getchar() != '\n');
	}

	getchar();

    totalStudents++;

    printf("\nStudent added successfully!\n");
}

void displayStudents()
{
    int i;

    if(totalStudents == 0)
    {
        printf("\nNo students found.\n");
        return;
    }

    printf("\nSTUDENT LIST\n");

    for(i = 0; i < totalStudents; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("ID      : %d\n", studentID[i]);
        printf("Name    : %s\n", studentName[i]);
        printf("Major   : %s\n", studentMajor[i]);
        printf("GPA     : %.2f\n", studentGPA[i]);
        printf("Credits : %d\n", studentCredits[i]);
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
        break;
    }

    printf("Invalid!\n");

    while (getchar() != '\n');
	}		

getchar();

    for(i = 0; i < totalStudents; i++)
    {
        if(studentID[i] == id)
        {
            printf("\nStudent Found!\n");
            printf("ID      : %d\n", studentID[i]);
            printf("Name    : %s\n", studentName[i]);
            printf("Major   : %s\n", studentMajor[i]);
            printf("GPA     : %.2f\n", studentGPA[i]);
            printf("Credits : %d\n", studentCredits[i]);

            found = 1;
            break;
        }
    }

    if(found == 0)
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
    printf("\nEnter GPA: ");

    if (scanf("%f", &minimumGPA) == 1 &&
        minimumGPA >= 0.0 &&
        minimumGPA <= 4.0)
    {
        break;
    }

    printf("Invalid.\n");

    while (getchar() != '\n');
	}

getchar();

    printf("\nStudents with GPA >= %.2f\n", minimumGPA);

    for(i = 0; i < totalStudents; i++)
    {
        if(studentGPA[i] >= minimumGPA)
        {
            printf("ID    : %d\n", studentID[i]);
            printf("Name  : %s\n", studentName[i]);
            printf("Major : %s\n", studentMajor[i]);
            printf("GPA   : %.2f\n", studentGPA[i]);

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("\nNo students found.\n");
    }
}

void searchByMajor()
{
    char major[MAJOR_LENGTH];
    int i;
    int count = 0;

    printf("\nEnter Major: ");
    fgets(major, MAJOR_LENGTH, stdin);
    major[strcspn(major, "\n")] = '\0';

    printf("\nStudents in %s\n", major);

    for(i = 0; i < totalStudents; i++)
    {
        if(strcmp(studentMajor[i], major) == 0)
        {
            printf("ID   : %d\n", studentID[i]);
            printf("Name : %s\n", studentName[i]);
            printf("GPA  : %.2f\n", studentGPA[i]);

            count++;
        }
    }

    printf("\nTotal Students: %d\n", count);

    if(count == 0)
    {
        printf("No students found in this major.\n");
    }
}
