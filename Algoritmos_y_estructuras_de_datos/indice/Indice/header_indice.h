#ifndef HEADER_INDICE_H_INCLUDED
#define HEADER_INDICE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 0
#define ERROR_MEMORIA 1
#define DUPLICADO 2

typedef struct
{
    char nombre[50];
    char descripcion[50];
    unsigned n_serie;
    float precio;
} t_productos;

typedef struct s_nodo_arbol
{
    void* info;
    unsigned tam;
    struct s_nodo_arbol *izq;
    struct s_nodo_arbol *der;
}t_nodo_arbol;

typedef t_nodo_arbol* t_arbol;



void crear_arbol(t_arbol *raiz);
void crear_indice(t_arbol *raiz);
int insertar_arbol(t_arbol *arbol, void* dato, unsigned tam_dato,
                                      int (*cmp)(void*, void*));
void crear_indice(t_arbol *raiz);
void escribir_indice(t_arbol *raiz);
void recorrer_en_orden_mod(t_arbol *raiz, void(*accion)(t_arbol*));
int comparar_nombre_productos( void *dato1,  void *dato2);
void mostrar_arbol(t_arbol *raiz);

#endif // HEADER_INDICE_H_INCLUDED
