
#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

struct student
{
   char name[50];
   long int id;
   long int birthday;
};


typedef struct set_t* Set;
typedef struct student* Stud;
typedef void* Elem;
typedef Elem (*copy_fnc) (Elem);
typedef void (*free_fnc) (Elem);
typedef int (*compare_fnc) (Elem,Elem);
typedef enum {Fail, Success} Result ;
Set setCreate(int setSize,copy_fnc cpy, free_fnc fre, compare_fnc cmp);
Result Insert (Set mySet, Elem element); //insert an element in to the set.
Result pop(Set mySet); //remove the last index from the set.
Result removeByIndex (Set mySet, int index); //remove the item at specified index from set
Result getByIndex(Set mySet, int index, Elem* returnVal);//get the value at the current Index, if invalid returns null.
void destroy (Set s);
void printset(Set s);

#endif // SET_H_INCLUDED
