#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}t_fecha;

int carga_archivo(int );

int leer_archivo();

void ingreso_de_datos(t_fecha*);

int leer_archivo_generico(int ,
                          void (*mostrar)( void **));

void leer_fecha(void**punt);


#endif // HEADER_H_INCLUDED
