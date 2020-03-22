#include <stdio.h>
#include <stdlib.h>

void VisualizzaDimensione()
{
    printf(" --- Tipi base --- \n");
    printf("sizeof(int)=%ld\n", sizeof(int)*8);
    printf("sizeof(long long)=%ld\n", sizeof(long long)*8);

    printf("\n\n --- Tipi puntatore --- \n");
    printf("sizeof(int*)=%ld\n", sizeof(int*)*8);
    printf("sizeof(long long*)=%ld\n", sizeof(long long*)*8);
}

// FUNZIONE ERRATA, MOLTO PERICOLOSA
int*  RitornaPuntatore(int x, int y)
{
    int sum;
    int* p;

    sum = x + y;

    p=&sum;

    //p= (int*) malloc(sizeof(int));

    return p; // ORRIBILE ... ERESIA
}


void Puntatori()
{
    int a = 712978;// variabile intera nel range [-2147483648; 2147483647]
                   // in esadecimale è 00 0A E1 12, considerando tutti e 4 byte
                   // che la compongono

    char ch = 'A';
    int* p; // variabile puntatore ad interi relativi di 32 bit
    char* p2;

    // il puntatore è una variabile che continene un indirizzo

    VisualizzaDimensione();

    printf(" a = %d \n",a );

    p = &a; // p punta ad a (cioè contiene l'indirizzo RAM di a)

    (*p) = -23;

    printf(" a = %d \n",a );

    p = RitornaPuntatore(4,7);

    printf("\n somma = %d", (*p));
}

void ByteAByte(int x)
{
    int i;
    char* p;

    p=(char*)&x; // prendo l'indirizzo di a
                 // ma lo considero come indirizzo di char

    for(i=0; i<sizeof(int); i++)
    {
        printf("\n byte %d = %c", i, (*p));
        p++; // punta al prossima al
    }
}

void Malloc()
{
    // c'è una porzione di RAM detta HEAP, dove posso
    // volontariamente creare e distruggere variabili
    int* p;

    p = (int*) malloc(sizeof(int)); // allocazione dinamica

    (*p) = 10;

    free(p); // ==> dimenticarlo causa la "memory leak"
}

int main()
{

   Puntatori();

   //int x = -1;
   //ByteAByte(x);

   //Malloc();

    return 0;
}
