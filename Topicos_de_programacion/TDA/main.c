#include "header.h"

int main()
{
    t_vector vec;

    vec=crear_vector(10,sizeof(int));

    cargar_vector(&vec,tipo_int);

    return 0;
}
