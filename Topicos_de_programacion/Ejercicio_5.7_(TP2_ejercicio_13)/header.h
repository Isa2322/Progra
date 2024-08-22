#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    int dni;
    char apellido[21];
    char nombre[21];
    float sueldo;
    }t_empleados;

typedef struct{
    int dni;
    char apellido[21];
    char nombre[21];
    float promedios;
    }t_alumnos;

void actualizar_sueldos(FILE*, FILE*, int, int comparar(void*,void*),void actualizar(void*,void*,float,float));

#endif // HEADER_H_INCLUDED
