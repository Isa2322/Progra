#ifndef HEADER_COLA_H_INCLUDED
#define HEADER_COLA_H_INCLUDED

#define MAX 10000
#define TODO_OK 0
#define ERROR 1//////revisar

#define MINIMO(x,y) ((x)<(y)?(x):(y))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char vec[MAX];
    unsigned pri;
    unsigned ult;
    unsigned tam_disp;
} tcola;

typedef struct
{
    char nombre_cliente[20];
    char tipo_mov; //debe ser 'D' o 'E' (deposito o extraccion)
    int importe;
} t_movimientos;

void crear_cola(tcola* cola);
int cola_vacia(const tcola* cola);
int cola_llena(const tcola* cola, unsigned tam_dato);
void vaciar_cola(tcola* cola);
int acolar(tcola* cola, const void* elem, unsigned tam_elem);
int desacolar(tcola* cola, void* elem, unsigned tam_elem);
void lote_de_pruebas();
int banco();


#endif // HEADER_COLA_H_INCLUDED
