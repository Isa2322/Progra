#include "header.h"

void mostrar_arch(FILE *pf)
{
    t_fecha fecha;

    fread(&fecha,sizeof(t_fecha),1,pf);

    while(feof(pf)==0)
    {
        printf("dia: %d  mes: %d  anio: %d \n",fecha.dia, fecha.mes, fecha.anio);
        fread(&fecha,sizeof(t_fecha),1,pf);
    }
}

