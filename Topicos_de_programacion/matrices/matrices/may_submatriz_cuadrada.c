#include "header.h"

void may_submatriz_cuadrada(int mat[][FIL], int filas, int coordi, int coordj)
{
    int i, j;

    i=filas-coordi-1;
    j=filas-coordj-1;

    if(i>coordi)
    {
        if(j>coordj && j==i)
        {
            printf("La submatriz 4 es la mayor submatriz cuadrada");
        }
        else
        {
            if(j<coordj && i==coordj)
            {
                printf("La submatriz 3 es la mayor submatriz cuadrada");
            }
            else
            {
                printf("No hay submatrices cuadradas");
            }
        }
    }
    else
    {
        if(i<coordi)
        {
            if(j>coordj && j==coordi)
            {
                printf("La submatriz 2 es la mayor submatriz cuadrada");
            }
            else
            {
                if(j<coordj && coordi==coordj)
                {
                    printf("La submatriz 1 es la mayor submatriz cuadrada");
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

