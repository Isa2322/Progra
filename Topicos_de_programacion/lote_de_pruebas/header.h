#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int anio;
    }t_fecha;

void lote_de_pruebas();
void cambiar_fecha();
void mostrar_arch(FILE*);

#endif // HEADER_H_INCLUDED
