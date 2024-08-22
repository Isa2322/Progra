#include "header.h"

int comparar_alumnos(void*reg1, void*reg2)
{
    int cmp;
    t_alumno *alu1=reg1, *alu2=reg2;

    if(alu2->novedad=='M')
        return 0;

    if(!(cmp=strcmp(alu1->apellido,alu2->apellido)))
       if(!(cmp=strcmp(alu1->nombre,alu2->nombre)))
          return (alu1->dni-alu2->dni);

    return cmp;
}
