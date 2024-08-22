#include "header.h"

void operar_float(FILE* pf, void** vec, int tam, char op)
{
    float **vector=(float**)vec;
    int i;
    float resultado;

    if(op=='+')
        for(i=0; i<tam; i++)
        {
            resultado=vector[0][i]+vector[1][i];
            fprintf(pf,"%f %c %f = %f\n",vector[0][i],op,vector[1][i], resultado);
        }
    else
        for(i=0; i<tam; i++)
        {
            resultado=vector[0][i]-vector[1][i];
            fprintf(pf,"%f %c %f = %f\n",vector[0][i],op,vector[1][i], resultado);
        }

}
