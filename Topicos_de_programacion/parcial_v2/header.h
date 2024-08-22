#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char carga_vec(FILE *, FILE *, void **, int*, int*);

void carga_double(void** , FILE *, FILE *);
void carga_int   (void** , FILE *, FILE *);
void carga_float (void** , FILE *, FILE *);

void suma_y_resta(void** vec, int tam, int tipo, char op);


void operar_int   (FILE* pf, void** vec, int tam, char op);
void operar_float (FILE* pf, void** vec, int tam, char op);
void operar_double(FILE* pf, void** vec, int tam, char op);



#endif // HEADER_H_INCLUDED
