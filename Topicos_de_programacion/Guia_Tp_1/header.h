#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "normalizar_string.h"

char* buscar_prox_pal_cl(const char* , int* );
char* buscar_prox_pal_punt(const char* , char** );
char* invertir_palabra(char* , char*);
char* invertir_frase(char*);


#endif // HEADER_H_INCLUDED

