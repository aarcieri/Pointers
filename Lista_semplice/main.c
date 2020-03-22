#include <stdio.h>
#include <stdlib.h>  // contiene la definizione di NULL
#include <string.h>
#include <stdbool.h> // per aver a disposizione il tipo bool
#include "List.h"

#ifdef _WIN32
    #define CLEAR() system("cls");
#endif // _WIN32

#ifdef __linux__
    #define CLEAR() system("clear");
#endif // __linux__

void Test_Allocazione()
{

     int i;
    persona* lista;
    persona* cpy;

    lista = malloc(sizeof(persona));

    if(lista==NULL) return; // stop prematuro del programma

    lista->eta=32;

    strcpy(lista->nome, "Gino");
    lista->next=NULL;

    printf("NULL vale %ld\n", (long int)NULL);

    i = (long int)NULL + 2;

    printf("i vale %d\n", i);

    printf("1. x= %d\n", lista->eta);
    printf("1. nome = %s\n", lista->nome);

    cpy=lista;
    free(lista);

    if(lista==cpy)
    {
        printf("2. x= %d\n", cpy->eta);
        printf("2. nome = %s\n", cpy->nome);
    }

    lista = NULL;
}

bool Inserisci(persona** lista)
{
    char nome[MAX_STRING];
    int eta;

    printf("Inserisci i dati della nuova persona \n");
    printf("Nome: ");
    scanf("%s", nome);
    printf("eta: ");
    scanf("%d", &eta);

    return Create(lista, nome, eta);
}

bool Cancella(persona** lista)
{
    char nome[MAX_STRING];

    printf("Inserisci i dati della persona da ELIMINARE \n");
    printf("Nome: ");
    scanf("%s", nome);


    return Delete(lista, nome);
}

bool Cerca(persona* lista)
{
    char nome[MAX_STRING];
    persona* p;

    printf("Inserisci i dati della persona da CERCARE \n");
    printf("Nome: ");
    scanf("%s", nome);


    p = Read(lista, nome);

    if(p==NULL) return false;

    printf(" ---- PERSONA ---\n");
    printf("Nome: %s\n", p->nome);
    printf("Eta: %d", p->eta);

    return true;
}

void VisualizzaTutto(persona* lista)
{
    ListIterator it = First(lista);

    printf(" --- ELENCO ---\n");

    while(it)
    {
        printf("Nome: %s; eta: %d \n", it->nome, it->eta);

        it = MoveNext(it);
    }

    printf(" --------------\n");
}

void UserInterface()
{
    int c;
    bool result;
    persona* lista;
    lista = NULL;

    do
    {
        printf(" --- MENU' ---       \n\n");
        printf(" 1: Inserisci        \n");
        printf(" 2: Cancella         \n");
        printf(" 3: Cerca            \n");
        printf(" 4: Visualizza Tutto \n");
        printf(" 0: ESCI             \n");

        printf(" Scelta --> ");
        scanf("%d", &c);

        result = true;

        switch(c)
        {
            case 1:
                    result = Inserisci(&lista);
                break;
            case 2:
                    result = Cancella(&lista);
                break;
            case 3:
                    result = Cerca(lista);
                break;
            case 4:
                    VisualizzaTutto(lista);
                break;
            case 0:
                return;
            default:
                printf("Scelta ERRATA \n");
        }

        if(!result) printf("Operazione NON possibile\n\n");

        printf("____ Press ENTER to continue ____");
        while(getchar()!='\n'); // clean stdin, prelevando l'ultimo ENTER premuto
        getchar(); // wait for ENTER

        CLEAR();

    }while(c!=0);
}


int main()
{
    UserInterface();

    return 0;
}
