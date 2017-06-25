#ifndef _DATE_H
#define _DATE_H


typedef struct Date
{
    int day;
    int month;
    int year;
}Date;

Date* createDate(int day, int month, int year);

void printDate(Date* date);

#endif // _DATE_H
