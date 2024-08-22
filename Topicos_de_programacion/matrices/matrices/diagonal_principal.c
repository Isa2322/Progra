#include "header.h"

void diagonal_pricipal(int mat[][FIL],int filas)
{
    int i;

    for(i=0;i<filas;i++)
        printf("%d \n",mat[i][i]);
}
