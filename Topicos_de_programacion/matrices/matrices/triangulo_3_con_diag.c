#include "header.h"

void triangulo_3_con_diag(int mat[][FIL], int filas)
{
    int i, j, col;

    if(filas%2==0)
    {
        col=1;

        for(i=(filas/2);i<filas;i++)
        {
            for(j=(filas/2)-col;j<=i;j++)
            {
                printf("%d\n",mat[i][j]);
            }
            col++;
            printf("\n");
        }

    }
    else
    {
        col=0;
        for(i=(filas/2);i<filas;i++)
        {
            for(j=(filas/2)-col;j<=i;j++)
            {
                printf("%d\n",mat[i][j]);
            }
            col++;
            printf("\n");
        }
    }
}

