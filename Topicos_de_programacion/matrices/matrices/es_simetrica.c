#include "header.h"

void es_simetrica(int mat [][FIL], int filas)
{
    int i, j, cont=0;


    for(i=0; i<filas; i++)
    {
        for(j=0; j<filas-i-1; j++)
        {
            if(mat[i][j]!=mat[j][i])
                cont++;
        }
    }

    if(cont==0)
        printf("La matriz es simetrica");
    else
        printf("La matriz NO es simetrica");

}

