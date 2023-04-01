#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "student.h"

void assignFileHeading();

short checkFileExists();

void addStudentInfo(Student student);

void searchStudentInfo(char rollNo[]);

void modifyStudentInfo(char rollNo[], Mode mode, void (*modify)(Student *));

void updateStudentInfo(Student *student);

void displayOptions();

#endif