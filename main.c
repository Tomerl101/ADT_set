#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

Elem copyDouble(Elem x){
    int* y;
    y=(int*)malloc(sizeof(int));
    y=(int*) x;
    return y;
}

Elem copyChar(Elem x){
    char* y;
    y=(char*)malloc(sizeof(char));
    y=(char*) x;
    return y;
}

int compDouble(Elem x, Elem y){
    if(*(double*)x==(*(double*)y))
        return 1;
    return 0;
}

int compChar(Elem x, Elem y){
    if(*(char*)x==(*(char*)y))
        return 1;
    return 0;
}

void frees(Elem x){
    free(x);
}

int main()
{
    Elem temp = NULL;
    Set s=setCreate(5,copyDouble,frees,compDouble);
    if(s == NULL)
        return 0;

    Set sChar = setCreate(5,copyChar,frees,compChar);
    if(sChar == NULL)
        return 0;


    char x1='a' ,y1='b' ,z1= 't';
    int x=4,y=5,z=6;

    Insert(s,&x);
    Insert(s,&y);
    Insert(s,&z);
    printsetDouble(s);

    Insert(sChar,x1);
    Insert(sChar,y1);
    Insert(sChar,z1);

    int i=3;


  while(getByIndex(sChar,i,&temp))
    {
        printf("%c\n",(char*)temp);
        i--;
    }

    printf("CHECK CHECK...");
    //destroy(s);
    destroy(sChar);



    return 0;
}

