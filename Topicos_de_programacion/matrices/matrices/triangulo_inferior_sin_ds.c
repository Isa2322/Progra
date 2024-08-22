#include "header.h"

void triangulo_inferior_sin_ds(int mat [][FIL], int filas)
{
    int i, j;

    for(i=1;i<filas;i++)
    {
        j=filas-i;

        while(j<filas)
        {
            printf("%d \n",mat[i][j]);
            j++;
        }
        printf("\n");
    }

/*
    for(i=0;i<FIL;i++)
    {
        for(j=0;j<FIL;j++)
        {
            if(j<i)
                printf("%d \t",mat[i][j]);
            else
                printf("  \t");
        }
        printf("\n");
    }
*/
}
