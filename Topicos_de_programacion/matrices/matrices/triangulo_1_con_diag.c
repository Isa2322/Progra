#include "header.h"

void triangulo_1_con_diag(int mat[][FIL], int filas)
{

    int i, j;

    for(i=0; i<=(filas/2) ; i++)
    {
        for(j=i; j<filas-i; j++)
        {
            printf("%d\n",mat[i][j]);
        }
        printf("\n");
    }
}
