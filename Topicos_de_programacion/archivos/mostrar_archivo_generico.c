#include "header.h"

void mostrar_archivo_generico(FILE *pf, int tam_tipo, void* tipo, void mostrar( void *))
{
    void *reg=malloc(tam_tipo);

    if(!reg)
        return;

    reg=tipo;

    fread(reg,tam_tipo,1,pf);

    while(!feof(pf))
    {
        mostrar(reg);
        fread(reg,tam_tipo,1,pf);
    }
    free(reg);
}
