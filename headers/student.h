#ifndef STUDENT_H
#define STUDENT_H

#define FILE_NAME "students.csv"
#define TEMP_FILE_NAME "tempFile.csv"
#define FILE_HEADING "NAME, AGE, ROLL NO, GPA"
#define MAX_LINE_LENGTH 1024
#define MAX_NAME_LENGTH 100

typedef struct
{
    char name[MAX_NAME_LENGTH];
    unsigned short age;
    unsigned short rollNo;
    double GPA;
} Student;

typedef enum
{
    UPDATE_MODE,
    DELETE_MODE
} Mode;

#endif