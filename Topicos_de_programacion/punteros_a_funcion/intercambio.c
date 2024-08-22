#include "header.h"

void intercambio(void* elem1, void* elem2, int tam)
{
    void* aux;

    aux=malloc(tam);
    memcpy(aux,elem1,tam);
    memcpy(elem1,elem2,tam);
    memcpy(elem2,aux,tam);
    free(aux);
}
