#include "header.h"

void carga_int(void** vec, FILE *pf1, FILE *pf2)
{
    int **vectores=(int**)vec;
    int pos, num;

    while(!feof(pf1))
    {
        fscanf(pf1,"%d|%d\n",&pos, &num);
        vectores[0][pos-1]=num;
    }

    while(!feof(pf2))
    {
        fscanf(pf2,"%d|%d\n",&pos, &num);
        vectores[1][pos-1]=num;
    }
}
