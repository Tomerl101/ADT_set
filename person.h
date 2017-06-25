#ifndef _PERSON_H
#define _PERSON_H

#include "date.h"

typedef struct Person
{
    char* name;
    char* id;
    Date* date;
}Person;

Person* CreateNewPerson(char* name, char* id, int day, int month, int year);

#endif // _PERSON_H
