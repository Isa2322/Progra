#include "header.h"

void mostrar_txt(char* nom)
{
    FILE *pf;
    int num;

    pf=fopen(nom,"rt");

    if(pf==NULL)
        return;

    fscanf(pf,"%d",&num);

    while(!feof(pf))
    {
        printf("%d ",num);
        fscanf(pf,"%d",&num);
    }
}
