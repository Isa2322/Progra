#include "header.h"

void hola_v(char* cad)
{
    if(*cad!='\0')
    {
        printf("%c\n",*cad);
        return hola_v(cad+1);
    }
}

void hola_v_inv(char *cad)
{

    if(*(cad+1)!='\0')
    {
        hola_v_inv(cad+1);
    }

    printf("%c\n",*cad);
}

void hola_3(char *cad)
{
    if(*cad!='\0')
    {
        printf("%s\n",cad);
        hola_3(cad+1);
    }
}

void hola_4(char *cad)
{
    if(*cad!='\0')
    {
        hola_4(cad+1);
        printf("%s\n",cad);
    }
}
