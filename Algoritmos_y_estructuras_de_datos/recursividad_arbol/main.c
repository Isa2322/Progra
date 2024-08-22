#include "header_arbol.h"

int main()
{
    t_arbol arbol;

    int vec[]={10,25,50,60,75,100,110,125,150,175,200};

    crear_arbol(&arbol);

    cargar_arbol_desde_orden(&arbol,vec,sizeof(vec)/sizeof(int), _carga_enteros);

    printf("%d",altura_arbol(&arbol));

}
