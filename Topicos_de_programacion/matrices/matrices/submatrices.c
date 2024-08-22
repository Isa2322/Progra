#include "header.h"

void submatrices(int mat[][FIL], int filas, int coordi, int coordj)
{
    int i, j;


    printf("sub matriz 1\n\n");

    for(i=0;i<coordi;i++)
    {
        for(j=0;j<coordj;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n\nsub matriz 2\n\n");

    for(i=0;i<coordi;i++)
    {
        for(j=coordj+1;j<filas;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n\nsub matriz 3\n\n");

    for(i=coordi+1;i<filas;i++)
    {
        for(j=0;j<coordj;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n\nsub matriz 4\n\n");

    for(i=coordi+1;i<filas;i++)
    {
        for(j=coordj+1;j<filas;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }

}

