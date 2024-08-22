#include "header.h"

void es_escalar(int mat [][FIL], int filas)
{
    int i, j, cont=0, diag;

    diag=mat[0][0];

    for(i=0;i<filas;i++)
    {
        for(j=i;j<filas;j++)
        {
            if(i==j)
            {
                if(mat[i][j]!=diag)
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
        printf("La matriz es escalar");
    else
        printf("La matriz NO es escalar");
}
