#include<stdio.h>
#include<stdlib.h>


void eliminar_int_en_array_pos(int*vec, int ce, int tam, int pos)
{
    int aux=0, aux2, i=0;

    if(tam<=ce && pos>=tam)
    {
        printf("La posicion esta fuera del array");
        exit (1);
    }

    while(i<ce-1)
    {
        i++;
        vec++;
    }


    for(i;i>=pos-1;i--)
        {
        aux2=*vec;
        *vec=aux;
        vec--;
        aux=aux2;
        }

}
