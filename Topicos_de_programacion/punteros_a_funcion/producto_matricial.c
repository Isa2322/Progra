#include "header.h"

void producto_matricial(int matriz_1[][5], int filas_1, int columnas_1, int matriz_2[][5], int filas_2, int columnas_2)
{
    int i,j,k,sum=0;
    int **matriz_resultado;

    if(columnas_1 != filas_2)
    {
        printf("No se pueden multiplicar las matrices porque la cantidad de filas de la matriz 1 es diferente de la cantidad de filas de la matriz 2");
        exit(1);
    }

    matriz_resultado=crear_matriz(columnas_1,filas_2,sizeof(int));

    if(matriz_resultado==NULL)
    {
        printf("Sin memoria");
        exit(1);
    }

    for(i=0; i<filas_1; i++)
    {
        for(k=0; k<filas_2; k++)
        {
            for(j=0; j<columnas_1; j++)
            {
                sum+=(matriz_1[i][j]*matriz_2[j][k]);
            }
            matriz_resultado[i][k]=sum;
            sum=0;
        }
    }

    for(i=0;i<columnas_1;i++)
    {
        for(j=0;j<filas_2;j++)
        {
            printf("%d\t",matriz_resultado[i][j]);
        }
        printf("\n");
    }
}
