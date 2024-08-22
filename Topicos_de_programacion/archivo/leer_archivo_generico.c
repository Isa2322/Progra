#include "header.h"

int leer_archivo_generico(int tam_tipo, void mostrar( void **))
{
    FILE*pf;

    void *puntero;

    mostrar(&puntero);

    pf=fopen("pruebas.dat","rb");

    if(pf==NULL)
        return 1;

    fread(puntero,tam_tipo,1,pf);

    while(feof(pf)==0)
    {
        mostrar(puntero);
        fread(puntero,tam_tipo,1,pf);
    }

    fclose(pf);

    return 0;
}
