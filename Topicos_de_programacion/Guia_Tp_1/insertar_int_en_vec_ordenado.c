#include<stdio.h>
#include<stdlib.h>

void insertar_int_en_vec_ordenado(int*vec, int ce, int tam, int elem)
{

    int aux, i=0;

    if(tam<=ce)
    {
        printf("La cantidad de elementos es mayor que el tamaño del array");
        exit (1);
    }

    while(elem>*vec && i<tam && i<ce)
    {
        vec++;
        i++;
    }

    if(i>=tam)
        printf("Todos los elementos del array son menores que el elemento dado\n");
    else
        for(i;i<tam;i++)
        {
        aux=*vec;
        *vec=elem;
        vec++;
        elem=aux;
        }


}
