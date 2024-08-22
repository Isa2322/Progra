#include "header.h"

char* invertir_frase(char* frase)
{
    char *ref;
    char *pun;
    char *finp;

    ref=frase;
    finp=frase;

    pun=buscar_prox_pal_punt(finp,&finp);

    while(*finp!='\0')
    {
        pun=invertir_palabra(pun,finp);
        finp++;
        pun=buscar_prox_pal_punt(finp,&finp);

    }

    return ref;
}
