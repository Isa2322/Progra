#include "header.h"

void carga_vector_int(FILE *punt_txt, void *vec)
{
    int i, pos, elem;
    int *ref=vec;

    fscanf(punt_txt,"%d",&pos);

    while(!feof(punt_txt))
    {

        for(i=1; i<=pos; i++)
        {
            ref+=sizeof(int);
        }
        fgetc(punt_txt);
        fscanf(punt_txt,"%d",&elem);
        memcpy(ref,&elem,sizeof(int));
    }
}
