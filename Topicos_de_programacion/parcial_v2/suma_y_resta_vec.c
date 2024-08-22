#include "header.h"

void suma_y_resta(void** vec, int tam, int tipo, char op)
{
    FILE *pf;

    pf=fopen("resultado.txt","wt");

    if(tipo==1)
        operar_int(pf,vec,tam,op);
    else
        if(tipo==2)
            operar_float(pf,vec,tam,op);
        else
            operar_double(pf,vec,tam,op);

    fclose(pf);
}
