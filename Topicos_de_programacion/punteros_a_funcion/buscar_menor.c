#include "header.h"

void* buscar_menor(void *vec, int tam, int ce, int(*comparar)(const void*, const void*))
{
    void *menor=vec;
    int i;

    for(i=0; i<ce; i++)
    {
        vec+=tam;
        if((comparar(vec,menor))<0)
            menor=vec;
    }

    return menor;
}
