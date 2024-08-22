#include "lista_doble_header.h"

int main()
{
    t_lista lista;

    int vec[9]={1,2,3,4,5,6,7};
    int i;

    crear_lista(&lista);

    for(i=0; i<7; i++)
    {
        insertar_en_orden(&lista, vec[i], sizeof(int),comparar_int(int* elem1, int* elem2));
    }

}
