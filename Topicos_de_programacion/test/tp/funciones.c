#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 4000
#define CDH 8
#define PCS 1604

int valores_medios_voltaje()
{
    char telemetria[4000]; //ya que la variables tiene un tamaño de un byte,
                            //entonces la cadena de 4000 bytes tendra toda la informacion
                            // y sera mas facil desplazarse.
    int raw;
    float voltaje;
    char fecha_hora[4]; //4 bytes es el tamaño de la informacion (no se)

    FILE*pfvoltaje;
    FILE*pfinfromacion;

    pfvoltaje= fopen("HKTMST","rb");

    if(!pfvoltaje)
    {
        printf("\nNo se pudo abrir el archivo  HKTMST \n");
        return 0;
    }

    pfinfromacion= fopen("informacion","wb");

    if(!pfinfromacion)
    {
        printf("\nNo se pudo abrir el archivo de texto\n");
        return 0;
    }


    fread(telemetria,sizeof(telemetria),1,pfvoltaje);

    while(!feof(pfvoltaje))
    {
        raw=((int)telemetria+PCS+749); //me desplazo por la cadena. le pude 749 porque se pasaria(?
        voltaje= (float)(raw*0.01873128+(-38.682956)); //valor del voltaje.

        //fecha_hora=, aca iria el valor del OBT, para ´poder guardarlo en el archivo de texto, para el excel.
        //se puede haceruna funcion aparte(?
        // yo pense en dos opciones en como esta la infomacion en el registro.
        // tiene un tamaño de 4 bytes desde el princio (8 bytes) o desde el byte 4 (8+4) empieza la infomacion.

        if((voltaje<34 && voltaje>32) || (voltaje<=32 && voltaje>31.5))
        {
            //se guarda en el archivo de texto, porque es un valor de voltaje valido

            fprintf(pfinfromacion,"%f|%s|\n",&voltaje,fecha_hora);


            fread(telemetria,sizeof(telemetria),1,pfvoltaje);
        }



    }

    fclose (pfvoltaje);
    fclose (pfinfromacion);

    return  1;


}


int verificacion_archivo()
{
    char telemetria[4000];
    int acum;

    FILE*pfvoltaje;

    pfvoltaje= fopen("HKTMST.bin","rb");

    if(!pfvoltaje)
    {
        printf("\nNo se pudo abrir el archivo  HKTMST \n");
        return 0;
    }

    fread(telemetria,sizeof(telemetria),1,pfvoltaje);

    while(!feof(pfvoltaje))
    {
        acum = strlen(telemetria)+1; //se le suma el uno (1) porque la funcion no toma en cuenta el valor de uno.
    }

    if((acum%4000)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}




