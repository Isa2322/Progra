#include "header.h"

int main()
{
    int cantLetras=0;
    char frase[]="   Argentina    campeon     del    mundo     ";
    char *pun;
    char *finp;
    char *pinvert;
    finp=frase;



    printf("%s",normalizar_string(invertir_frase(frase)));


    return 0;
}

