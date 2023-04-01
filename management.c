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
        fprintf(file, "%s ,%hu ,%hu ,%.1f\n", student.name, student.age, student.rollNo, student.GPA);
        fclose(file);
        printf("\n\n***********\n");
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
                printf("\n\n***********\n");
                printf("%s\n", line);
                printf("\n***********\n");
            }
        }
    }
    else
        fprintf(stderr, "An Error occured while writing to file %s.\n", FILE_NAME);
}

void updateStudentInfo(Student *student)
{
    printf("%s , %hu , %hu , %.1f\n", student->name, student->age, student->rollNo, student->GPA);
    char name[MAX_NAME_LENGTH];
    unsigned short age, rollNo;
    double GPA;
    puts("Enter new details for the student.");
    printf("Enter name (press Enter to skip): ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    if (strlen(name) > 1 && !isspace(name[0]))
    {
        name[strcspn(name, "\n")] = '\0';
        strcpy(student->name, name);
    }
    getchar();
    printf("Enter age (enter 0 to skip): ");
    scanf("%hu", &age);
    if (age > 0)
    {
        student->age = age;
    }
    printf("Enter roll no. (enter 0 to skip): ");
    scanf("%hu", &rollNo);
    if (rollNo > 0)
    {
        student->rollNo = rollNo;
    }
    printf("Enter GPA (enter 0 to skip): ");
    scanf("%lf", &GPA);
    if (GPA > 0.0)
    {
        student->GPA = GPA;
    }
    printf("%s , %hu , %hu , %.1f\n", student->name, student->age, student->rollNo, student->GPA);
}

void modifyStudentInfo(char rollNo[], Mode mode, void (*modify)(Student *))
{
    FILE *file;
    FILE *tempFile;
    char line[MAX_LINE_LENGTH];
    int found = 0;
    if (!checkFileExists())
    {
        fprintf(stderr, "ERROR: File %s does not exist.", FILE_NAME);
        return;
    }
    if ((file = fopen(FILE_NAME, "r")) != NULL)
    {
        if ((tempFile = fopen(TEMP_FILE_NAME, "w")))
        {
            while (fgets(line, MAX_LINE_LENGTH, file))
            {
                line[strcspn(line, "\n")] = '\0';

                if (strstr(line, rollNo))
                {
                    Student student;
                    switch (mode)
                    {
                    case UPDATE_MODE:
                        sscanf(line, "%[^,] ,%hu ,%hu ,%lf", student.name, &student.age, &student.rollNo, &student.GPA);
                        modify(&student);
                        fprintf(tempFile, "%s ,%hu ,%hu ,%.1f\n", student.name, student.age, student.rollNo, student.GPA);
                        break;
                    case DELETE_MODE:
                        break;
                    default:
                        break;
                    }
                    found = 1;
                }
                else
                    fprintf(tempFile, "%s\n", line);
            }
            fclose(file);
            fclose(tempFile);
            if (found)
                if (remove(FILE_NAME) != 0)
                    fprintf(stderr, "An error occured while deleting file %s.\n", FILE_NAME);
                else if (rename(TEMP_FILE_NAME, FILE_NAME) != 0)
                    fprintf(stderr, "An error occured while renaming file %s.\n", FILE_NAME);
                else
                {
                    printf("Student info modified successfully!!!\n");
                }
            else
            {
                remove(TEMP_FILE_NAME);
                printf("Student with roll no. %s not found.\n", rollNo);
            }
        }
        else
            fprintf(stderr, "An Error occured while creating temporary file.\n");
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