#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int ce;
    int tam;
    int tam_tipo;
    void* dir_inic;
}t_vector;


t_vector crear_vector(int , unsigned );
void eliminar_vector(t_vector *);

void cargar_vector(t_vector*, void(*tipo)(t_vector*));
void tipo_int(t_vector*);


#endif // HEADER_H_INCLUDED
