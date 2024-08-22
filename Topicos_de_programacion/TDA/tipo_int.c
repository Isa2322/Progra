#include "header.h"

void tipo_int(t_vector* vec)
{
    int i, pos, valor, *punt;
    void* aux=vec->dir_inic;

    punt=vec->dir_inic;

    for(i=1;i<=vec->tam;i++,(int*)vec->dir_inic++)
    {
        printf("%2d %20d\n",i,*(int*)vec->dir_inic);
    }

    vec->dir_inic=aux;

    printf("\nIngrese la posicion: ");
    fflush(stdin);
    scanf("%d",&pos);

    if(pos==-1)
        return;

    printf("\nIngrese el valor nuevo en la posicion %d: ",pos);
    fflush(stdin);

    scanf("%d",&valor);

    for(i=0;i<pos;i++)
        punt++;

    vec->dir_inic=punt;
    *(int*)vec->dir_inic=valor;

    vec->dir_inic=aux;

    //*(int*)vec->dir_inic[pos]=valor;

}
