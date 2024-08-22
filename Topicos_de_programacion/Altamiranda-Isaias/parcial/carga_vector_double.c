#include "header.h"

void carga_vector_double(FILE *punt_txt, void *vec)
{
    int i, pos;
    double elem;
    int *ref=vec;

    fscanf(punt_txt,"%d",&pos);

    while(punt_txt!='\0' || !feof(punt_txt))
    {

        for(i=1; i<=pos; i++)
        {
            ref+=sizeof(double);
        }

        fgetc(punt_txt);
        fscanf(punt_txt,"%lf",&elem);
        memcpy(ref,&elem,sizeof(double));

        ref=vec;
    }
}
