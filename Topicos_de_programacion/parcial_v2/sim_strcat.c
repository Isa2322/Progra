#include "header.h"

char* sim_strcat(char* destino, char* origen)
{
    char *inic=destino;

    while(*destino!='\0')
    {
        destino++;
    }

    while(*origen!='\0')
    {
        *destino=*origen;
        origen++;
        destino++;
    }

    *destino=*origen;

    return inic;
}
