#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char leer_txt(FILE*, FILE*,int*,int*);


void carga_vector_int(FILE *, void *);
void carga_vector_float(FILE *, void *);
void carga_vector_double(FILE *, void *);

void suma_y_resta(void *vec1, void *vec2, char op, int dim, void (*operar)(void*, void*, FILE*, char));

void operar_int(void*, void*, FILE*, char);
void operar_float(void*, void*, FILE*, char);
void operar_double(void*, void*, FILE*, char);


#endif // HEADER_H_INCLUDED
