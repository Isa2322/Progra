#include "header.h"

void suma_y_resta(void *vec1, void *vec2, char op, int dim, void (*operar)(void*, void*, FILE*, char))
{
    FILE *pf;
    int i;

    pf=fopen("resultado.txt","wt");

    if(pf==NULL)
        return;

    for(i=0; i<dim; i++)
    {
        operar(vec1,vec2,pf,op);
    }
}
