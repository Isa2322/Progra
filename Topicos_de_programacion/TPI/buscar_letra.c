#include "header.h"

char* buscar_letra(char* cadena, char letra)
{
    char *elem=NULL;
    char *aux=cadena;

    while(*aux!=letra && *aux!='\0')
    {
        aux++;
    }

    if(*aux==letra)
        elem=aux;

    return elem;
}
