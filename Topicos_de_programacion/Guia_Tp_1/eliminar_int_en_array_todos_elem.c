#include<stdio.h>
#include<stdlib.h>

void eliminar_int_en_array_todos_elem(int*vec, int ce, int tam, int elem)
{
    int aux=0, aux2, i=0, pos=1, *guia=vec;



    if(tam<ce)
    {
        printf("La cantidad de elementos es mayor que el tamaño del array");
        exit (1);
    }


    while(pos!=-1)
    {
        pos=-1;
        aux=0;
        vec=guia;
        i=0;

        while(i<ce-1)
        {
            vec++;
            i++;

            if(*vec==elem)
                pos=i;
        }

        if(pos!=-1)
            for(i;i>=pos;i--)
            {

                aux2=*vec;
                *vec=aux;
                vec--;
                aux=aux2;

            }
    }



}
