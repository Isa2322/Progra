#include "header.h"

void carga_vector_float(FILE *punt_txt, void *vec)
{
    int i, pos;
    float elem;
    int *ref=vec;

    fscanf(punt_txt,"%d",&pos);

    while(punt_txt!='\0' || !feof(punt_txt))
    {

        for(i=1; i<=pos; i++)
        {
            ref+=sizeof(float);
        }
        fgetc(punt_txt);
        fscanf(punt_txt,"%f",&elem);
        memcpy(ref,&elem,sizeof(float));

        ref=vec;
    }
}
