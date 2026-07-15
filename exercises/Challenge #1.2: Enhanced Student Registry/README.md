# Enhanced Student Registry

## Description

This project is an enhanced version of the Student Registry program. It stores student records and saves them to a file so the data is still available when the program is opened again. The program uses file handling and separates the code into multiple files using a header file.

## Features

- Add a student
- Display all students
- Search by Student ID
- Find students by GPA
- Find students by Major
- Save student records to a file
- Load saved records when the program starts

## Project Files

- `student_registry.h` - Function declarations, constants, and Student structure
- `student_registry.c` - Program functions and file handling
- `main.c` - Menu and user interaction
- `Makefile` - Build instructions
- `students.dat` - Stores student records (created automatically)

## Data Structure

The program uses a `Student` structure to keep all student information together.

```c
typedef struct
{
    int id;
    char name[100];
    char major[50];
    float gpa;
    int credits;
} Student;
```

Using a structure makes the program easier to organize and manage compared to using separate arrays.

## File Format

The program uses a **text file** (`students.dat`).

Example:

```
1001|Alice Johnson|Computer Science|3.80|90
1002|John Smith|Engineering|3.50|75
```

A text file was chosen because it is easy to read, edit, and debug.

## How to Compile

Using Makefile:

```bash
make
```

or compile manually:

```bash
gcc -c student_registry.c
gcc -c main.c
gcc student_registry.o main.o -o student_registry
```

## How to Run

Using Makefile:

```bash
make run
```

or run manually:

```bash
./student_registry
```

## Test Cases

I tested the following:

- Program starts even when `students.dat` does not exist.
- Added several students successfully.
- Displayed all student records.
- Searched using Student ID.
- Searched students by GPA.
- Searched students by Major.
- Saved student records before exiting.
- Reopened the program and confirmed that the saved records were loaded correctly.

## Design Decisions

- Used a structure to store student information.
- Used separate files to organize the project.
- Used text file storage because it is simple and easy to check.
- Added input validation for menu choices, IDs, GPA, and credits to avoid invalid input.

## Author

Student Project for Module 12 - Enhanced Student Registry  
University of San Jose-Recoletos
