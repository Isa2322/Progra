#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANO 1000
#define SIN_MEM 0
#define TODO_OK 1
#define SIN_ELEM 2
#define MINIMO(x,y) ((x)>(y)?(y):(x))


typedef struct
{
    char pila[TAMANO];
    int tope;
} tpila;


void lote_de_pruebas(tpila* pila1, tpila* pila2);


void crear_tpila(tpila* pila);
int pila_vacia(const tpila* pila);
int pila_llena(const tpila* pila, unsigned tam_elem);
void vaciar_pila(tpila* pila);
int apilar_pila(tpila* pila, const void* elem, unsigned tam);
int desapilar_pila(tpila* pila, void* elem, unsigned tam);

void ordenar_archivo(tpila* pila1, FILE* pf);


#endif // HEADER_H_INCLUDED
