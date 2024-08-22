#include<stdio.h>

void buscar_en_fibonacci(int par)
{
    int num=1, num1=1, flag=0;

    do
    {
        if(par==num)
            flag=1;

        num1+=num;

        if(par==num1)
            flag=1;

        num+=num1;
    } while(flag==0 && num<par && num1<par);

    if(flag==1)
        printf("El numero %d SI  pertenece al la serie de Fibonacci",par);
    else
        printf("El numero %d NO  pertenece al la serie de Fibonacci",par);
}
