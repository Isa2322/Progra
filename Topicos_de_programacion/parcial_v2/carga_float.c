#include "header.h"

void carga_float(void** vec, FILE *pf1, FILE *pf2)
{
    float **vectores=(float**)vec, num;
    int pos;

    while(!feof(pf1))
    {
        fscanf(pf1,"%d|%f\n",&pos, &num);
        vectores[0][pos-1]=num;
    }

    while(!feof(pf2))
    {
        fscanf(pf2,"%d|%f\n",&pos, &num);
        vectores[1][pos-1]=num;
    }
}
