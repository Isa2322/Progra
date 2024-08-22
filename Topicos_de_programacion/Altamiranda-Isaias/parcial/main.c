#include "header.h"

int main()
{
    FILE *pf1, *pf2;
    void *vec1, *vec2;
    char op;
    int *tam, *dim;

    tam=malloc(sizeof(int));
    dim=malloc(sizeof(int));

    pf1=fopen("arch1.txt","rt");
    pf2=fopen("arch2.txt","rt");

    if(pf1==NULL || pf2==NULL)
        return 1;

    op=leer_txt(pf1,pf2,tam,dim);

    vec1=calloc(*tam,*dim);
    vec2=calloc(*tam,*dim);

    carga_vector_int(pf1,vec1);
    carga_vector_int(pf2,vec2);//creo que cargue los elementos en la variable auxiliar en lugar del vector

    suma_y_resta(vec1,vec2,op,10,operar_int);

    fclose(pf1);
    fclose(pf2);

    free(vec1);
    free(vec2);
    return 0;
}
