#include "header.h"

int modificar_stock(void* reg)
{
    t_stock *registro=reg;

    if((registro->stock)<200)
    {
        registro->stock=200;
        reg=registro;
        return 1;
    }

    return 0;

}
