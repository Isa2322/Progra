#include "header.h"

void producto_matricial(int matriz_1[][5], int filas_1, int columnas_1, int matriz_2[][5], int filas_2, int columnas_2)
{
    int i,j,k,sum=0;

    if(columnas_1 != filas_2)
    {
        printf("No se pueden multiplicar las matrices porque la cantidad de filas de la matriz 1 es diferente de la cantidad de filas de la matriz 2");
        exit(1);
    }
    else
        if(filas_1!=filas_r || columnas_2!=columnas_r)
        {
            printf("La matriz resultado tiene una cantidad incorrecta de filas o columnas");
            exit (1);
        }

       for(i=0;i<filas_1;i++)
       {
           for(k=0;k<filas_2;k++)
           {
               for(j=0;j<columnas_1;j++)
               {
                   sum+=(matriz_1[i][j]*matriz_2[j][k]);
               }
                matriz_resulatado[i][k]=sum;
                sum=0;
           }
       }
}
