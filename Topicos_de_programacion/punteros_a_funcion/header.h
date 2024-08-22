#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dia;
    int mes;
    int anio;
    }t_fecha;

typedef struct{
    int dni;
    char nom [20];
    char ap [20];
    t_fecha fing;
    }t_alu;

typedef struct{
    int cod_art;
    char desc[50];
    int stock;
    }t_stock;

int comparar_enteros_menor_a_mayor(const void *, const void *);
int comparar_enteros_mayor_a_menor(const void *, const void *);

void mostrar_cualquier_vector(const void*, int, int,
                              void (*mostrar)(const void *));

void mostrar_vec_char(const void*);
void mostrar_vec_int(const void*);
void mostrar_vec_float(const void*);

void producto_matricial(int [][5], int , int , int [][5], int , int );
int** crear_matriz(int, int, int);

void* sim_memcopy(void*, const void*, int);
void* sim_memmove(void*, const void*, int);

int* algoritmo_seleccion_int(int*, int );

int carga_archivo(int );

int leer_archivo();

void ingreso_de_datos(t_fecha*);

void leer_archivo_generico(FILE *, int ,void* ,
                           void (*mostrar)( void *));

void leer_fecha(void*);
void leer_stock(void*);


void sim_qsort(void *, int , int , int(*comparar)(const void*, const void*));

void* buscar_menor(void *,int ,int ,int(*comparar)(const void*, const void*));

void intercambio(void*, void*, int);

int comparar_int(const void*,const void*);

void modificar_archivo(FILE *, int , void* , int (*modificar)( void *));

int modificar_stock(void* );

int cambiar_fecha(void* );


#endif // HEADER_H_INCLUDED
