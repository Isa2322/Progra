#include "header.h"

void* sim_memcopy(void* destino, const void* origen, int tam_total)
{
    char aux;
    int i;

    for(i=0;i<tam_total;i++)
    {
        aux=*(char*)origen;
        origen++;
        *(char*)destino=aux;
        destino++;
    }

    return (void*)destino;
}
