#include "header.h"

void actualizar_alumnos(void*reg1, void*reg2)
{
    t_alumno *alu1=reg1, *alu2=reg2;

    strcpy(alu1->apellido,alu2->apellido);
    strcpy(alu1->nombre,alu2->nombre);
    alu1->dni=alu2->dni;
    alu1->novedad=alu2->novedad;
}
