#include "header.h"

void carga_double(void** vec, FILE *pf1, FILE *pf2)
{
    double **vectores=(double**)vec, num;
    int pos;

    while(!feof(pf1))
    {
        fscanf(pf1,"%d|%lf\n",&pos, &num);
        vectores[0][pos-1]=num;
    }

    while(!feof(pf2))
    {
        fscanf(pf2,"%d|%lf\n",&pos, &num);
        vectores[1][pos-1]=num;
    }
}
