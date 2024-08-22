#include "header.h"

int cambiar_fecha(void* reg)
{
    t_fecha*registro=reg;

    if((registro->mes)==06)
    {
        registro->mes=12;
        reg=registro;
        return 1;
    }

    return 0;

}
