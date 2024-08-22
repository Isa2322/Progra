#include "header.h"

void matriz_concentrica(int mat[][FIL], int filas, int coordi, int coordj)
{
    int i, j;

    if(filas%2!=0 && ((coordi==filas/2) || (coordj==filas/2)))
    {
        if(coordi==filas/2)
        {
            for((coordj<(filas/2))?(j=coordj):(j=(filas-coordj-1)) ; (coordj<(filas/2))?(j<(filas-coordj)):(j<=coordj) ; j++)
            {
                printf("%d\t",mat[coordi][j]);
            }
        }
        else
        {
            if(coordj==filas/2)
            {
                for((coordi<(filas/2))?(i=coordi):(i=(filas-coordi-1)) ; (coordi<(filas/2))?(i<filas-coordi):(i<=coordi) ; i++)
                {
                    printf("%d\n",mat[i][coordj]);
                }
            }
        }
    }
    else
    {
        for((coordi<(filas/2))?(i=coordi):(i=(filas-coordi-1)) ; (coordi<(filas/2))?(i<filas-coordi):(i<=coordi) ; i++)
        {
            for((coordj<(filas/2))?(j=coordj):(j=(filas-coordj-1)) ; (coordj<(filas/2))?(j<(filas-coordj)):(j<=coordj) ; j++)
            {
                printf("%d\t",mat[i][j]);
            }
            printf("\n");
        }
    }
}


