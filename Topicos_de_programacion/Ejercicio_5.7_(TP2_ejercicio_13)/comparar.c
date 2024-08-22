#include "header.h"

int comparar(void* alumno, void* empleado)
{
    int cmp;
    t_empleados *emp=empleado;
    t_alumnos *alu=alumno;

    cmp=strcmp(alu->apellido,emp->apellido);

    if(!cmp)
        return cmp;

    cmp=strcmp(alu->nombre,emp->nombre);

    if(!cmp)
        return cmp;

    return (alu->dni - emp->dni);

    //return cmp;
}
