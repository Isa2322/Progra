#include "header.h"

void triangulo_2_con_diag(int mat[][FIL], int filas)
{
    int i, j;

    for(j=filas-1;j>=filas/2;j--)
    {
        for(i=filas-1-j;i<=j;i++)
        {
            printf("%d\n",mat[i][j]);
        }
        printf("\n");
    }
}
