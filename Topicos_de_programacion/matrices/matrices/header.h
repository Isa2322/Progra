#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define FIL 5

void diagonal_pricipal(int [][FIL], int);
void diagonal_secundaria(int [][FIL], int);

void triangulo_inferior_sin_dp(int [][FIL], int);
void triangulo_inferior_con_dp(int [][FIL], int);
void triangulo_inferior_sin_ds(int [][FIL], int);
void triangulo_inferior_con_ds(int [][FIL], int);

void triangulo_superior_sin_dp(int [][FIL], int);
void triangulo_superior_con_dp(int [][FIL], int);
void triangulo_superior_sin_ds(int [][FIL], int);
void triangulo_superior_con_ds(int [][FIL], int);

void triangulo_1_sin_diag(int [][FIL], int);
void triangulo_2_sin_diag(int [][FIL], int);
void triangulo_3_sin_diag(int [][FIL], int);
void triangulo_4_sin_diag(int [][FIL], int);

void triangulo_1_con_diag(int [][FIL], int);
void triangulo_2_con_diag(int [][FIL], int);
void triangulo_3_con_diag(int [][FIL], int);
void triangulo_4_con_diag(int [][FIL], int);

void recorrer_filas_columnas(int [][FIL], int);
void recorrer_espiral(int [][FIL], int);
void recorrer_diagonal(int [][FIL], int);

void submatrices(int [][FIL], int, int, int);
void may_submatriz(int [][FIL], int, int, int);
void min_submatriz(int [][FIL], int, int, int);
void may_submatriz_cuadrada(int [][FIL], int, int, int);
void min_submatriz_cuadrada(int [][FIL], int, int, int);

void matriz_concentrica(int [][FIL], int, int, int);

void mostrar_vecinos(int [][FIL], int, int, int);
void promedio_vecinos(int [][FIL], int, int, int);

void es_simetrica(int [][FIL], int);
void trasponer(int [][FIL], int);
void es_identidad(int [][FIL], int);
void es_escalar(int [][FIL], int);

void producto_matricial(int [][5], int, int, int [][5], int, int, int [][5], int, int);


#endif // HEADER_H_INCLUDED
