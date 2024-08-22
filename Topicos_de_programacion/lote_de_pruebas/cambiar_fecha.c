#include "header.h"

void cambiar_fecha()
{
    FILE*pf;
    t_fecha fecha;
    int cont=0;

    pf=fopen("fechas.dat","r+");

    fread(&fecha,sizeof(t_fecha),1,pf);
    fseek(pf,0L,SEEK_SET);

    while(feof(pf)==0)
    {
        fread(&fecha,sizeof(t_fecha),1,pf);
        cont++;

        if(fecha.mes==06)
        {
            fecha.mes=12;
            fseek(pf,sizeof(t_fecha)*(cont-1),SEEK_SET);
            fwrite(&fecha,sizeof(t_fecha),1,pf);
            fseek(pf,0L,SEEK_SET);
            //rewind(pf);
        }
    }

    fclose(pf);

    pf=fopen("fechas.dat","rb");


    printf("\n\n");
    mostrar_arch(pf);

    fclose(pf);
}
