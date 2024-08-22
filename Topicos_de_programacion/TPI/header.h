#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define TAM 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encriptar_cesar   (FILE *, FILE*, int, int);
void desencriptar_cesar(FILE *, FILE*, int, int);


char* buscar_letra(char*, char);

char* invertir_palabra    (char*, char* );
char* buscar_prox_pal_punt(char*, char**);
char* invertir_frase      (char*);

void cesar(FILE *, FILE *,
            void (*funcion)(FILE *, FILE*, int, int));

int son_coprimos   (int, int);
int inverso_modular(int, int);

void desencriptar_afin(FILE *, FILE *);



#endif // HEADER_H_INCLUDED
