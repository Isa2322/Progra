#include "header.h"

void operar_double(FILE* pf, void** vec, int tam, char op)
{
    double **vector=(double**)vec;
    int i;
    double resultado;

    if(op=='+')
        for(i=0; i<tam; i++)
        {
            resultado=vector[0][i]+vector[1][i];
            fprintf(pf,"%lf %c %lf = %lf\n",vector[0][i],op,vector[1][i], resultado);
        }
    else
        for(i=0; i<tam; i++)
        {
            resultado=vector[0][i]-vector[1][i];
            fprintf(pf,"%lf %c %lf = %lf\n",vector[0][i],op,vector[1][i], resultado);
        }

}
