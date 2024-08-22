#include "header.h"

void largo_variable_a_bin(char *linea, t_campeones *registro)
{
    char *aux;

    aux=strchr(linea, '|');

    if(aux==NULL)
        exit(1);

    *aux='\0';

    strcpy(registro->nombre,linea);

    aux++;
    linea=aux;

    aux=strchr(linea, '|');

    if(aux==NULL)
        exit(1);

    *aux='\0';

    strcpy(registro->apellido,linea);

    aux++;
    linea=aux;

    aux=strchr(linea, '\n');

    if(aux==NULL)
        exit(1);

    *aux='\0';

    sscanf(linea,"%d",&registro->num);

}
