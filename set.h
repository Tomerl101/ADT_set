
#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

/*ADT of generic Set*/
typedef struct set_t* Set;
typedef struct student* Stud;
typedef void* Elem;

/*pointer to function declaration*/
typedef Elem (*copy_fnc) (Elem);
typedef void (*free_fnc) (Elem);
typedef int (*compare_fnc) (Elem,Elem);

/*possible return values*/
typedef enum {Fail, Success} Result ;

/*/* Initialize the Set. Sets the set maximal capacity to max_size. Save
pointers to functions. If fails, return NULL*/
Set setCreate(int setSize,copy_fnc cpy, free_fnc fre, compare_fnc cmp);

/* Insert a copy of the element to the top of the set.
Fails if s == NULL, or elm == NULL or if the set is full. */
Result Insert (Set mySet, Elem element);

/* Removes the element at the top of the set.
Fails if s == NULL or if the set is empty. */
Result pop(Set mySet);

/*Remove the element at the given index of the set.
Fails if mySet == NULL or if the set is empty*/
Result removeByIndex (Set mySet, int index);

/*retrieve the element at the given index of the set.
Fails if mySet == NULL or if the set is empty*/
Result getByIndex(Set mySet, int index, Elem* returnVal);

/* Releases all the resources of the set */
void destroy (Set s);
void printset(Set s);

#endif // SET_H_INCLUDED
