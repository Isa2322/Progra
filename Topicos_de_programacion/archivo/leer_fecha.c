#include "header.h"

void leer_fecha( void**punt)
{
    t_fecha fechas;

    if(*punt==NULL)
        *punt=&fechas;
    else
    {
        fechas=*(t_fecha*)punt;
        printf("\n%d - %d - %d",fechas.dia, fechas.mes, fechas.anio);
    }

}

