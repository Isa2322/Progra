#include "header.h"

void modificar_archivo(FILE *pf, int tam_tipo, int modificar( void *))
{
    void *reg;

    reg=malloc(tam_tipo);

    if(!reg)
        return;

    fread(reg,tam_tipo,1,pf);

    while(!feof(pf))
    {
        if(modificar(reg)==1)
        {
            fseek(pf,-1L *tam_tipo,SEEK_CUR);
            fwrite(reg,tam_tipo,1,pf);
            fseek(pf,0L,SEEK_CUR);
        }

        fread(reg,tam_tipo,1,pf);
    }

    free(reg);
}
