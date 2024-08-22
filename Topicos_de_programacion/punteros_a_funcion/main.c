#include "header.h"

int main()
{
    /*float vec_f[10]={7.5,6.6,1.2,9.9,4.4,3.2,2.1,8.3,0.01,5.02};
    float vec_f2[10]={7.5,6.6,1.2,9.9,4.4,3.2,2.1,8.3,0.01,5.02};

    int vec_i2[10]={1,2,3,4,5,6,7,8,9,0};
    *char vec_c[10]={'a','s','d','f','g','h','j','k','l','i'};
    char string[50]="Argentina campeon del mundo";
    char string2[50]="Argentina campeon del mundo";
    int matriz[5][5]={{11,12,13,14,15},{21,22,23,24,25},{31,32,33,34,35},{41,42,43,44,45},{51,52,53,54,55}};
    int matriz2[5][5]={{11,12,13,14,15},{21,22,23,24,25},{31,32,33,34,35},{41,42,43,44,45},{51,52,53,54,55}};
    int i;*/
    //int vec_i[10]={7,6,1,9,4,3,5,0,8,2};


    FILE *pf;

    t_fecha *fecha;


    int i;
    t_fecha *aux;
    t_fecha vec[5]={
        {05,06,2001},
        {10,06,2002},
        {15,06,2003},
        {20,06,2004},
        {25,06,2005}};

    aux=vec;

    pf=fopen("FECHAS.DAT","wb");

    if(pf==NULL)
        return 1;

    for(i=0;i<5;i++)
    {
        fwrite(aux,sizeof(t_fecha),1,pf);
        aux++;
    }
    fclose(pf);

    pf=fopen("FECHAS.DAT","rb");

    if(pf==NULL)
        return 1;

    leer_archivo_generico(pf,sizeof(t_fecha),(void*)fecha,leer_fecha);

    fclose(pf);

   /* pf=fopen("FECHAS.DAT","r+");

    printf("\n\n");

    if(pf==NULL)
        return 1;
    modificar_archivo(pf,sizeof(t_fecha),(void*)fecha,cambiar_fecha);
    fclose(pf);

    pf=fopen("FECHAS.DAT","rb");

    if(pf==NULL)
        return 1;

    leer_archivo_generico(pf,sizeof(t_fecha),(void*)fecha,leer_fecha);

    fclose(pf);*/


    return 0;
}
