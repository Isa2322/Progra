#include "header.h"

char* invertir_frase(char* frase)
{
    char *ref;
    char *pun;
    char *finp;

    ref=frase;
    finp=frase;

    while(*finp!='\0')
    {
        pun=buscar_prox_pal_punt(finp,&finp);
        pun=invertir_palabra(pun,finp);
        finp++;

    }

    return ref;
}
