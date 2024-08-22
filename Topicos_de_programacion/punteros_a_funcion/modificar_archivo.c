#include "header.h"

void modificar_archivo(FILE *pf, int tam_tipo, void* tipo, int modificar( void *))
{
    void *reg;
    long dist=tam_tipo;

    reg=malloc(tam_tipo);

    if(!reg)
        return;

    reg=tipo;

    fread(reg,tam_tipo,1,pf);

    while(!feof(pf))
    {
        //leer_fecha(reg);

        if(modificar(reg)==1)
        {
            fseek(pf,-dist,SEEK_CUR);
            fwrite(reg,tam_tipo,1,pf);
            fseek(pf,0L,SEEK_CUR);
        }

        //leer_fecha(reg);

        fread(reg,tam_tipo,1,pf);
    }

    free(reg);
}
