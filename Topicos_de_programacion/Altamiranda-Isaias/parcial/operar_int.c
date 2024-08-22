#include "header.h"

void operar_int(void* vec1, void* vec2, FILE* pf, char op)
{
    int *n1=vec1, *n2=vec2;
    int num1=*n1, num2=*n2;
    int res;

    if(op=='+')
        res=num1+num2;
    else
        res=num1-num2;

    fprintf(pf,"%d %c %d = %d",*n1, op, *n2, res);

    n1++;
    n2++;
    vec1=n1;
    vec2=n2;

}
