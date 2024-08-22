#include "header.h"

void operar_int(FILE* pf, void** vec, int tam, char op)
{
    int **vector=(int**)vec;
    int i, resultado;

    if(op=='+')
        for(i=0; i<tam; i++)
        {
            resultado=vector[0][i]+vector[1][i];
            fprintf(pf,"%d %c %d = %d\n",vector[0][i],op,vector[1][i], resultado);
        }
    else
        for(i=0; i<tam; i++)
        {
            resultado=vector[0][i]-vector[1][i];
            fprintf(pf,"%d %c %d = %d\n",vector[0][i],op,vector[1][i], resultado);
        }

}
