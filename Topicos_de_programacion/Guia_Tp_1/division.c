#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int cociente;
    int resto;
    }Tdivisionn;

Tdivisionn division(int num, int div)
{
    Tdivisionn numero;

    if(div==0)
    {
        printf("NO SE PUEDE DIVIDIR ENTRE CERO");
        exit (1);
    }

    numero.cociente=num/div;
    numero.resto=num%div;

    return numero;
}
