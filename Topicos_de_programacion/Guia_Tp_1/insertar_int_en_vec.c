#include<stdio.h>
#include<stdlib.h>

void insertar_int_en_vec(int*vec, int ce, int tam, int pos, int elem)
{
    int aux, i;

    if(pos>=tam ||tam<=ce)
    {
        printf("La posicion esta fuera del array");
        exit (1);
    }

    //para usar posicion de subindice uso i<=pos ------- para usar posicion "literal" uso i<pos

    for(i=1;i<pos;i++)
        vec++;

    for(pos;pos<=tam;pos++)
    {
        aux=*vec;
        *vec=elem;
        vec++;
        elem=aux;
    }
}
