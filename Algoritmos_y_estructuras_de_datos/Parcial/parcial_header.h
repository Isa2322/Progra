///43.094.671_Atamiranda_Isaias
#ifndef PARCIAL_HEADER_H_INCLUDED
#define PARCIAL_HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 1
#define ERROR_ARCHIVO 2
#define SIN_MEM 3
#define VACIA 4
#define VENCE_PROX 5
#define NO_VENCE_PROX 6
#define ES_MENOR 7
#define MINIMO(x,y) ((x)<(y)?(x):(y))

typedef struct
{
    int dia;
    int mes;
    int anio;
}t_fecha;

typedef struct
{
    char cod_prod[6];
    char desc[25];
    int lote;
    t_fecha fecha;
    unsigned cant;
}t_producto;

typedef struct s_nodo
{
    unsigned cb;
    void* dato;
    struct s_nodo* sig;
} t_nodo;

typedef t_nodo *t_pila;


void lote_prueba();
void crear_pila(t_pila* pila);
int pila_vacia(t_pila* pila);
int apilar(t_pila* pila, void* dato, unsigned tam);
int desapilar(t_pila* pila, void* dato, unsigned tam);
void vaciar_pila(t_pila* pila);
int generar_archivos(int n_meses);
int vence_pronto(t_fecha fecha_hoy, t_fecha fecha_prod, int meses);
int compara_fechas(t_fecha f1, t_fecha f2);
void mostrar_arch();
void menu();

#endif // PARCIAL_HEADER_H_INCLUDED
