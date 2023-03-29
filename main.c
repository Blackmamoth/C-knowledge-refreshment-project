#include "headers/management.h"

void addStudent();
void searchStudent();
void deleteStudent();

int main()
{
    unsigned short option;
    while (option != 5)
    {
        displayOptions();
        printf("Choose an option between (1-5): ");
        scanf("%hu", &option);
        switch (option)
        {
        case 1:
            addStudent();
            break;
        case 2:
            searchStudent();
            break;
        case 3:
            puts("Option 3 to be implemented");
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            puts("BYE!!!");
            break;
        default:
            printf("Invalid option: %hu.\n", option);
            break;
        }
    }

    return 0;
}

void addStudent()
{
    Student student;
    getchar();
    printf("Enter student's name: ");
    fgets(student.name, 100, stdin);
    student.name[strcspn(student.name, "\n")] = '\0';
    printf("Enter student's age: ");
    scanf("%hu", &student.age);
    printf("Enter student's roll no: ");
    scanf("%hu", &student.rollNo);
    printf("Enter student's GPA: ");
    scanf("%lf", &student.GPA);
    addStudentInfo(student);
}

void searchStudent()
{
    char rollNo[5];
    getchar();
    printf("Enter student's roll no: ");
    fgets(rollNo, 5, stdin);
    rollNo[strcspn(rollNo, "\n")] = '\0';
    searchStudentInfo(rollNo);
}

void deleteStudent()
{
    char rollNo[5];
    getchar();
    printf("Enter student's roll no: ");
    fgets(rollNo, 5, stdin);
    rollNo[strcspn(rollNo, "\n")] = '\0';
    deleteStudentInfo(rollNo);
}