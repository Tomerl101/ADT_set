#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "person.h"


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

    strcpy(((Stud)y)->name,((Stud)x)->name);
    y->id = ((Stud)x)->id;

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

    if(((Stud)x)->id ==((Stud)y)->id)
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
    int i,size, num = 0;
    double data;
    char string[256];
    Elem tmp;
    Person* p1;
    Person* p2;

    Set s = NULL;
    printf("CHOOSE SET TO CREATE: \n");
    printf("1.DOUBLE\n2.STRING\n3.STUDENTS\n");
    scanf("%d",&num);
    printf("CHOOSE THE SIZE OF THE SET: \n");
    scanf("%d",&size);


    switch(num)
    {
    case 1:
        s=setCreate(size,copyDouble,frees,compDouble);
        if(s == NULL)
        return 0;
        for(i=1; i<=size; i++)
        {
            printf("Enter value:\n");
            scanf("%lf",&data);
            Insert(s,(Elem)&data);
        }
        printf("SET VALUES:\n");
        for(i=1; i<=size; i++)
        {
            getByIndex(s,i,&tmp);
            printf("%.2lf,",*(double*)tmp);
        }
        break;
    case 2:
        fflush(stdin);
        s=setCreate(size,copyChar,frees,compChar);
        if(s == NULL)
        return 0;
        for(i=0; i<size; i++)
        {
            printf("Enter value:\n");
            fgets(string,256,stdin);
            Insert(s,(Elem)string);
        }
        printf("SET VALUES:\n");
        for(i=1; i<=size; i++)
        {
            getByIndex(s,i,&tmp);
            printf("%s,",(char*)tmp);
        }
        break;
    case 3:
        s=setCreate(size,copyStud,frees,compStudId);
        if(s == NULL)
            return 0;
        for(i=0; i<2; i++)
        {
            p1= CreateNewPerson("tomer","123456",13,4,92);
            Insert(s,(Elem)p1);
            p2= CreateNewPerson("shoham","121212",14,1,95);
            Insert(s,(Elem)p2);
        }
        break;
    case 0:
        break;
    default:
        printf("ERROR\n");
    }

    destroy(s);
    return 0;
}

