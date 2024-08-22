#include "header.h"

void leer_fecha(void*punt)
{
    t_fecha *fecha=(t_fecha*)punt;
    printf("%d - %d - %d \n",fecha->dia, fecha->mes, fecha->anio);
}

