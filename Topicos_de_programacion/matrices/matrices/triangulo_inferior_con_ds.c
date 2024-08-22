#include "header.h"

void triangulo_inferior_con_ds(int mat [][FIL], int filas)
{
    int i, j;


    for(i=0;i<filas;i++)
    {
        j=(filas-i-1);

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
            if(j+i>=FIL-1)
                printf("%d \t",mat[i][j]);
            else
                printf("  \t");
        }
        printf("\n");
    }
*/
}
