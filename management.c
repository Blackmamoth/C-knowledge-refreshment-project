#include "headers/management.h"

void assignFileHeading()
{
    FILE *file = fopen(FILE_NAME, "w");
    if (file != NULL)
    {
        fprintf(file, "%s\n", FILE_HEADING);
        fclose(file);
    }
    else
    {
        printf("An error occured while writing to file %s.\n", FILE_NAME);
    }
}

short checkFileExists()
{
    FILE *file;
    if ((file = fopen(FILE_NAME, "r")) != NULL)
    {
        fclose(file);
        return 1;
    }
    else
    {
        return 0;
    }
}

void addStudentInfo(Student student)
{
    if (!checkFileExists())
        assignFileHeading();
    FILE *file;
    if ((file = fopen(FILE_NAME, "a")) != NULL)
    {
        fprintf(file, "%s , %hu , %hu , %.1f\n", student.name, student.age, student.rollNo, student.GPA);
        fclose(file);
        printf("\n***********\n");
        printf("Student info added successfully!\n");
        printf("\n***********\n");
    }
    else
    {
        fprintf(stderr, "An Error occured while writing to file %s.\n", FILE_NAME);
    }
}

void searchStudentInfo(char rollNo[])
{
    char line[MAX_LINE_LENGTH];
    if (!checkFileExists())
    {
        fprintf(stderr, "ERROR: File %s does not exist.", FILE_NAME);
        return;
    }
    FILE *file;
    if ((file = fopen(FILE_NAME, "r")) != NULL)
    {
        while (fgets(line, MAX_LINE_LENGTH, file))
        {
            line[strcspn(line, "\n")] = '\0';
            if (strstr(line, rollNo))
            {
                printf("\n***********\n");
                printf("%s\n", line);
                printf("\n***********\n");
            }
        }
    }
    else
        fprintf(stderr, "An Error occured while writing to file %s.\n", FILE_NAME);
}

void displayOptions()
{
    puts("1. Add student info");
    puts("2. Search student");
    puts("3. Update student info");
    puts("4. Delete student info");
    puts("5. EXIT");
    puts("\n");
}