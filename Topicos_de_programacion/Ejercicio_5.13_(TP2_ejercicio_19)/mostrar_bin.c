#include "header.h"

void mostrar_bin(char* nom)
{
    FILE *pf;
    int reg;

    pf=fopen(nom,"rb");

    if(pf==NULL)
        return;

    fread(&reg,sizeof(int),1,pf);

    while(!feof(pf))
    {
        printf("%d ",reg);
        fread(&reg,sizeof(int),1,pf);
    }
}
