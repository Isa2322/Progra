#ifndef HEADER_LISTA_CIRCULAR_H_INCLUDED
#define HEADER_LISTA_CIRCULAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIN_MEM 1
#define VACIA 2
#define INSUFICIENTES_ELEMENTOS 3
#define TODO_OK 0
#define MINIMO( X , Y ) ((X)<(Y)?(X):(Y))

typedef struct s_nodo
{
    void *info;
    unsigned tam_info;
    struct s_nodo *sig;
} t_nodo;

typedef t_nodo *t_lista;

#endif // HEADER_LISTA_CIRCULAR_H_INCLUDED
