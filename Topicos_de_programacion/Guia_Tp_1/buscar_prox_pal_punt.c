#include "header.h"

char* buscar_prox_pal_punt(const char* frase, char**finp)
{
    char *pal;

    while(*frase==' ')
        frase++;

    if(*frase=='\0')
        return NULL;

    pal=frase;

    while(*frase!=' ' && *frase!='\0')
    {
        frase++;
    }

    *finp=frase-1;

    return pal;
}
