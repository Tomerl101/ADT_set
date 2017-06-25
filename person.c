#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Person* CreateNewPerson(char* name, char* id, int day, int month, int year)
{
    Person* newPerson = (Person*)malloc(sizeof(Person));
    if(newPerson == NULL)
        return NULL;
    newPerson->name = strdup(name);
    if(name == NULL)
        return NULL;
    newPerson->id = strdup(id);
    if(name == NULL)
        return NULL;
    newPerson->date = createDate(day, month, year);
    if(name == NULL)
        return NULL;
    return newPerson;
}
