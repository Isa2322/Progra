#include "header.h"

void triangulo_3_sin_diag(int mat[][FIL], int filas)
{
    int i, j;

    for(i=filas-1;i>(filas/2);i--)
    {
        for(j=filas-i;j<i;j++)
        {
            printf("%d\n",mat[i][j]);
        }
        printf("\n");
    }

}
