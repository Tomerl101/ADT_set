#include <stdio.h>
#include <stdlib.h>
#include "set.h"

struct set_t
{
    Elem* array ;
    int top ;
    int maxCapacity ;
    copy_fnc copfunc;
    free_fnc freefunc;
    compare_fnc compfunc;
};

Set setCreate(int setSize,copy_fnc cpy, free_fnc fre, compare_fnc cmp)
{
    Set s = NULL;
    if (setSize <=0 || fre==NULL ||cpy == NULL || cmp==NULL )
        return NULL ;
    s = (Set) malloc (sizeof(Set)) ;
    if (s== NULL)
        return NULL;
    s->array = (Elem*)malloc(setSize*sizeof(Elem)) ;
    if (s->array == NULL)
    {
        free(s) ;
        return NULL ;
    }
    s->top = 0;
    s->maxCapacity = setSize;
    s->copfunc=cpy;
    s->freefunc=fre;
    s->compfunc=cmp;

    return s ;
}

Result Insert (Set mySet, Elem element)
 {
    int i;
    Elem tmpelement = NULL;
    if ( mySet == NULL || element == NULL || mySet->top >= mySet->maxCapacity )
        return Fail;

    /*for(i=0;i<mySet->top;i++)
    {
        if(mySet->compfunc(element,mySet->array[i]))
            return Fail;
    }*/
    tmpelement=mySet->copfunc(element);
    if (tmpelement == NULL)
        return Fail ;
    mySet->array[mySet->top] = tmpelement;
    mySet->top++ ;
    return Success ;
}

Result pop(Set mySet)
{
    //Set s;
    if ((mySet == NULL) || (mySet->top == 0))
        return Fail ;

    mySet->top--;
    mySet->freefunc(mySet->array[mySet->top]);
    return Success ;
}

Result removeByIndex (Set mySet, int index)
{
    int i = 0 ;
    if ((mySet == NULL) || (index <= 0))
        return Fail ;

   mySet->freefunc(mySet->array[index-1]);

   for(i=index-1; i< mySet->top-1; i++)
   {
       mySet->array[i] = mySet->array[i+1];
   }
    mySet->top--;
    return Success;
}

Result getByIndex(Set mySet, int index, Elem* returnVal)
{
    Elem tmp = NULL;
    if (mySet == NULL || index-1 < 0 || returnVal == NULL)
        return Fail ;
    tmp = mySet->copfunc(mySet->array[index-1]);
    *returnVal = tmp;
    return (tmp == NULL) ? Fail : Success ;
}

void destroy (Set s)
{
    if (s == NULL)
        return;

    while (s->top > 0 && pop(s) == Success) ;
    free(s->array);
    free(s);
}

void printsetDouble(Set s)
{
int i;
for(i=0;i<s->top;i++ )
    {
    printf("%d\n",*((double*)s->array[i]));
    }
}

void printsetChar(Set s)
{
int i;
for(i=0;i<s->top;i++ )
    {
    printf("%c\n",*((char*)s->array[i]));
    }
}

