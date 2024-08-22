#include "header_indice.h"
int main()
{
    t_productos producto;
    FILE *pf;
    t_arbol arbol;

    crear_arbol(&arbol);

    /*pf=fopen("productos.dat","rb");

    if(pf==NULL)
        return 1;

    while(!feof(pf))
    {
        fread(&producto, sizeof(t_productos), 1, pf);
        insertar_arbol(&arbol, &producto, sizeof(t_productos),comparar_nombre_productos);
    }
    fclose(pf);

    recorrer_en_orden_mod(&arbol, mostrar_arbol);


    crear_indice(&arbol);*/

    pf=fopen("productos.idx","rb");

    if(!pf)
        return 1;

    while(!feof(pf))
    {
        fread(&producto, sizeof(t_productos), 1, pf);
        printf("%s\n%s\n%d\n%.2fn\n\n\n",producto.nombre, producto.descripcion, producto.n_serie, producto.precio);
    }

    fclose(pf);

    return 0;
}
