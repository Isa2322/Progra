#include "header.h"

void desencriptar_afin(FILE *texto, FILE *clave)
{
    int decimacion, desplazamiento, tam, inverso, pos=0, i;
    char *alfabeto, *frase, *aux, *inic;
    FILE *pf;

    fseek(clave,0L,SEEK_END);
    tam=ftell(clave);
    fseek(clave,0L,SEEK_SET);

    alfabeto=malloc(tam);

    if(alfabeto==NULL)
        return;

    fscanf(clave,"a=%d,b=%d\n%s",&decimacion,&desplazamiento,alfabeto);

    aux=alfabeto;

    fseek(texto,0L,SEEK_END);
    tam=ftell(texto);
    fseek(texto,0L,SEEK_SET);

    tam++;

    frase=malloc(tam);
    if(frase==NULL)
        return;

    fgets(frase,tam,texto);

    tam=strlen(alfabeto);

    if(!son_coprimos(decimacion,tam))
        return;

    inverso=inverso_modular(decimacion,tam);

    inic=frase;

    while(*frase!='\n' && *frase!='\0')
    {
        if(strchr(alfabeto,*frase)!=NULL)
        {
            while(*frase!=*aux)
            {
                pos++;
                aux++;
            }
            aux=alfabeto;
            pos-=desplazamiento;
            pos*=inverso;

            if(pos>=0)
            {
                while(pos>tam)
                {
                    pos-=tam;
                }
            }
            else
            {
                while(pos<0)
                {
                    pos+=tam;
                }
            }

            for(i=0;i<pos;i++)
            {
                aux++;
            }

            *frase=*aux;
        }

        aux=alfabeto;
        frase++;
        pos=0;
    }

    frase=invertir_frase(inic);

    pf=fopen("texto_desencriptado.txt","wt");

    if(pf==NULL)
        return;

    fprintf(pf,"%s",frase);

    fclose(pf);
}
