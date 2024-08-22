#include "header.h"

int carga_archivo(int ce)
{
    int i;
    FILE*pf;
    t_fecha fechas;

    pf=fopen("pruebas.dat","wb");

    if(pf==NULL)
        return 1;

    for(i=0;i<ce;i++)
    {
        ingreso_de_datos(&fechas);

        fwrite(&fechas,sizeof(t_fecha),1,pf);
    }

    fclose(pf);

    return 0;
}
