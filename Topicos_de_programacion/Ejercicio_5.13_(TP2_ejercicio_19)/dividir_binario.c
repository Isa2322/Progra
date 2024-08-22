#include "header.h"

void dividir_binario(FILE* pf)
{
    FILE *pf1, *pf2, *pf3;

    int num, i;

    rewind(pf);
    fread(&num,sizeof(int),1,pf);

    pf1=fopen("archal1.dat","wb");
    if(pf1==NULL)
        return;

    for(i=0; i<30; i++)
    {
        fwrite(&num,sizeof(int),1,pf1);
        fread(&num,sizeof(int),1,pf);
    }

    fclose(pf1);


    pf2=fopen("archal2.dat","wb");
    if(pf2==NULL)
        return;

    for(i=0; i<30; i++)
    {
        fwrite(&num,sizeof(int),1,pf2);
        fread(&num,sizeof(int),1,pf);
    }

    fclose(pf2);


    pf3=fopen("archal3.dat","wb");
    if(pf3==NULL)
        return;

    for(i=0; i<30; i++)
    {
        fwrite(&num,sizeof(int),1,pf3);
        fread(&num,sizeof(int),1,pf);
    }

    fclose(pf3);
}
