#include "header.h"

void min_submatriz_cuadrada(int mat[][FIL], int filas, int coordi, int coordj)
{
    int i, j;

    i=filas-coordi-1;
    j=filas-coordj-1;

    if(i<coordi)
    {
        if(j<coordj && i==j)
        {
            printf("La submatriz 4 es la menor submatriz cuadrada");
        }
        else
        {
            if(j>coordj && i==coordj)
            {
                printf("La submatriz 3 es la menor submatriz cuadrada");
            }
            else
            {
                printf("No hay submatrices cuadradas");
            }
        }
    }
    else
    {
        if(i>coordi)
        {
            if(j>coordj && coordj==coordi)
            {
                printf("La submatriz 1 es la menor submatriz cuadrada");
            }
            else
            {
                if(j<coordj && coordi==j)
                {
                    printf("La submatriz 2 es la menor submatriz cuadrada");
                }
                else
                {
                    printf("No hay submatrices cuadradas");
                }
            }
        }
        else
        if(j==coordj)
            {
                printf("Todas las submatrices son cuadradas e iguales");
            }
            else
            {
                printf("No hay submatrices cuadradas");
            }

    }
}

