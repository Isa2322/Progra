#include "header.h"

char carga_vec(FILE *pf1, FILE *pf2, void **vec, int *tipo, int* tam)
{
    int dim1, dim2, tam1_tipo, tam2_tipo;
    char op1, op2;
    char aux[10];
    long inic;

    fscanf(pf1,"(%d)\n",&dim1);
    fscanf(pf2,"(%d)\n",&dim2);

    op1=fgetc(pf1);
    op2=fgetc(pf2);

    if(op1!=op2)
        return '0';

    fscanf(pf1,"%d\n",&tam1_tipo);
    fscanf(pf2,"%d\n",&tam2_tipo);

    if(tam1_tipo!=tam2_tipo)
        return '0';

    if(dim1>=dim2)
    {
        vec[0]=calloc(tam1_tipo,dim1);
        vec[1]=calloc(tam1_tipo,dim1);
        *tam=dim1;
    }
    else
    {
        vec[0]=calloc(tam2_tipo,dim2);
        vec[1]=calloc(tam2_tipo,dim2);
        *tam=dim2;
    }

    inic=ftell(pf1);

    fgets(aux,10,pf1);

    fseek(pf1,inic,SEEK_SET);

    if(tam1_tipo==sizeof(double))
    {
        carga_double(vec,pf1,pf2);
        *tipo=3;
    }
    else
    {
        if(strchr(aux,'.')==NULL)
        {
            carga_int(vec,pf1,pf2);
            *tipo=1;
        }
        else
        {
            carga_float(vec,pf1,pf2);
            *tipo=2;
        }
    }




    return op1;
}
