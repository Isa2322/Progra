#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[21];
    char apellido[21];
    int num;
} t_campeones;

typedef struct{
    int dia;
    int mes;
    int anio;
    }t_fecha;

void mostrar_archivo_generico(FILE *, int ,void* ,
                        void (*mostrar)( void *));

void modificar_archivo(FILE *, int, int (*modificar)( void *));

void leer_fecha(void*);
int cambiar_fecha(void* );

void cargar_bin();
void largo_fijo_a_bin(char *, t_campeones *);
void largo_variable_a_bin(char *, t_campeones *);



#endif // HEADER_H_INCLUDED
