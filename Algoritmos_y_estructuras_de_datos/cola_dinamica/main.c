#include "header_cola_dinamica.h"

int main()
{
    t_cola cola;

    crear_cola(&cola);

    if(cola_vacia(&cola))
    {
        puts("La cola esta vacia");
    }

    return 0;
}
