#include "header.h"

void operar_double(void* vec1, void* vec2, FILE* pf, char op)
{
    double *n1=vec1, *n2=vec2;
    double res;

    if(op=='+')
        res=*n1+*n2;
    else
        res=*n1-*n2;

    fprintf(pf,"%lf %c %lf = %lf",*n1, op, *n2, res);

    n1++;
    n2++;
    vec1=n1;
    vec2=n2;

}
