#include <stdio.h>


void clasificacion(int num)
{
    int i, cont=0;

    for(i=1;i<=(num/2);i++)
    {
        if(num%i==0)
            cont+=i;
    }

    if(cont==num)
        printf("El numero %d es PERFECTO",num);
    else
        if(cont<num)
            printf("El numero %d es DEFICIENTE",num);
        else
            printf("El numero %d es ABUNDANTE",num);
}
