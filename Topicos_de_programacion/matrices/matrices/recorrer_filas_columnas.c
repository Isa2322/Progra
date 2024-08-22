#include "header.h"

void recorrer_filas_columnas(int mat[][FIL], int filas)
{
    int i , j;

    for(i=0;i<filas;i++)
    {
        for(j=0;j<filas;j++)
        {
            printf("%d \t",mat[i][j]);
        }
        printf("\n");
    }
}
