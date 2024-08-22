#ifndef HEADER_RECURSIVIDAD_H_INCLUDED
#define HEADER_RECURSIVIDAD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int factorial(int n);
int sumatoria(int n);
int fibonacci(int n);
void string_vert(char *ini);
void string_vert_inv(char *ini);
void string_vert_norm_inv(char *ini);
void string_red(char *ini);
void string_aum(char *ini);

void n_entero(int n);
void n_entero_inv(int n);
void n_entero_inv_norm(int n);
void numeros_4(int n);
void numeros_5(int n);
int es_palindromo(char* ini);
int _es_palindromo(char* ini, char* fin);


#endif // HEADER_RECURSIVIDAD_H_INCLUDED
