#include "header.h"

int inverso_modular(int decim, int mod)
{
    int num=-1, aux;

    while(num<mod && aux!=-1)
    {
        num++;

        aux=decim*num;

        while(aux>mod)
        {
            aux-=mod;
        }

        if(aux==1)
            aux=-1;
    }

    return num;
}
