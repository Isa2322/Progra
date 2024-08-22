#include "potencia.h"
#include <stdio.h>

float ex(int num, float tol)
{
    int multi=1, cont=1;
    float res=1, ter, pot=num;

    ter=num/multi;

    while(ter>tol)
    {
        res+=ter;

        cont++;

        pot*=num;
        multi*=cont;

        ter=pot/multi;

    }

    printf("%f",res);

    return res;
}

