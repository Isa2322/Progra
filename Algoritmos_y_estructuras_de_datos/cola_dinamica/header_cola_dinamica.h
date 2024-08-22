#ifndef HEADER_COLA_DINAMICA_H_INCLUDED
#define HEADER_COLA_DINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 1
#define SIN_MEM 2
#define COLA_VACIA 3
#define MINIMO(x,y) ((x)<(y)?(x):(y))



typedef struct s_nodo
{
    unsigned tam;
    void* elem;
    struct s_nodo* sig;
}t_nodo;

typedef struct
{
    t_nodo* pri;
    t_nodo* ult;
} t_cola;


void crear_cola(t_cola* cola);
int cola_vacia(const t_cola* cola);
int cola_llena(const t_cola* cola, unsigned tam);
int poner_en_cola(t_cola* cola,const void* elemento, unsigned tam);
int mostrar_primero(t_cola* cola, void* elem, unsigned tam);


#endif // HEADER_COLA_DINAMICA_H_INCLUDED
