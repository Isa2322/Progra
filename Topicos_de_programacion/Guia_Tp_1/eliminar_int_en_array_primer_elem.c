#include<stdio.h>
#include<stdlib.h>

void eliminar_int_en_array_primer_elem(int*vec, int ce, int tam, int elem)
{
    int aux=0, aux2, i, pos=-1;

    if(tam<ce)
    {
        printf("La cantidad de elementos es mayor que el tamaño del array");
        exit (1);
    }

    for(i=0;i<ce-1;i++)
    {
        vec++;
        if(*vec==elem)
            pos=i;
    }

    if(pos==-1)
        printf("No se encontro el elemento \n");
    else
        for(i;i>pos;i--)
        {
            aux2=*vec;
            *vec=aux;
            vec--;
            aux=aux2;
        }


}
