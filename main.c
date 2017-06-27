#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "person.h"

/* functions that will be used by the ADT */

Elem copyDouble(Elem x){
    double* y;
    if(x == NULL)
        return NULL;

    y=(double*)malloc(sizeof(double));
    if(y == NULL)
        return NULL;
//here we DO NOT! want to change the address of the pointer. just give it the value x point to.
    *y=*(double*) x;
    return y;
}

Elem copyChar(Elem x){
    char* y;
    if(x == NULL)
        return NULL;
    y=(char*)malloc(sizeof(strlen((char*)x)+1));
    if(y == NULL)
        return NULL;
    strcpy(y, (char*)x);
    return y;
}

Elem copyStud(Elem x){
    Student* y = (Student*)x;
    return y;
}

int compDouble(Elem x, Elem y){
    if(y == NULL)
        return 1;
    if(*(double*)x==(*(double*)y))
        return 1;

    return 0;
}

int compChar(Elem x, Elem y){
    int check;
    //printf("%s , %s \n",(char*)x , (char*)y);
    check = strcmp((char*)x, (char*)y);
    if(check == 0)
        return 1;

    return 0;
}

int compStudId(Elem x, Elem y){
    if(y == NULL)
        return 1;

    if(strcmp(((Student*)x)->id ,((Student*)y)->id)==0)
        return 1;

    return 0;
}

void frees(Elem x){
    if(x != NULL)
        free(x);
}

void freeStud(Elem x)
{
  free(((Student*)x)->name );
  free(((Student*)x)->id );
  free(((Student*)x)->date );
  free(x);
}

  /*---------------------------/
 /  M A I N - TOMER & SHOHAM  /
/---------------------------*/

int main()
{
    printf("------------------------\n");
    printf("GENERIC SET PROGRAM\n");
    printf("------------------------\n");
    int i, num, size;
    double data;
    char string[256];
    Elem tmp;
    Student* p1,*p2,*p3;

    Set s = NULL;

menu:
    printf("CHOOSE SET TO CREATE: \n");
    printf("[1].DOUBLE\n[2].STRING\n[3].STUDENTS\n");
    scanf("%d",&num);
    while(num<1 || num>3)
    {
        goto menu;
    }
    printf("CHOOSE THE SIZE OF THE SET: \n");
    scanf("%d",&size);

    switch(num)
    {
    /*create Double Set*/
    case 1:
        s=setCreate(size,copyDouble,frees,compDouble);
        if(s == NULL)
        return 0;
        for(i=0; i<size; i++){
            printf("Enter value:\n");
            scanf("%lf",&data);
            Insert(s,(Elem)&data);}
        /*print the set for testing*/
        printf("SET VALUES:\n");
        printf("{");
        for(i=1; i<=size; i++){
            if(getByIndex(s,i,&tmp)==Success)
                printf("%.2lf,",*(double*)tmp);}
        printf("}\n");
        break;
    /*create String Set*/
    case 2:
        fflush(stdin);
        s=setCreate(size,copyChar,frees,compChar);
        if(s == NULL)
        return 0;
        for(i=0; i<size; i++){
            printf("Enter value:\n");
            //fgets(string,256,stdin);
            gets(string);
            Insert(s,(Elem)string);}
        /*print the set for testing*/
        printf("SET VALUES:\n");
        printf("{");
        for(i=1; i<=size; i++){
            if(getByIndex(s,i,&tmp)==Success)
                printf("%s,",(char*)tmp);}
        printf("}\n");
        break;
    case 3:
        s=setCreate(size,copyStud,freeStud,compStudId);
        if(s == NULL)
            return 0;

        p1 = CreateNewStudent("tomer","123456",13,4,92);
        Insert(s,(Elem)p1);
        p2 = CreateNewStudent("shoham","121212",14,1,95);
        Insert(s,(Elem)p2);
        /*p3 have the same id as p2 therefor it will not added to the set*/
        p3 = CreateNewStudent("gal","121212",13,4,92);
        Insert(s,(Elem)p3);

        /*printing the student set for testing */
        for(i=1; i<=size; i++){
            if(getByIndex(s,i,&tmp)==Success)
                printStud((Student*)tmp);}
        break;
    case 0:
        break;
    default:
        printf("ERROR\n");
    }
    printf("EXIT THE PROGRAM . . . ;");
    destroy(s);
    return 0;
}
/*
                            _        _____ _____ _____
                           (_)      /  ___|  ___|_   _|
  __ _  ___ _ __   ___ _ __ _  ___  \ `--.| |__   | |
 / _` |/ _ \ '_ \ / _ \ '__| |/ __|  `--. \  __|  | |
| (_| |  __/ | | |  __/ |  | | (__  /\__/ / |___  | |
 \__, |\___|_| |_|\___|_|  |_|\___| \____/\____/  \_/
  __/ |
 |___/
*/
