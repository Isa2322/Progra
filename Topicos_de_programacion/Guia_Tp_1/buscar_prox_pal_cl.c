#include "header.h"

char* buscar_prox_pal_cl(const char * frase, int * cantletras)
{
    char *pal;

    *cantletras=0;

    while(*frase==' ')
        frase++;

    if(*frase=='\0')
        return NULL;

    pal=frase;

    while(*frase!=' ' && *frase!='\0')
    {
        frase++;
        (*cantletras)++;
    }

    return pal;
}
