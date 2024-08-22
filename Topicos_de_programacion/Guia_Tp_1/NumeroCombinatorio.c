#include "factorial.h"
#include <stdio.h>

int NumeroCombinatorio(int num1, int num2)
{
    int numc;
    double num1f, num2f, aux;

    if(num1>num2)
        printf("Error el numero %d no es mayor o igual que %d",num2,num1);

    num1f=factorial(num1);
    num2f=factorial(num2);
    aux=factorial(num2-num1);
    aux*=num1f;
    numc=(int)num2f/aux;

    return numc;

}
