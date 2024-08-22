#include "header.h"

void leer_stock(void*punt)
{
    t_stock *stock=(t_stock*)punt;
    printf("\n%d \t %s \t %d",stock->cod_art, stock->desc, stock->stock);
}

