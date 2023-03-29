#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <stdio.h>
#include <string.h>
#include "student.h"

#define FILE_NAME "students.csv"
#define TEMP_FILE_NAME "tempFile.csv"
#define FILE_HEADING "NAME ,AGE ,ROLL NO ,GPA"
#define MAX_LINE_LENGTH 1024

void assignFileHeading();

short checkFileExists();

void addStudentInfo(Student student);

void searchStudentInfo(char rollNo[]);

void deleteStudentInfo(char rollNo[]);

void displayOptions();

#endif