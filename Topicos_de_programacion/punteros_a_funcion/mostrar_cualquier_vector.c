#include "header.h"

void mostrar_cualquier_vector(const void* vec, int tam_tipo, int tamanio, void mostrar(const void*))
{
    int i;

    for(i=0;i<tamanio;i++)
    {
        mostrar(vec);
        vec+=tam_tipo;
        //printf("\n");
    }
}
