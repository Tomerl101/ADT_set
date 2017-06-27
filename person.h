#ifndef _PERSON_H
#define _PERSON_H

#include "date.h"

/* A structure that represents a Student.
/* Each Student keeps hold name, id and a pointer to a structure Date */
typedef struct _Student
{
    char* name;
    char* id;
    Date* date;
}Student;

/*Initialize the Student.Save pointers to functions. If fails, return NULL*/
Student* CreateNewStudent(char* name, char* id, int day, int month, int year);

/*print student info*/
void printStud(Student* stud);

#endif // _PERSON_H
