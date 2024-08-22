#include "header_lista.h"

int main()
{
    t_lista lista;

    crear_lista(&lista);

    lote(&lista);

    ordenar_lista_asc(&lista, cmp_dorsal);

    mostrar(&lista);

    vaciar_lista(&lista);
    return 0;
}
