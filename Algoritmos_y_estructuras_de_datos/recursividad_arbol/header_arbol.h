#ifndef HEADER_ARBOL_H_INCLUDED
#define HEADER_ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MINIMO(X,Y) ((X)<(Y)?(X):(Y))
#define MAXIMO(X,Y) ((X)>(Y)?(X):(Y))
#define TODO_OK 0
#define ERROR_MEMORIA 1
#define DUPLICADO 2

typedef struct s_nodo_arbol
{
    void* info;
    unsigned tam;
    struct s_nodo_arbol *izq;
    struct s_nodo_arbol *der;
}t_nodo_arbol;

typedef t_nodo_arbol* t_arbol;



int cargar_arbol_desde_orden(t_arbol *arbol, void* datos, int cant_elem,
                              int(*carga_tipo_dato)(t_arbol*,void*, int, int));

void crear_arbol(t_arbol *raiz);
int _carga_enteros(t_arbol* raiz, void* datos, int ini, int fin);
void recorrer_en_orden(t_arbol *arbol, void(*accion)(t_arbol*));
void _mostrar_raiz_int(t_arbol *raiz);
int altura_arbol(const t_arbol* raiz);

int cmp_entero(void* d1, void* d2);
void* busqueda_binaria(t_arbol *raiz, void* dato, int (*cmp)(void* d1, void* d2));



int mayor_elem_no_clave(t_arbol *raiz, void *dato, unsigned tam,
                          int(*cmp)(void*, void*));

t_arbol* mayor_nodo_no_clave(t_arbol *raiz, t_arbol *mayor,
                             int(*cmp)(void*, void*));



int menor_elem_no_clave(t_arbol *raiz, void *dato, unsigned tam,
                        int(*cmp)(void*, void*));

t_arbol* menor_nodo_no_clave(t_arbol *raiz, t_arbol *menor,
                             int(*cmp)(void*, void*));




int buscar_elem_no_clave(t_arbol *raiz, void *dato, unsigned tam,
                         int(*cmp)(void*, void*));

t_arbol* buscar_nodo_no_clave(t_arbol *raiz, void *dato,
                              int(*cmp)(void*, void*));

#endif // HEADER_ARBOL_H_INCLUDED
