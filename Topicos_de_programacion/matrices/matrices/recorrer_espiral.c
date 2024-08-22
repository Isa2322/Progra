#include "header.h"

void recorrer_espiral(int mat[][FIL], int filas)
{
    int i=0, j=0, lim=0;

    while(lim<(filas/2))
    {
        for(j;j<filas-lim;j++)
        {
            printf("%d \t",mat[i][j]);
        }
        printf("\n");
        j--;
        i++;

        for(i;i<filas-lim;i++)
        {
            printf("%d \t",mat[i][j]);
        }
        printf("\n");
        i--;
        j--;


        for(j;j>=0+lim;j--)
        {
            printf("%d \t",mat[i][j]);
        }
        printf("\n");
        j++;

        lim++;
        i--;

        for(i;i>=lim;i--)
        {
            printf("%d \t",mat[i][j]);
        }
        printf("\n");
        i++;
        j++;
    }


}
