#include "header.h"

void diagonal_secundaria(int mat[][FIL], int filas)
{
    int i;

    for(i=1;i<=filas;i++)
        printf("%d \n",mat[i-1][filas-i]);
}
