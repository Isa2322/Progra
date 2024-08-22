#include "header.h"

void lote_de_pruebas(tpila* pila1, tpila* pila2)
{
    int i;

    for(i=0; i<=9; i++)
    {
        apilar_pila(pila1, &i, sizeof(int));
    }

    for(i=0; i<=9; i++)
    {
        apilar_pila(pila2, &i, sizeof(int));
    }
}
