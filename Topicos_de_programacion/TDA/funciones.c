#include "header.h"

t_vector crear_vector(int tam, unsigned tam_tipo)
{
    t_vector vec;

    vec.dir_inic=calloc(tam,tam_tipo);
    vec.tam=tam;
    vec.tam_tipo=tam_tipo;
    vec.ce=0;

    return vec;
}

void eliminar_vector(t_vector *vec)
{
    free(vec->dir_inic);
}

void cargar_vector(t_vector *vec,void(*tipo)(t_vector*))
{
    int i, ce;

    printf("Ingrese la cantidad de elementos a cargar\n");
    fflush(stdin);
    scanf("%d",&ce);

    if(vec->tam<ce)
        return;

    for(i=1;<=ce;i++)
    {
        tipo(vec);
    }


}

