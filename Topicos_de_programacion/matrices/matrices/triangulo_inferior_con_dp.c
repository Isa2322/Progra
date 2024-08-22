#include "header.h"

void triangulo_inferior_con_dp(int mat [][FIL], int filas)
{
    int i,j=0;

    for(i=0;i<filas;i++)
    {
        while(j<=i)
        {
            printf("%d \t",mat[i][j]);
            j++;
        }
        j=0;
        printf("\n");
    }
}
