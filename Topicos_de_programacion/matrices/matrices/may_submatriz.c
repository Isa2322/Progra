#include "header.h"

void may_submatriz(int mat[][FIL], int filas, int coordi, int coordj)
{
    int i, j;

    i=filas-coordi-1;
    j=filas-coordj-1;

    if(i>coordi)
    {
        if(j>coordj)
        {
            printf("La submatriz 4 es la mayor");
        }
        else
        {
            if(j<coordj)
            {
                printf("La submatriz 3 es la mayor");
            }
            else
            {
                printf("Las submatrices 3 y 4 son las mayores");
            }
        }
    }
    else
    {
        if(i<coordi)
        {
            if(j>coordj)
            {
                printf("La submatriz 2 es la mayor");
            }
            else
            {
                if(j<coordj)
                {
                    printf("La submatriz 1 es la mayor");
                }
                else
                {
                    printf("Las submatrices 1 y 2 son las mayores");
                }
            }
        }
        else
        if(j>coordj)
            {
                printf("Las submatrices 2 y 4 son las mayores");
            }
            else
            {
                if(j<coordj)
                {
                    printf("Las submatrices 1 y 3 son las mayores");
                }
                else
                {
                    printf("Todas las submatrices son iguales");
                }
            }

    }
}

