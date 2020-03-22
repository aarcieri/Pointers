#include <stdio.h>
#include <stdlib.h>

#define DIM 5

void Visualizza(int v[], int size)
{
    int i;

    printf("\n\n----------------\n");

    for(i=0; i<size; i++)
    {
        printf("v[%d] = %d \n", i, v[i]);
    }

}

void Visualizza_2(int* v, int size)
{
    int i;

    printf("\n\n----------------\n");

    for(i=0; i<size; i++)
    {
        printf("v[%d] = %d \n", i, v[i]);
    }

}

int main()
{
    int i;

    int v[DIM];

    int* p;

    for(i=0; i<DIM; i++)
    {
        //v[i] = i;
        (*(v+i)) = i;
    }

    Visualizza(v, DIM);

    p = v; // adesso con p posso accedere agli elementi di v

    // un vettore in realtà non è altro che un puntatore al primo elemento
    // però non posso modificare il suo valore

    // il compilatore "trasforma" v[i] con (*(v+i))

    // (*(p+1))
    p[1] = 50; // ATTENZIONE a quello che vuol dire !!!

    Visualizza_2(v, DIM);

    return 0;
}
