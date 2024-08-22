#include "header.h"

void promedio_vecinos(int mat[][FIL], int filas, int coordi, int coordj)
{
    int i, j, cont=0, suma=0;

    if(filas==1)
    {
        printf("La matriz no tiene vecinos");
        system("pause");
        exit (1);
    }


    for(i=coordi-1; i<=coordi+1; i++)
    {
        for(j=coordj-1; j<=coordj+1; j++)
        {
            if(i>=0 && i<filas && j>=0 && j<filas)
                if(i!=coordi || j!=coordj)
                {
                    suma+=mat[i][j];
                    cont++;
                }
        }
    }

    printf("El promedio de los vecinos es: %.2f",(float)suma/cont);
}
