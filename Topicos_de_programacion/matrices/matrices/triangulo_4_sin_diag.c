#include "header.h"

void triangulo_4_sin_diag(int mat[][FIL], int filas)
{
    int i, j;

    if(filas%2==0)
    {
        for(i=1;i<filas-1;i++)
        {
            if(i<filas/2)
            {
                for(j=0;j<=i;j++)
                {
                    printf("%d\n",mat[i][j]);
                }
                printf("\n");
            }
            else
            {
                for(j=0;j<filas-i;j++)
                {
                     printf("%d\n",mat[i][j]);
                }
                printf("\n");
            }
        }
    }
    else
    {
        for(i=1;i<filas-1;i++)
        {
            if(i<=filas/2)
            {
                for(j=0;j<i;j++)
                {
                    printf("%d\n",mat[i][j]);
                }
                printf("\n");
            }
            else
            {
                for(j=0;j<filas-i-1;j++)
                {
                     printf("%d\n",mat[i][j]);
                }
                printf("\n");
            }
        }
    }

}
