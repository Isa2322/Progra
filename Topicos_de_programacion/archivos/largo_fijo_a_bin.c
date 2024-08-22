#include "header.h"

void largo_fijo_a_bin(char *linea, t_campeones *registro)
{
    char *aux;

    aux=strchr(linea,'\n');

    if(aux==NULL)
        exit(1);

    *aux='\0';

    aux-=2;

    sscanf(aux,"%d",&registro->num);

    aux--;

    *aux='\0';

    aux-=20;

    strcpy(registro->apellido, aux);

    aux--;
    *aux='\0';

    strcpy(registro->nombre, linea);
}
