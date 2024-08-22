#include "header.h"

void mostrar_vecinos(int mat[][FIL], int filas, int coordi, int coordj)
{
    int i,j;


    for(i=coordi-1; i<=coordi+1; i++)
    {
        for(j=coordj-1; j<=coordj+1; j++)
        {
            if(i>=0 && i<filas && j>=0 && j<filas)
            {
                if(i==coordi && j==coordj)
                {
                    printf(" \t");
                }
            }
            else
            {
                printf("%d \t",mat[i][j]);
            }
        }
        printf("\n");
    }
}
