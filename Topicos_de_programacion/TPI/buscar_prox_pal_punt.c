#include "header.h"

char* buscar_prox_pal_punt(char* frase, char**finp)
{
    char *pal;

    while(*frase==' ' || *frase=='.' || *frase==',')
        frase++;

    if(*frase=='\0')
    {
        *finp=frase;
        return NULL;
    }

    pal=frase;

    while(*frase!=' ' && *frase!='\0' && *frase!='.' && *frase!=',')
    {
        frase++;
    }

    *finp=frase-1;

    return pal;
}
