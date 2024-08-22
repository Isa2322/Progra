#include "header.h"

void actualizar(void* alumno, void* empleado, float prom, float sueldo)
{
    t_alumnos *alu=alumno;
    t_empleados *emp=empleado;

    if(alu->promedios>prom)
        emp->sueldo*=sueldo;
}
