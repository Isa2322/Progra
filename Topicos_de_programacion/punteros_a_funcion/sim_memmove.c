#include "header.h"

void* sim_memmove(void* destino, const void* origen, int tam_total)
{
    int i;
    char *copia;

    copia=(char*)malloc(tam_total);

    if(copia==NULL)
        exit(1);

    for(i=0;i<tam_total;i++)
    {
        *copia=*(char*)origen;
        copia++;
        (char*)origen++;
    }

    copia-=tam_total;

    for(i=0;i<tam_total;i++)
    {
        *(char*)destino=*copia;
        (char*)destino++;
        copia++;
    }

    return destino;
}
