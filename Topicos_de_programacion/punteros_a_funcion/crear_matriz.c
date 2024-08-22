#include "header.h"

int** crear_matriz(int fil, int col, int tam_tipo)
{
    int **filas;
    int i=0;

    filas=(int**)malloc(fil*tam_tipo);

    if(filas==NULL)
    {
        exit(1);
    }

    filas[i]=(int*)malloc(col*tam_tipo);

    while(filas[i]!=NULL && i<col)
    {
        i++;
        filas[i]=(int*)malloc(col*tam_tipo);
    }

    if(filas[i]==NULL)
    {
        for(i-=1; i>0; i--)
            free(filas[i]);
    }

    return filas;
}
