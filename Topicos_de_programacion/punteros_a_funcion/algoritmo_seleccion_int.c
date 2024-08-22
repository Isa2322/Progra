#include "header.h"

int* algoritmo_seleccion_int(int*vec, int tam)
{
    int *pos1=vec, *pos2;
    int i, j, aux;

    for(i=0; i<tam; i++)
    {
        pos2=pos1+1;

        for(j=i+1; j<tam; j++)
        {
            if(*pos2<*pos1)
            {
                aux=*pos1;
                *pos1=*pos2;
                *pos2=aux;
            }

            pos2++;
        }

        pos1++;
    }

    return vec;
}
