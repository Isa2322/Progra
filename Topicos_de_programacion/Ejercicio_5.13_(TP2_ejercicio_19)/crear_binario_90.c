#include "header.h"

void crear_binario_90()
{
    int num,i;
    FILE *pf;

    pf=fopen("archalea.dat","wb");

    if(pf==NULL)
        return;

    for(i=0; i<90; i++)
    {
        num=rand() % 900+100;
        fwrite(&num,sizeof(int),1,pf);
    }

    dividir_binario(pf);

    fclose(pf);
}
