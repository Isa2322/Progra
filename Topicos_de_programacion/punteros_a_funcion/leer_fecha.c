#include "header.h"

void leer_fecha(void*punt)
{
    t_fecha *fecha=(t_fecha*)punt;
    printf("\n%d - %d - %d",fecha->dia, fecha->mes, fecha->anio);
}

