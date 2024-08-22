#include "header.h"

void es_identidad(int mat [][FIL], int filas)
{
    int i, j, cont=0;

    for(i=0;i<filas;i++)
    {
        for(j=0;j<filas-i;j++)
        {
            if(i==j)
            {
                if(mat[i][j]!=1)
                    cont++;
            }
            else
            {
                if(mat[i][j]!=0 || mat[j][i]!=0)
                    cont++;
            }
        }
    }

    if(cont==0)
        printf("La matriz es identidad");
    else
        printf("La matriz NO es identidad");
}
