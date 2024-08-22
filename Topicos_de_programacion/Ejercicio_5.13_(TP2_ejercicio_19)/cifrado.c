#include "header.h"

void cifrado()
{
    FILE *pft, *pftc;
    char cad[3], num;

    pft=fopen("archal1.txt","rt");
    pftc=fopen("archtex1.txt","wt");

    if(pft==NULL || pftc==NULL)
    {
        fclose(pft);
        fclose(pftc);
        return;
    }

    num=fgetc(pft);

    while(num!='\0' && num!='\n' && !feof(pft))
    {
        if(num!=' ')
        {
            num+=17;
            fprintf(pftc,"%c",num);
        }

        num=fgetc(pft);
    }

    fclose(pft);
    fclose(pftc);

    ///////////////////////////////////////////////

    pft=fopen("archal2.txt","rt");
    pftc=fopen("archtex2.txt","wt");

    if(pft==NULL || pftc==NULL)
    {
        fclose(pft);
        fclose(pftc);
        return;
    }

    num=fgetc(pft);

    while(num!='\0' && num!='\n' && !feof(pft))
    {
        if(num!=' ')
        {
            num+=27;
            fprintf(pftc,"%c",num);
        }

        num=fgetc(pft);
    }

    fclose(pft);
    fclose(pftc);

    ///////////////////////////////////////////

    pft=fopen("archal3.txt","rt");
    pftc=fopen("archtex3.txt","wt");

    if(pft==NULL || pftc==NULL)
    {
        fclose(pft);
        fclose(pftc);
        return;
    }

    num=fgetc(pft);

    while(num!='\0' && num!='\n' && !feof(pft))
    {
        if(num!=' ')
        {
            num+=37;
            if(num>90)
                num-=25;
            fprintf(pftc,"%c",num);
        }

        num=fgetc(pft);
    }

    fclose(pft);
    fclose(pftc);
}
