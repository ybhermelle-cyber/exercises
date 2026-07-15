#ifndef STUDENT_REGISTRY_H
#define STUDENT_REGISTRY_H

#include <stdio.h>

#define MAX_STUDENTS 10
#define NAME_LENGTH 100
#define MAJOR_LENGTH 50
#define FILE_NAME "students.dat"

typedef struct
{
    int id;
    char name[NAME_LENGTH];
    char major[MAJOR_LENGTH];
    float gpa;
    int credits;
} Student;

extern Student students[MAX_STUDENTS];
extern int totalStudents;

void addStudent();
void displayStudents();
void searchByID();
void searchByGPA();
void searchByMajor();

void saveStudentsToFile();
void loadStudentsFromFile();

#endif
