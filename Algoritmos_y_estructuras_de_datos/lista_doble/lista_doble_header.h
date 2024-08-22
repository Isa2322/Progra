#ifndef LISTA_DOBLE_HEADER_H_INCLUDED
#define LISTA_DOBLE_HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_nodo
{
    void *info;
    unsigned tam_info;
    struct s_nodo *sig;
    struct s_nodo *ant;
} t_nodo;

typedef struct {
    char isbn[13];
    char titulo[100];
    char autor[50];
    int anioPublicacion;
    int cantidad;
    float precio;
} libro;


typedef t_nodo *t_lista;

void crear_lista(t_lista *lista);
int insertar_en_orden(t_lista *lista, const void* elem, unsigned tam_elem,
                       int (*cmp(const void* elem_1, const void* elem_2)));
int comparar_int(int* elem1, int* elem2);
int mostrar_izq_der(const t_lista *lista, void(*mostrar)(const void*));
int mostrar_der_izq(const t_lista *lista, void(*mostrar)(const void*));


#endif // LISTA_DOBLE_HEADER_H_INCLUDED
