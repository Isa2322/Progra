#include "header.h"

void trasponer(int mat [][FIL], int filas)
{
    int i, j, aux;

    for(i=0; i<filas; i++)
    {
        for(j=0; j<filas-i-1; j++)
        {
            aux=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=aux;
        }
    }
}

