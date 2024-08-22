#include "header.h"

void bin_a_txt()
{
    char cad[3];
    int num;
    FILE *pf, *pft;

    pf=fopen("archal1.dat","rb");
    pft=fopen("archal1.txt","wt");

    if(pf==NULL || pft==NULL)
    {
        fclose(pf);
        fclose(pft);
        return;
    }

    fread(&num,sizeof(int),1,pf);
    sscanf(cad,"%d",&num);
    fwrite(cad,sizeof(cad),1,pft);
    while(!feof(pf))
    {
        sscanf(cad," %d",&num);
        fwrite(cad,sizeof(cad),1,pft);
        fread(&num,sizeof(int),1,pf);
    }

    fclose(pf);
    fclose(pft);

    ///////////////////////////////////////

    pf=fopen("archal2.dat","rb");
    pft=fopen("archal2.txt","wt");

    if(pf==NULL || pft==NULL)
    {
        fclose(pf);
        fclose(pft);
        return;
    }

    fread(&num,sizeof(int),1,pf);
    sscanf(cad,"%d",&num);
    fwrite(cad,sizeof(cad),1,pft);
    while(!feof(pf))
    {
        sscanf(cad," %d",&num);
        fwrite(cad,sizeof(cad),1,pft);
        fread(&num,sizeof(int),1,pf);
    }

    fclose(pf);
    fclose(pft);


    ///////////////////////////////////////

    pf=fopen("archal3.dat","rb");
    pft=fopen("archal3.txt","wt");

    if(pf==NULL || pft==NULL)
    {
        fclose(pf);
        fclose(pft);
        return;
    }

    fread(&num,sizeof(int),1,pf);
    sscanf(cad,"%d",&num);
    fwrite(cad,sizeof(cad),1,pft);
    while(!feof(pf))
    {
        sscanf(cad," %d",&num);
        fwrite(cad,sizeof(cad),1,pft);
        fread(&num,sizeof(int),1,pf);
    }

    fclose(pf);
    fclose(pft);


}
