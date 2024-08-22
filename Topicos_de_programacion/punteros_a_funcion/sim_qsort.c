#include "header.h"

void sim_qsort(void *vec, int tam, int ce, int(*comparar)(const void*, const void*))
{
    void *menor;
    int i;

    if(ce==0)
        return;

    for(i=0;i<ce-1;i++)
    {
        menor=buscar_menor(vec,tam,ce-i,comparar);

        if(vec!=menor)
            intercambio(vec,menor,tam);

        vec+=tam;
    }
}
