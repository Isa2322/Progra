#include "header.h"

void triangulo_superior_con_ds(int mat[][FIL], int filas)
{
    int i, j;


    for(i=0;i<filas;i++)
    {
        for(j=0;j<(filas-i);j++)
            printf("%d \n",mat[i][j]);

        printf("\n");
    }


/*
    for(i=0;i<FIL;i++)
        {
            for(j=0;j<FIL;j++)
            {
                if(j+i<=(filas-1))
                    printf("%d \t",mat[i][j]);
                else
                    printf("  \t");
            }
            printf("\n");
        }
*/

}