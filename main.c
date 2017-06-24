#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"



Elem copyDouble(Elem x){
    double* y;
    if(x == NULL)
        return NULL;

    y=(double*)malloc(sizeof(double));
    if(y == NULL)
        return NULL;

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

   Stud y=(Stud)malloc(sizeof(struct student));
    if(y == NULL)
        return NULL;

    strcpy(y->name, "tomer");

   /* strcpy(y->name,(Stud)x->name);
    y->id = (Stud)x->id;*/

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
    printf("%s , %s \n",(char*)x , (char*)y);
    check = strcmp((char*)x, (char*)y);
    if(check == 0)
        return 1;

    return 0;
}

int compStudId(Elem x, Elem y){
    if(y == NULL)
        return 1;

    if((Stud)x->id ==(Stud)y->id)
        return 1;

    return 0;
}

void frees(Elem x){
    if(x != NULL)
        free(x);
}

  /*----------/
 /  M A I N  /
/----------*/

int main()
{
    Elem temp = NULL;
    Set s=setCreate(5,copyDouble,frees,compDouble);
    if(s == NULL)
        return 0;

    Set sChar = setCreate(5,copyChar,frees,compChar);
    if(sChar == NULL)
        return 0;

    Set sStud = setCreate(5, copyStud, frees, compStudId);
    if(sStud == NULL)
        return 0;

    char x1[]="Tomer" ,y1[]="Shoham" ,z1[]= "Gal";
    double x= 4.5, y=5.5, z= 6.5;
    Stud stud1 = {"Shoham", 123456, 010194}

    Insert(s,(Elem)&x);
    Insert(s,(Elem)&y);
    Insert(s,(Elem)&z);
    printsetDouble(s);

    Insert(sChar,(Elem)x1);
    Insert(sChar,(Elem)y1);
    Insert(sChar,(Elem)z1);

    Insert(sStud, (Elem)&stud1);

    int i=3;


    destroy(s);
    destroy(sChar);


    return 0;
}

