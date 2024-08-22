#include<stdio.h>

void es_primo(int num)
{
    int cont=0, i;
    float aux;

    for(i=1; i<num;i++)
    {
        aux=num%i;

        if(aux==0)
            cont++;
    }

    if(cont==1)
        printf("El numero %d es primo",num);
    else
        printf("El numero %d NO es primo",num);
}
