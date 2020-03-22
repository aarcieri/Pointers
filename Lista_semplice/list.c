#include "List.h"
#include <stdlib.h>  // contiene la definizione di NULL
#include <string.h>
#include <stdbool.h> // per aver a disposizione il tipo bool



// get first element of the List
ListIterator First(persona* l)
{
    return l;
}

// get next element of the List
ListIterator MoveNext(ListIterator it)
{
    if(it==NULL) return NULL;

    return it->next;
}

// funzioni C R U D (Create, Read, Update, Delete)
bool Create(persona** lista, char nome[], int eta)
{
    persona* p;

    p = (persona*) malloc(sizeof(persona));

    if(p==NULL) return false;

    p->next = (struct st_persona*) (*lista); // "inserimento in testa"

   (*lista) = p;

    p->eta = eta;
    strcpy(p->nome, nome);

    return true;
}

bool Delete(persona** lista, char nome[])
{
    persona* precedente;
    persona* attuale;

    if((*lista)==NULL) return false;

    precedente = (*lista);
    attuale    = (*lista);

    while(attuale!=NULL && strcmp(attuale->nome, nome)!=0)
    {
        precedente=attuale;
        attuale = (persona*) attuale->next;
    }

    if(attuale==NULL) return false;

    if(attuale==(*lista)) (*lista)= (persona*) (*lista)->next;
    else precedente->next=attuale->next;

    free(attuale);

    return true;
}

persona* Read(persona* lista, char nome[])
{
    persona* attuale;

    if(lista==NULL) return NULL;

    attuale = lista;

    while(attuale!=NULL && strcmp(attuale->nome, nome)!=0)
    {
        attuale = (persona*) attuale->next; // "attuale->next" equivale a "(*attuale).next"
    }

    if(attuale==NULL) return NULL;

    return attuale;
}
