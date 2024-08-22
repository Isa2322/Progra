#include "header.h"

char leer_txt(FILE* punt_vec1, FILE* punt_vec2,int *tam, int* dim)
{
    int dim_vec1, dim_vec2, tam_tipo_vec1, tam_tipo_vec2;
    char op_vec1, op_vec2;

    fgetc(punt_vec1);
    fgetc(punt_vec2);

    fscanf(punt_vec1,"%d",&dim_vec1);
    fscanf(punt_vec2,"%d",&dim_vec2);

    fseek(punt_vec1,3,SEEK_CUR);
    fseek(punt_vec2,3,SEEK_CUR);

    op_vec1=fgetc(punt_vec1);
    op_vec2=fgetc(punt_vec2);

    if(op_vec1!=op_vec2)
        return 1;

    fscanf(punt_vec1,"%d",&tam_tipo_vec1);
    fscanf(punt_vec2,"%d",&tam_tipo_vec2);

    if(tam_tipo_vec1!=tam_tipo_vec2)
        return 1;

    if(dim_vec1<dim_vec2)
    {
        *tam=dim_vec2*tam_tipo_vec1;
        *dim=dim_vec2;
    }
    else
    {
        *tam=dim_vec1*tam_tipo_vec1;
        *dim=dim_vec1;
    }

    return op_vec1;
}
