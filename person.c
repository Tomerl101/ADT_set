#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Student* CreateNewStudent(char* name, char* id, int day, int month, int year)
{
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if(newStudent == NULL)
        return NULL;
    newStudent->name = strdup(name);
    if(name == NULL)
        return NULL;
    newStudent->id = strdup(id);
    if(name == NULL)
        return NULL;
    newStudent->date = createDate(day, month, year);
    if(name == NULL)
        return NULL;
    return newStudent;
}

void printStud(Student* stud)
{
    printf("name: %s \n", stud->name);
    printf("id: %s \n", stud->id);
    printf("birthday: ");
    printDate(stud->date);
}
