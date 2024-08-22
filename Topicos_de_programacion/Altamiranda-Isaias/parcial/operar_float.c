#include "header.h"

void operar_float(void* vec1, void* vec2, FILE* pf, char op)
{
    float *n1=vec1, *n2=vec2;
    float res;

    if(op=='+')
        res=*n1+*n2;
    else
        res=*n1-*n2;

    fprintf(pf,"%f %c %f = %f",*n1, op, *n2, res);

    n1++;
    n2++;
    vec1=n1;
    vec2=n2;

}
