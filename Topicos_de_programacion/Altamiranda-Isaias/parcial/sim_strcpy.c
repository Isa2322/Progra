#include "header.h"

char* sim_strcat(char* dest, char* copia)
{
    char *inic=dest;

    while(*dest!='\0')
    {
        dest++;
    }

    while(*copia!='\0')
    {
        *dest=*copia;
        dest++;
        copia++;
    }

    *dest=*copia;

    return inic;
}
