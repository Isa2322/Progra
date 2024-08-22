#include "header.h"

int leer_archivo()
{
    FILE*pf;
    t_fecha fechas;

    pf=fopen("pruebas.dat","rb");

    if(pf==NULL)
        return 1;

    fread(&fechas,sizeof(t_fecha),1,pf);

    while(feof(pf)==0)
    {
        printf("\n%d - %d - %d",fechas.dia, fechas.mes, fechas.anio);

        fread(&fechas,sizeof(t_fecha),1,pf);
    }

    fclose(pf);

    return 0;
}
