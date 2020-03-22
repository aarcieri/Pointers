#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdbool.h>

//#include "List.c"

#define MAX_STRING 30

typedef struct st_persona
{
    char nome[MAX_STRING];
    int eta;
    struct st_persona* next;// puntatore ad una "struct st_persona"

} persona;

typedef persona* ListIterator;

ListIterator First(persona* l);
ListIterator MoveNext(ListIterator it);

bool Create(persona** lista, char nome[], int eta);
bool Delete(persona** lista, char nome[]);
persona* Read(persona* lista, char nome[]);


#endif // LIST_H_INCLUDED
