#include "header.h"

char* invertir_palabra(char* inic, char* fin)
{
    char aux;
    char *ref;

    ref=inic;

    while(*inic==' ')
        inic++;

    if(*inic=='\0')
        return NULL;

    while(inic!=fin && inic<fin)
    {
        aux=*inic;
        *inic=*fin;
        *fin=aux;

        inic++;
        fin--;
    }

    return ref;
}
