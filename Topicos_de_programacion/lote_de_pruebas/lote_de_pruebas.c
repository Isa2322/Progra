#include "header.h"

void lote_de_pruebas()
{
    FILE *pf;
    int i;
    t_fecha vec[5]={
        {05,06,2001},
        {10,06,2002},
        {15,06,2003},
        {20,06,2004},
        {25,06,2005}};
    t_fecha *aux;


        pf=fopen("fechas.dat","wb");
        if(pf==NULL)
            return;

        aux=vec;

        for(i=0;i<5;i++)
        {
            fwrite(aux,sizeof(t_fecha),1,pf);
            aux++;
        }

        fclose(pf);

        pf=fopen("fechas.dat","rb");

        mostrar_arch(pf);

        fclose(pf);


}
