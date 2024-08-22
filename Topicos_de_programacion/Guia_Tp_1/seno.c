#define VALOR_ABSOLUTO
#include "factorial.h"

float seno(int grad, float tol)
{
    int cont=3, signo=1;
    float sen=0, term;
    double fact=6, pot, rad;

    rad=(grad*3.14159265359)/180;
    term=rad;
    pot=rad*rad*rad;

    while(VALOR_ABSOLUTO(term)>tol)
    {
        if(signo==1)
            sen+=term;
        else
            sen-=term;

        pot*=rad;
        pot*=rad;
        cont++;
        fact*=cont;
        cont++;
        fact*=cont;

        term=pot/fact;
        signo*=-1;
    }

    return sen;
}
