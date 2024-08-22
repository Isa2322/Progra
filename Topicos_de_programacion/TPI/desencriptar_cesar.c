#include "header.h"

void desencriptar_cesar(FILE *texto, FILE*clave, int long_texto, int long_alfa)
{
    int salto, i;
    char *alfabeto, *frase;
    char *letra, *inic;
    FILE *pf;

    long_texto++;

    alfabeto=malloc(long_alfa);
    frase=malloc(long_texto);

    fscanf(clave,"%d\n",&salto);

    fgets(alfabeto,long_alfa,clave);
    fgets(frase,long_texto,texto);

    alfabeto=invertir_frase(alfabeto);

    inic=frase;

    while(*frase!='\0')
    {
        letra=buscar_letra(alfabeto,*frase);

        if(letra!=NULL)
        {
            for(i=0;i<salto;i++)
            {
                letra++;

                if(*letra=='\n' || *letra=='\0')
                    letra=alfabeto;
            }

            *frase=*letra;
        }

        frase++;
    }

    frase=invertir_frase(inic);

    pf=fopen("texto_desencriptado.txt","wt");

    if(pf==NULL)
        return;

    fprintf(pf,"%s",frase);

}
