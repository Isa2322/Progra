#include "header.h"

void triangulo_1_sin_diag(int mat[][FIL], int filas)
{

    int i, j;

    for(i=0; i<(filas/2) ; i++)
    {
        for(j=i+1; j<filas-1-i; j++)
        {
            printf("%d\n",mat[i][j]);
        }
        printf("\n");
    }
}
