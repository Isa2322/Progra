#include "header.h"

int son_coprimos(int num1, int num2)
{
    float aux=0;
    int i=1;

    while(i<num1 && i<num2 && aux!=-1)
    {
        aux=num1%i;

        if(aux==0 && i!=1)
        {
            aux=num2%i;

            if(aux==0)
                aux=-1;
        }
        i++;
    }

    if(aux==-1)
        return 0;
    else
        return 1;
}
