#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME_LENGTH 100

typedef struct
{
    char name[MAX_NAME_LENGTH];
    unsigned short age;
    unsigned short rollNo;
    double GPA;
} Student;

#endif