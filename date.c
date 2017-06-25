#include <stdio.h>
#include <stdlib.h>
#include "date.h"

Date* createDate(int day, int month, int year)
{
    Date* date = (Date*) malloc (sizeof(Date));
    if(date == NULL)
        return NULL;

    date->day = day;
    date->month = month;
    date->year = year;

    return date;
}



void printDate(Date* date)
{
    printf("%d/", date->day);
    printf("%d/", date->month);
    printf("%d\n", date->year);

    return;
}
